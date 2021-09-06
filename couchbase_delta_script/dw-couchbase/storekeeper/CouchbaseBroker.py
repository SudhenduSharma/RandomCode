#https://github.com/couchbaselabs/devguide-examples
import os
from couchbase.cluster import Cluster
from couchbase.bucketmanager import BucketManager
from couchbase.cluster import PasswordAuthenticator
from couchbase.bucket import Bucket
import CustomException as CE
import couchbase.exceptions as E
import json
from datetime import datetime
import re

class CouchbaseBroker():

   def __init__(self,opts):
     try:
       self.opts_dict = opts
       self.store_keeper_meta = ()
       connect_string = "//couchbase:"+opts['connect']+":8091"
       self.cb_cli_opts = "--cluster {} --username {} --password {} --bucket {} ".format(connect_string,opts['username'],opts['password'],opts['bucket_name'])
       print(self.cb_cli_opts)
       cbq_connect_str="http://" + opts['connect']+":8093"
       self.cb_cbq_opts = "--engine {} -u {} -p {} ".format(cbq_connect_str,opts['username'],opts['password'])
       print(self.cb_cbq_opts)
       self.cluster = Cluster("couchbase://"+opts['connect'])
       self.bucket  = None
     except :
         print("unable to connect {%s}" % (opts["connect"]))
         raise
         #raise  CE.InvalidArgType('Only supported for valid connect string ') #.format(opts["connect"]))
     try :
       print("authenticate using {} {} ".format(opts["username"], opts['password']))
       self.authenticator = PasswordAuthenticator(opts['username'],opts['password'])
       self.cluster.authenticate(self.authenticator)
     except :
       print("unable to authenticate {} {} ".format(opts["username"], opts['password']))
       raise

   def open_bucket(self,bucket_name) :
     try :
       self.bucket = self.cluster.open_bucket(bucket_name)
       return self.bucket
     except :
       print("unable to open bucket {%s}  " % (bucket_name))
       raise

   def wipeBucket(self,opts_dict) :
     #wipe all document from bucket
     cmd = "couchbase-cli bucket-flush " + self.cb_cli_opts
     print("running-->" + cmd)
     print("\n----\nEnter yes/no to flush bucket")
     output=os.popen(cmd).read().rstrip('\n')
     print(output)

   def listBuckets(self,opts_dict) :
     #wipe all document from bucket
     cmd = "couchbase-cli bucket-flush  --cluster {} --username {} --password {}".format(opts_dict['connect'],opts_dict['username'],opts_dict['password'])
     print(cmd)
     output=os.popen(cmd).read().rstrip('\n')
     print(output)

   def checkIfStoreKeeperMetaAvailable(self) :
     #TODO Remove this function
     #TODO introduce query comand generator
     query = " \"select count(*) from " + "''" + self.opts_dict['bucket_name'] + "'" +" USE KEYS 'StoreKeeperMeta::00001'\""
     cmd = "cbq -q " +  self.cb_cbq_opts + " -s" + query
     print(cmd)
     output=os.popen(cmd).read().rstrip('\n')

     try:
       output_json = json.loads(output)
       result=output_json['results'][0]['$1']

       if result == 0 :
         print("Create StoreKeeperMeta Doc")
         return False
       else:
         print("Fetch StoreKeeperMeta Doc")
         return True
       print(output_json['results'][0]['$1'])
     except:
        raise

   def createStoreKeeperMeta(self) :
     utc_time = str(datetime.utcnow())
     print(utc_time)
     self.store_keeper_meta = {
                        'name':'StoreKeeperMeta',
                        'createdOn': '',
                        'lastModifiedOn': '',
                        '_class':'com.mavenir.dep.bucket.metadata'
                      }
     self.store_keeper_meta['_class'] = "com.mavenir.dep."+ self.opts_dict['bucket_name'] + ".metadata"
     self.store_keeper_meta['createdOn'] = utc_time
     self.store_keeper_meta['lastModifiedOn'] = utc_time
     self.uploadStoreKeeperMetaInDB()

     #https://stackoverflow.com/questions/11875770/how-to-overcome-datetime-datetime-not-json-serializable
     #storekeeoer_json = json.dumps(self.store_keeper_meta,indent=4, sort_keys=True, default=str).replace('"','\\"')
   def uploadStoreKeeperMetaInDB(self) :
     try:
       print("Createing Initial DOC")
       self.store_keeper_meta = self.bucket.upsert('StoreKeeperMeta::00001',self.store_keeper_meta)
       print(self.store_keeper_meta)
     except E.KeyExistsError:
       print('Got exception for since doc already exists !')
       raise

     ##TODO introduce query comand generator
     #query= " \"UPSERT INTO {} (KEY _k, VALUE _v) SELECT '{}' AS _k, {} AS _v \"".format(self.opts_dict['bucket_name'] ,"'StoreKeeperMeta::00001'",storekeeoer_json)
     #cmd = "cbq -q " +  self.cb_cbq_opts + " -s" + query
     #print("Executing ->", cmd)
     #output=os.popen(cmd).read().rstrip('\n')
     #print(output)
     #self.store_keeper_meta = storekeeoer_json


   def fetchStoreKeeperMeta(self) :
     #query = " \"select a.* from accdet a USE KEYS 'StoreKeeperMeta::00001'\""
     #cmd = "cbq -q " +  self.cb_cbq_opts + " -s" + query
     #print(cmd)
     #output=os.popen(cmd).read().rstrip('\n')
     #print(output)
     try:
       self.store_keeper_meta = self.bucket.get('StoreKeeperMeta::00001').value
       print(self.store_keeper_meta)
       return True
     except E.NotFoundError:
       print('Got exception for missing document!')
       print('...')
       return False


   def executeCreatesIfNeeded(self) :
     #FIXME TODO
     print("TODO BUCKET CREATION NEEDS TO BE IMPLEMENTED")
     if False == self.fetchStoreKeeperMeta() :
       #Create StoreKeeperMeta Doc
       print("Creating StoreKeeperMeta Doc")
       self.createStoreKeeperMeta()
     else :
       #Fetch StoreKeeperMeta Doc
       print("Fetched StoreKeeperMeta Doc")

   def executeDeltasIfNeeded(self,db_script_runner) :
     if 'deltas' in self.store_keeper_meta.keys() and len(self.store_keeper_meta['deltas']) > 0:
       #find max version of delta script already applied on bucket
       version_int = int(max(self.store_keeper_meta['deltas'],key=lambda x:int(x.get('version'))).get('version'))
       print("Max Delta in Couchbase->",version_int)
       self.applyDeltas(db_script_runner,version_int)
     else :
       self.initalSetup(db_script_runner)
    #there are deltas applied already, so find maximum version applied and continue onwards

   def  applyDeltas(self,db_script_runner,version_int) :
     try:
       delta_scripts_to_apply = db_script_runner.findDeltasGreaterThan(version_int)
       print('deltas to be applied --> ')
       print(delta_scripts_to_apply)
       print('please confirm')
       #TODO code for user inputs
       for db_script in delta_scripts_to_apply:
         print(db_script)
         self.applyDbScript(db_script)
     except KeyError:
       raise
     except :
       raise

   def applyDbScript(self,db_script) :
     print("applying Script -->" , db_script)
     cmd = "cbq -q " +  self.cb_cbq_opts + " -f " +  db_script.file_path
     print(cmd)
     output=os.popen(cmd).read().rstrip('\n')
     #TODO check for succcess failure
     print(output)
     self.updateStoreKeeperMeta(db_script)

   def updateStoreKeeperMeta(self,db_script) :
     #TODO assert if delta is already in store_keeper_meta

     if 'deltas' not in self.store_keeper_meta:
       self.store_keeper_meta['deltas'] = []

     self.store_keeper_meta['deltas'].append(db_script.toJson())
     print(self.store_keeper_meta)

     self.uploadStoreKeeperMetaInDB()

   def  initalSetup(self,db_script_runner) :
     print("apply the create-1 and all deltas > version 1 in sequence")
     db_script = db_script_runner.findCreateScriptsEqualTo(1)
     if  len(db_script) == 1:
       self.applyDbScript(db_script[0])
     else :
       print("DB script with create version 1 count == {}  !! something is wrong please check", len(db_script))
       return

     #TODO
     return
     self.applyDeltas(db_script_runner,1)



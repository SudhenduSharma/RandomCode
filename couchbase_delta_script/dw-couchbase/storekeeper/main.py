import sys , getopt, os

from couchbase.cluster import Cluster
from couchbase.cluster import PasswordAuthenticator
from couchbase.n1ql import N1QLQuery
from BucketIndexManager import BucketIndexManager
from CouchbaseBroker import CouchbaseBroker
import CustomException
from DbScriptsRunner import DbScriptsRunner


#rv = cb.get('airline_24')
#print(rv)

#query = N1QLQuery("""SELECT airportname, city, country FROM `travel-sample` """
#                  """WHERE type="airport" AND city=$my_city""", my_city="Reno")
#for row in cb.n1ql_query(query):
#    print("---row --")
#    print(row)
def parse(opts,args):
  opts_dict = {
      "connect"  : "10.1.20.86",
      "username" : "aquto",
      "password" : "aqut0r0cks",
      "bucket_name" : "travel-sample",
      "directory" : "../nosql/",
      "wipe" : "false"
  }

  for opt, arg in opts:
      if opt == '-h':
         print (usage)
         sys.exit()
      elif opt in ("-c", "--connect"):
         opts_dict["connect"] = arg
      elif opt in ("-u", "--uername"):
         opts_dict["username"] = arg
      elif opt in ("-p", "--password"):
         opts_dict["password"]= arg
      elif opt in ("-b", "--bucket_name"):
         opts_dict["bucket_name"] = arg
      elif opt in ("-d", "--directory"):
         opts_dict["directory"] = arg
      elif opt in ("-w", "--wipe"):
         opts_dict["wipe"] = arg

  return opts_dict


if __name__ == '__main__':

  argv = sys.argv[1:]
  usage=" python main.py  -c 10.1.20.86 -u aquto -p aqut0r0cks -b accdet  -w  false \n main.py --connect <10.1.20.86> --username <username> --password <password> --bucket_name <bucket_name> -w  <false>"

  try:
      opts, args = getopt.getopt(argv,"hc:u:p:b:d:w:",["connect=","username=","password","bucket_name","directory","wipe"])
  except getopt.GetoptError:
     print (usage)
     sys.exit(2)
  except :
     print (usage)
     sys.exit(1)

  opts_dict = parse(opts, args)
  print(opts_dict)

 # store_keeper_meta = {u'deltas': [{u'applyDate': u'2013-04-27 12:38:18', u'version': u'1', u'deltaFileName': u'create1.sql'}, {u'applyDate': u'2018-04-27 12:38:18', u'version': u'1', u'deltaFileName': u'delta1.sql'}, {u'applyDate': u'2019-04-27 12:38:18', u'version': u'2', u'deltaFileName': u'delta2.sql'}], u'lastModifiedOn': u'2013-04-27 12:38:18', u'createdOn': u'2013-04-27 12:38:18', u'_class': u'com.mavenir.dep.accdet.metadata', u'name': u'StoreKeeperMet'}

 # #print(store_keeper_meta)
 # #print(store_keeper_meta['deltas'])

 # store_keeper_meta_dict = {u'deltas': [{u'applyDate': u'2013-04-27 12:38:18', u'version': u'1', u'deltaFileName': u'create1.sql'}, {u'applyDate': u'2018-04-27 12:38:18', u'version': u'1', u'deltaFileName': u'delta1.sql'}, {u'applyDate': u'2019-04-27 12:38:18', u'version': u'2', u'deltaFileName': u'delta2.sql'}], u'lastModifiedOn': u'2013-04-27 12:38:18', u'createdOn': u'2013-04-27 12:38:18', u'_class': u'com.mavenir.dep.accdet.metadata', u'name': u'StoreKeeperMet'}
 # print(store_keeper_meta_dict['deltas'])
 # item = max(store_keeper_meta_dict['deltas'],key=lambda x:x.get('version'))
 # print(item)


 # exit()
  db_broker = CouchbaseBroker(opts_dict)
  bucket = db_broker.open_bucket(opts_dict['bucket_name'])
  #index_mgr = BucketIndexManager(bucket)

  db_scripts_runner = DbScriptsRunner(opts_dict)

  if opts_dict['wipe'] == 'true' :
    print("wiping bucket",opts_dict["bucket_name"])
    db_broker.wipeBucket(opts_dict)

  db_broker.executeCreatesIfNeeded()
  db_broker.executeDeltasIfNeeded(db_scripts_runner)



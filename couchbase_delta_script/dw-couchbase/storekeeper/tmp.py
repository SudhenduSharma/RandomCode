from datetime import datetime
class DbScript():

    def __init__(self, name_str, version_int,file_path_str):
      try :
        self.name = name_str
        self.version = version_int
        self.file_path = file_path_str
      except :
        print("unable to authenticate {%s} {%s} " % (opts["usename"], opts['[password']))
        raise  CE.InvalidArgType('Only supported for valid auth credendials ') #.format(opts["connect"]))
    def __str__(self):
        return str(self.__class__) + ": " + str(self.__dict__)
    def toJson(self):
        json_str = "{" + "'deltaFileName': '{}','version':'{}','applyDate':'{}'".format(str(datetime.utcnow()),self.version,self.name) + "}"
        db_script = dict()
        db_script['deltaFileName'] = str(datetime.utcnow())
        db_script['version'] = self.version
        db_script['name'] = self.name
        return db_script


x = DbScript("create.1.nosql",1,"/root/create.1.nosql")

print(x.toJson())

utc_time = str(datetime.utcnow())
print(utc_time)
store_keeper_meta = {
              'name':'StoreKeeperMeta',
              'createdOn': '',
              'lastModifiedOn': '',
              '_class':'com.mavenir.dep.bucket.metadata'
            }
store_keeper_meta['_class'] = "com.mavenir.dep."+ 'bucket_name' + ".metadata"
store_keeper_meta['createdOn'] = utc_time
store_keeper_meta['lastModifiedOn'] = utc_time
store_keeper_meta['deltas'] = []
print( store_keeper_meta['deltas'])
store_keeper_meta['deltas'].append(x)
print( str(store_keeper_meta))



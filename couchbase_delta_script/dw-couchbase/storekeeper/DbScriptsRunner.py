import CustomException as CE
import couchbase.exceptions as E
import operator
from datetime import datetime
import re
import os

#/**
# * Represents a single db script that needs to be run.  Can be a create or delta script
# */

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
       #json_str = "{" + "'deltaFileName': '{}','version':'{}','applyDate':'{}'".format(str(datetime.utcnow()),self.version,self.name) + "}"
       db_script = dict()
       db_script['appliedOn'] = str(datetime.utcnow())
       db_script['version'] = self.version
       db_script['deltaFileName'] = self.name
       return db_script
class DbScriptsRunner():
   def __init__(self, opts_dict):
     self.creates = []
     self.deltas  = []
     path=''
     try:
       path = opts_dict['directory']
       print(path)
       is_dir = os.path.isdir(path)
     except :
         raise  ValueError('Only supported for valid input') #.format(opts["connect"]))

       #//See if the directory supplied exists.  If not, raise exception indicating that error
     if is_dir  == True :
       path = os.path.abspath(path) + "/" + opts_dict['bucket_name']
       print( 'Directory Path is valid' , path)
       files = [f for f in os.listdir(path) if re.match(r'(^[cdCD].*)\.[0-9]+\.nosql', f)]
       for f in files :
         #print(f)
         matchObj = re.match( r'(.*)\.([0-9]+).nosql', f, re.M|re.I)
         if matchObj:
             #print ("operation ", matchObj.group(1) , " version --> ",  matchObj.group(2))
             operation =  str(matchObj.group(1))
             version = str(matchObj.group(2))
             #print(operation , version)
             file_path = os.path.join(path,f)
             #print(file_path)
             if operation.lower() == 'create' :
               self.creates.append(DbScript(f,version,file_path))
             elif operation.lower() == 'delta' :
               self.deltas.append(DbScript(f,version,file_path))
             else :
                 print("skip the file",f)
             self.creates.sort(key=operator.attrgetter('version'))
             self.deltas.sort(key=operator.attrgetter('version'))
         else:
            print "No match!!"
     for script in self.creates :
         print('->',script.version,script.name)
     print('----')
     for script in self.deltas :
         print('->',script.version,script.name)

   def findDeltasGreaterThan(self,version_int) :
     return self.filterDBScriptsGreaterThan(version_int, self.deltas)
     #try :
     #  deltas = list(filter(lambda x: x.version > version_int , self.deltas))
     #  return deltas
     #except:
     #  return []

   def findCreateScriptsGreaterThan(self,version_int) :
     return self.filterDBScriptsGreaterThan(version_int, self.creates)

   def filterDBScriptsGreaterThan(self,version_int,list_items) :
     try :
       filtered_list = list(filter(lambda x: x.version > version_int , list_items))
       return filtered_list
     except:
       return []

   def findCreateScriptsEqualTo(self,version_int) :
     return self.filterDBScriptsEqualTo(version_int, self.creates)

   def filterDBScriptsEqualTo(self,version_int,list_items) :
     item = None
     try :
       item = list(filter(lambda x: int(x.version) == version_int , list_items))
     except:
       return item
     finally :
       return item



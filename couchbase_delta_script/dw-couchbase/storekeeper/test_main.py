import sys , getopt, os

from couchbase.cluster import Cluster
from couchbase.cluster import PasswordAuthenticator
from couchbase.n1ql import N1QLQuery
from BucketIndexManager import BucketIndexManager
from CouchbaseBroker import CouchbaseBroker
import CustomException
from DbScriptsRunner import DbScriptsRunner


##rv = cb.get('airline_24')
##print(rv)
#
##query = N1QLQuery("""SELECT airportname, city, country FROM `travel-sample` """
##                  """WHERE type="airport" AND city=$my_city""", my_city="Reno")
##for row in cb.n1ql_query(query):
##    print("---row --")
##    print(row)
#def parse(opts,args):
#  opts_dict = {
#      "connect"  : "couchbase://127.0.0.1",
#      "username" : "aquto",
#      "password" : "aqut0r0cks",
#      "bucket_name" : "travel-sample",
#      "directory" : "../nosql/"
#  }
#
#  for opt, arg in opts:
#      if opt == '-h':
#         print (usage)
#         sys.exit()
#      elif opt in ("-c", "--connect"):
#         opts_dict["connect"] = arg
#      elif opt in ("-u", "--uername"):
#         opts_dict["username"] = arg
#      elif opt in ("-p", "--password"):
#         opts_dict["password"]= arg
#      elif opt in ("-b", "--bucket_name"):
#         opts_dict["bucket_name"] = arg
#      elif opt in ("-d", "--directory"):
#         opts_dict["directory"] = arg
#      elif opt in ("-w", "--wipe"):
#         opts_dict["wipe"] = 'true'
#
#  return opts_dict
#
#
#if __name__ == '__main__':
#
#  argv = sys.argv[1:]
#  usage="main.py -c <couchbase://127.0.0.1> -u <username> -p <password> -b <bucket_name> \n main.py --connect <couchbase://127.0.0.1> --username <username> --password <password> --bucket_name <bucket_name> -w  <true>"
#  try:
#      opts, args = getopt.getopt(argv,"hc:u:p:b:d:w:",["connect=","username=","password","bucket_name","directory","wipe"])
#  except getopt.GetoptError:
#     print (usage)
#     sys.exit(2)
#  except :
#     print (usage)
#     sys.exit(2)
#
#  opts_dict = parse(opts, args)
#  print(opts_dict)
#  db_broker = CouchbaseBroker(opts_dict)
#  #bucket = db_broker.open_bucket(opts_dict['bucket_name'])
#  #index_mgr = BucketIndexManager(bucket)
#
#  scripts = DbScriptsRunner(opts_dict)
#
#  if opts_dict['wipe'] == 'true' :
#    print("wiping bucket",opts_dict["bucket_name"])
#    db_broker.wipeBucket(opts_dict)
#
#
#
#
#
cluster = Cluster('couchbase://127.0.0.1')
authenticator = PasswordAuthenticator('aquto', 'aqut0r0cks')
cluster.authenticate(authenticator)
cb = cluster.open_bucket('beer-sample')
#  mgr = cb.bucket_manager()

index_mgr = BucketIndexManager(cb)
index_mgr.list_indexes()
print("Hello BucketIndexManager")



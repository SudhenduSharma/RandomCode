from couchbase.cluster import Cluster
from couchbase.cluster import PasswordAuthenticator
from couchbase.n1ql import N1QLQuery
from BucketIndexManager import BucketIndexManager


#rv = cb.get('airline_24')
#print(rv)

#query = N1QLQuery("""SELECT airportname, city, country FROM `travel-sample` """
#                  """WHERE type="airport" AND city=$my_city""", my_city="Reno")
#for row in cb.n1ql_query(query):
#    print("---row --")
#    print(row)

if __name__ == '__main__':
  cluster = Cluster('couchbase://tdb01.dev.aquto.internal')
  authenticator = PasswordAuthenticator('aquto', 'aqut0r0cks')
  cluster.authenticate(authenticator)
  cb = cluster.open_bucket('accdet')
#  mgr = cb.bucket_manager()

  index_mgr = BucketIndexManager(cb)

  index_mgr.alt_indexes('pgw_customers_customerId',)

  index_mgr.list_indexes()
  print("Hello BucketIndexManager")



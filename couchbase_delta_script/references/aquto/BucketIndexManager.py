from couchbase.bucketmanager import BucketManager
from couchbase.bucket import Bucket
import couchbase.exceptions as E

class InvalidArgType(RuntimeError):
   def __init__(self, arg):
      self.args = arg

class BucketIndexManager():

    def __init__(self,bucket):
        self.cb = bucket # type: Bucket
        if self.cb.__class__ is not Bucket:
            raise  InvalidArgType('Only supported for synchronous bucket')
        self.mgr = bucket.bucket_manager() # type: BucketManager

    def _clear_indexes(self):
        for index in self.mgr.n1ql_index_list():
            mgr.n1ql_index_drop(index)

    def create_primary(self):
        self.mgr.n1ql_index_create_primary()
        # Ensure we can issue a query
        qstr = 'select * from {0} limit 1'.format(cb.bucket)
        cb.n1ql_query(qstr).execute()

    def drop_primary(self):
        # Drop the primary index
        self.mgr.n1ql_index_drop_primary()
        # Ensure we get an error when executing the query
        self.assertRaises(
            E.CouchbaseError, lambda x: x.execute(), cb.n1ql_query(qstr))

    def create_named_primary(self,index_name):
        # Try to create a _named_ primary index
        mgr.n1ql_index_create(index_name, primary=True)

    def alt_indexes(self,index_name,fields_tuple):
        cb = self.cb  # type: Bucket
        mgr = cb.bucket_manager()
        mgr.n1ql_index_create(index_name, fields=fields_tuple)

    def drop_index(self,index_name):
        # Drop the index
        mgr.n1ql_index_drop(index_name)

    def create_index_with_condition(self,index_name,fields_list,condition_tuple):
        # Create an index with a condition
        mgr.n1ql_index_create(index_name, fields_list, condition=condition_tuple)

    def list_indexes(self):
        cb = self.cb  # type: Bucket
        mgr = cb.bucket_manager()
        for index in self.mgr.n1ql_index_list():
            print(index)

#    def test_create_named_primary(self)
#        qstr = "TBD" # TBD/TODO
#        cb.n1ql_query(qstr).execute()
#
#    def test_drop_primary(self)
#        self.drop_primary()
#        qstr = "TBD" # TBD/TODO
#        #mgr.n1ql_index_drop_primary(ignore_missing=True)
#        #self.assertRaises(E.NotFoundError, mgr.n1ql_index_drop_primary)
#    def test_alt_indexes(self,index_name,fields_tuple):
#        qq = 'select {1}, {2} from `{0}` where {1}=1 and {2}=2 limit 1'\
#            .format(cb.bucket, *fields_tuple)
#        cb.n1ql_query(qq).execute()


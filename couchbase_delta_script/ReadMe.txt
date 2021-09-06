#https://blog.couchbase.com/couchbase-using-docker-compose/
#https://github.com/arun-gupta/docker-images/tree/master/couchbase
#https://github.com/arun-gupta/docker-images/blob/master/couchbase/readme.adoc
#
#Use the credentials Administrator/password to access the web console

docker-compose up

docker run  --name couchbase -p 8091-8094:8091-8094 -p 11210:11210 couchbase:latest

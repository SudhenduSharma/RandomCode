#About this project
It is as DB upgrade script. Many languages such as go has automatic upgrade libraries such as "https://github.com/golang-migrate/migrate"

This is a test project to achieve similar behaviour for proprietary products. It is not a generic impelementation but good enough for my use case.

The storekeepere applies the index and bucket creation db upgrade based on scripts such as those are present in bucket folder.
The folder name refers to couchbase buckets.
e.g. couchbase_delta_script/dw-couchbase/nosql/travel-sample/
    create.1.nosql
    create.2.nosql

travel-sample --> Counchbase Buckets
create.X.nosql --> contains the index creation/deletion operation


# Bringing up Couchbase Locally
    #https://blog.couchbase.com/couchbase-using-docker-compose/
    #https://github.com/arun-gupta/docker-images/tree/master/couchbase
    #https://github.com/arun-gupta/docker-images/blob/master/couchbase/readme.adoc
    #
    #Use the credentials Administrator/password to access the web console


    docker-compose up

    docker run  --name couchbase -p 8091-8094:8091-8094 -p 11210:11210 couchbase:latest

FROM ubuntu:latest

#no git 
MAINTAINER  jiudiaren <lianpengfei12@foxmail.com>
RUN apt-get update
RUN apt-get -y install redis-server redis-tools vim

EXPOSE 6397
ENTRYPOINT ["/usr/bin/redis-server"]
 
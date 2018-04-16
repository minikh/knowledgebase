FROM java:8u111-jre

MAINTAINER minikh

RUN apt-get update && \
    apt-get upgrade -y && \ 	
	apt-get install -y \
	git \
	vim \
	mc 
#RUN apt-get update && apt-get install -y mc vim

ADD bootstrap.sh /root/bootstrap.sh
CMD sh /root/bootstrap.sh

VOLUME /home/docker/app/
EXPOSE 80

CMD sh /root/bootstrap.sh

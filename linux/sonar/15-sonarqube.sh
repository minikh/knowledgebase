#!/bin/bash

if [ "$(id -u)" != "0" ] ; then
	echo "Недостаточно прав для выполнения операции"
	exit 1
fi

psql -h 127.0.0.1 -U postgres -d postgres -c 'create database sonarqube'
unzip resources/sonarqube-5.2.zip -d /opt/

sed -i "s/#sonar\.jdbc\.username.*$/sonar\.jdbc\.username=postgres/g" /opt/sonarqube-5.2/conf/sonar.properties
sed -i "s/#sonar\.jdbc\.password.*$/sonar\.jdbc\.password=postgres/g" /opt/sonarqube-5.2/conf/sonar.properties
sed -i "s/#sonar\.jdbc\.url.*$/sonar\.jdbc\.url=jdbc\:postgresql\:\/\/127.0.0.1\/sonarqube/g" /opt/sonarqube-5.2/conf/sonar.properties
sed -i "s/#sonar\.web\.javaOpts.*$/sonar\.web\.javaOpts=-Xmx768m -Xms256m -XX:MaxPermSize=160m -XX:+HeapDumpOnOutOfMemoryError -Djava.net.preferIPv4Stack=true -server/g" /opt/sonarqube-5.2/conf/sonar.properties

sed -i "s/#sonar\.web\.host=0\.0\.0\.0/sonar\.web\.host=127\.0\.0\.1/g" /opt/sonarqube-5.2/conf/sonar.properties
sed -i "s/#sonar\.web\.port.*$/sonar\.web\.port=3250/g" /opt/sonarqube-5.2/conf/sonar.properties

/opt/sonarqube-5.2/bin/linux-x86-64/sonar.sh start
update-alternatives --install /usr/bin/sonarqube sonarqube /opt/sonarqube-5.2/bin/linux-x86-64/sonar.sh 2000

cat > /etc/nginx/sites-available/sonar.disom.pc<<EOF
upstream sonar_pc_upstream {
	server 127.0.0.1:3250;
}
                                                                                                                                                                                                                                                    
server {
	listen 80;
    server_name sonar.disom.pc;
                                                                                                                                                                                                                                                    
	location / {
		proxy_pass http://sonar_pc_upstream;
		proxy_read_timeout 360;
		proxy_set_header Host $host;
		client_max_body_size 100m;
	}
}
EOF

ln -s /etc/nginx/sites-available/sonar.disom.pc /etc/nginx/sites-enabled/sonar.disom.pc

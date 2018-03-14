gradle xjc

для запуска приложений необходимо:
1. consul
#consul agent -ui -dev -config-dir=/etc/consul.d
consul agent -ui -dev
2. activemq
/opt/apache-activemq-5.15.0/bin/activemq start
3.spring cloud config с профилем native
./gradlew -Dspring.profiles.active=native bootRun
4.Postgres
-создать БД openbankdb (postgres/postgres)
-для каждого микросервиса создать схему <имя сервиса>_service (например card_service)
5.в /etc/hosts прописать 127.0.0.1 <любые буквы>.open.ru
6.для получения токена зайти на roox1.open.ru (необходимо для авторизации на микросервисах)
tilitilichki/123/1234
токен будет действовать 5 минут


gradle
для локального использования проекта commons прописать:
~/.gradle/.gradle.properties
org.gradle.daemon=true
systemProp.IS_SNAPSHOT=true
теперь для проекта commons можно делать так: 
gradle clean build publishToMavenLocal

gradle card-back:dependencies --configuration compile

/------------------------------
запуск сервиса локально с профилем 
front_dev_nightswatch
/------------------------------
bootRun.systemProperties = System.properties
bootRun.systemProperties = System.properties as Map<String, ?>


apply plugin: 'project-report'
./gradlew htmlDependencyReport


List<Card> cards = ofNullable(sendAndReceive(builder.build(virtualCardNums), AGREEMENT_CARD, CARD_CREDIT_INFO))
	.flatMap(e -> ofNullable(e.getAgreement()))
	.flatMap(e -> ofNullable(e.getCard()))
	.flatMap(e -> ofNullable(e.getAnsCardCreditInfo()))
	.map(TCardCreditInfoAns::getCard)
	.orElseGet(Collections::emptyList);
	
return ofNullable(card)
	.orElse(emptyList())
	.stream()
	.map(this::convert)
	.collect(toList());	


hazelcast
ns credits - перейти в credits кеш
m.clear - очистить

nginx. reverse-proxy
cd /opt/nginx/sites-available/
vim reverse-proxy.conf
/etc/init.d/nginx restart



net stop jenkins
net start jenkins

gradle clean build --refresh-dependencies

Создаём резервную копию конфига:
cp /etc/haproxy/haproxy.cfg{,.backup}


















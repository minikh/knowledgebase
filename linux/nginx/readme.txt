docker run --rm -v /home/minikh/nginx/www:/usr/share/nginx/html:ro -v /home/minikh/nginx/default.conf:/etc/nginx/conf.d/default.conf -p 80:80  nginx

server {
        listen 80;
        server_name 82.202.226.239;
        root /usr/share/nginx/html/vmsystems.ru;
}


server {
        listen 80;

        server_name landing.metacards.online;

        root /usr/share/nginx/html/landing.metacards.online;

}

server {
        listen 80;
        server_name vmsystems.ru;
        root /usr/share/nginx/html/vmsystems.ru;
}


upstream metacard {
        server 172.17.0.1:8090;
}


server {
        listen 80;
        server_name vmsystems.ru;
        root /usr/share/nginx/html/vmsystems.ru;
}


upstream metacard {
        server 172.17.0.1:8090;
}

server {
        listen 80;

        server_name metacards.online;

        location / {
                proxy_pass http://metacard;
                proxy_read_timeout 7200;
                proxy_set_header Host $host;
                proxy_set_header X-Real-IP $remote_addr;
                proxy_set_header REMOTE_ADDR $remote_addr;
                proxy_http_version 1.1;
                proxy_set_header Upgrade $http_upgrade;
                proxy_set_header Connection "upgrade";

        }
}

FROM debian:buster

RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install 	vim \
						wget \
						nginx \
						mariadb-server \
						mariadb-client \
						php-fpm \
						php-mysql \
						openssl \
						php7.3-mysql \
						php-mbstring \
						php7.3 \
						php7.3-fpm \
						php-common \
						php7.3-cli \
						php7.3-json \
						php7.3-readline \
						php7.3-opcache

RUN mkdir /var/www/tzenyatt && mkdir /var/www/tzenyatt/wordpress
RUN wget -P /var/www/tzenyatt https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN wget -P /var/www/tzenyatt/wordpress https://wordpress.org/latest.tar.gz

RUN chown -R www-data /var/www/*
RUN chmod -R 755 /var/www/*
RUN tar -xvf /var/www/tzenyatt/phpMyAdmin-5.0.4-english.tar.gz -C /var/www/tzenyatt
RUN tar -xvf /var/www/tzenyatt/wordpress/latest.tar.gz -C /var/www/tzenyatt/wordpress
RUN rm -rf /var/www/tzenyatt/phpMyAdmin-5.0.4-english.tar.gz /var/www/tzenyatt/wordpress/latest.tar.gz
RUN	ln -s /etc/nginx/sites-available/nginx  /etc/nginx/sites-enabled/nginx

COPY    ./srcs/nginx /etc/nginx/sites-available/nginx	
COPY	./srcs/init.sh /var

CMD bash var/init.sh

EXPOSE 80 443

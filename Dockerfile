# base image
FROM	debian:buster

LABEL	mainatiner = "mchun@student.42seoul.kr"

RUN		apt-get upgrade && \
		apt-get update && \
		apt-get install -y \
		nginx \
		mariadb-server \
		php-mysql \
		openssl \
		vim \
		wget \
		curl \
		php7.3-fpm

RUN		mkdir /home/temp

COPY	./srcs/run.sh /home/
COPY	./srcs/config.inc.php /home/temp
COPY	./srcs/wp-config.php /home/temp
COPY	./srcs/phpinfo.php /home/temp
COPY	./srcs/default /home/temp

EXPOSE 80 443

CMD		bash /home/run.sh

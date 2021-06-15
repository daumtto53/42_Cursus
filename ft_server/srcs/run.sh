
# 권한 설정
chmod 700 /home/run.sh

# ngnix 설정
mkdir	/etc/nginx/ssl
openssl	req -newkey rsa:2048 -days 365 -nodes -x509 -subj "/C=KR"\
	-keyout /etc/nginx/ssl/ft_server.key -out /etc/nginx/ssl/ft_server.crt
chmod	700 /etc/nginx/ssl/ft_server.key /etc/nginx/ssl/ft_server.crt
mv /home/temp/default /etc/nginx/sites-available/

# DB 생성 + 권한 추가
service mysql start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" \
	| mysql -u root --skip-password
echo "USE wordpress; CREATE TABLE ftserver (id int NOT NULL PRIMARY KEY, name varchar(10) NOT NULL); INSERT INTO ftserver VALUES(1, 'mchun');" \
	| mysql -u root --skip-password
echo "CREATE USER IF NOT EXISTS 'mchun'@'localhost';" \
	| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'mchun'@'localhost' WITH GRANT OPTION;" \
	| mysql -u root --skip-password
echo "flush privileges;" \
	| mysql -u root --skip-password
service mysql stop

# PHP 생성
mv /home/temp/phpinfo.php /var/www/html

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
rm -v phpMyAdmin-5.0.2-all-languages.tar.gz
mv ./phpmyadmin /var/www/html/
cp -rp /home/temp/config.inc.php /var/www/html/phpmyadmin

# Wordpress 생성
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm -v latest.tar.gz
mv wordpress /var/www/html/
cp -rp /home/temp/wp-config.php /var/www/html/wordpress

# 데몬 실행
service nginx start
service php7.3-fpm start
service mysql start

# Bash
bash

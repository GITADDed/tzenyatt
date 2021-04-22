service mysql start
echo "CREATE DATABASE dbase;" | mysql -u root -padmin
echo "CREATE USER 'admin'@'localhost' identified by 'admin'" | mysql -u root -padmin
echo "GRANT ALL PRIVILEGES ON dbase.* to 'admin'@'localhost' IDENTIFIED BY 'admin' WITH GRANT OPTION" | mysql -u root -padmin
echo "FLUSH PRIVILEGES;" | mysql -u root -padmin
service nginx start
service php7.3-fpm start
bash

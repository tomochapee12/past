mysqlにはmysql -u root -pで入る。
poke.phpはdbから表示させる
    php -S 0.0.0.0:9000で開始
    停止はctrl+c
    http://wslのIPアドレス:9000/poke.php
pokemon_fetcher.pyはデータ収集
    mysql -u root -p
    USE pokemon_db;
    python pokemon_fetcher.py
    で実行
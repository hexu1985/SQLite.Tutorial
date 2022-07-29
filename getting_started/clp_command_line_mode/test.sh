rm -f test*.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "dump database"
sqlite3 test.db .dump > test.sql

echo "copy database"
sqlite3 test2.db < test.sql

echo "copy database 2"
sqlite3 -init test.sql test3.db .exit

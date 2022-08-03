rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "order by test"
sqlite3 test.db < order_by.sql

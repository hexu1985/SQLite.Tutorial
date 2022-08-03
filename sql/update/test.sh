rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "update test"
sqlite3 test.db < update.sql

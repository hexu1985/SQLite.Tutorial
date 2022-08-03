rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "function test"
sqlite3 test.db < function.sql

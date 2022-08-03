rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "delete test"
sqlite3 test.db < delete.sql

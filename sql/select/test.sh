rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "select test"
sqlite3 test.db < select.sql

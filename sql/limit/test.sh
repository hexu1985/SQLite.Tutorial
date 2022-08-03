rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "limit test"
sqlite3 test.db < limit.sql

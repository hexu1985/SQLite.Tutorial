rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "analyzer database"
sqlite3_analyzer test.db


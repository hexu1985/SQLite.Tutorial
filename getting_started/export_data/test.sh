rm -f test.db file.sql

echo "init database"
sqlite3 test.db < init_database.sql

echo "dump database"
sqlite3 test.db < dump.sql > file.sql

echo "show file.sql"
cat file.sql


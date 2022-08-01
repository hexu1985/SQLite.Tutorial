rm -f *.db file.sql

echo "init database"
sqlite3 test.db < init_database.sql

echo "dump database"
sqlite3 test.db ".dump" > file.sql

echo "show file.sql"
cat file.sql

echo "exec .read cmd"
sqlite3 test2.db < import.sql

echo "select * from test of test2.db"
sqlite3 test2.db "select * from test"

echo "exec .read cmd again"
sqlite3 test.db < import_again.sql

# will print error message
echo "exec .read cmd"
sqlite3 test.db < import.sql


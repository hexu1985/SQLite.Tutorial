rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "show data before update"
sqlite3 test.db < select.sql

echo "update test"
./update_name_style

echo "show data after update"
sqlite3 test.db < select.sql


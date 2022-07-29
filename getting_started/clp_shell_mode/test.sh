rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "show data" 
sqlite3 test.db < format_select.sql


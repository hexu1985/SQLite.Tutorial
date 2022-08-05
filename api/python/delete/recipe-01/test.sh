rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "show data before delete"
sqlite3 test.db < select.sql

echo "delete test"
./delete_data.py

echo "show data after delete"
sqlite3 test.db < select.sql


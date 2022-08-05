rm -f test.db

echo "init database"
sqlite3 test.db < init_database.sql

echo "select test"
./select_data.py


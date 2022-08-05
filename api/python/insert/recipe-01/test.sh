rm -f test.db

echo "create table"
sqlite3 test.db < create_tables.sql

echo "show data before insert"
sqlite3 test.db < select.sql

echo "insert data"
./insert_data.py

echo "show data after insert"
sqlite3 test.db < select.sql


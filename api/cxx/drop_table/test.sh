rm -f test.db

echo "create tables"
sqlite3 test.db < create_tables.sql

echo "show tables"
sqlite3 test.db ".tables"

echo "drop tables"
./drop_table

echo "show tables"
sqlite3 test.db ".tables"


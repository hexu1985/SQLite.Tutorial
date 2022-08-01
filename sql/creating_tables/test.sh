rm -f test.db

echo "create tables"
sqlite3 test.db < create_tables.sql

echo "show tables"
sqlite3 test.db ".tables"

echo "show schema of COMPANY"
sqlite3 test.db ".schema COMPANY"

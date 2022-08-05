rm -f test.db

echo "create table"
./create_table

echo "show tables"
sqlite3 test.db ".tables"

echo "show schema of COMPANY"
sqlite3 test.db ".schema COMPANY"

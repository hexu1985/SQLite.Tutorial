rm -f test.db

echo "create table"
sqlite3 test.db < create_table.sql

echo "show schema"
sqlite3 test.db ".schema contacts"

echo "alter table"
sqlite3 test.db < alter_table.sql

echo "show schema"
sqlite3 test.db ".schema contacts"


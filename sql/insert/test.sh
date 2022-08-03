rm -f test.db

echo "exec insert"
sqlite3 test.db < insert.sql

echo "select table"
sqlite3 test.db "select * from COMPANY;"

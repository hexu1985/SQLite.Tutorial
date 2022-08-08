rm -f test.db

echo "create tables"
sqlite3 test.db < create_tables.sql

echo "before insert: select * from COMPANY"
sqlite3 test.db "select * from COMPANY"

echo "insert no trasaction"
./insert_no_transaction

echo "after insert: select * from COMPANY"
sqlite3 test.db "select * from COMPANY"

echo "======================================================="

rm -f test.db

echo "create tables"
sqlite3 test.db < create_tables.sql

echo "before insert: select * from COMPANY"
sqlite3 test.db "select * from COMPANY"

echo "insert no trasaction"
./insert_with_transaction

echo "after insert: select * from COMPANY"
sqlite3 test.db "select * from COMPANY"


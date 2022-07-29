rm -f test.db

echo "==================================== init database ====================================" 
sqlite3 test.db < init_database.sql
echo 

echo "==================================== show schema ====================================" 
sqlite3 test.db < show_schema.sql
echo 

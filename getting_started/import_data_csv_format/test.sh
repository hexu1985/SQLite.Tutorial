rm -f *.db *.csv

echo "init database"
sqlite3 test.db < init_database.sql

echo "export data format separator ,"
sqlite3 test.db < export_sep_comma.sql

echo "import data format separator ,"
sqlite3 test.db < import_sep_comma.sql

echo "export data mode csv"
sqlite3 test.db < export_mode_csv.sql

echo "import data mode csv" 
sqlite3 test.db < import_mode_csv.sql


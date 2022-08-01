rm -f test.db mode_csv.csv sep_comma.csv

echo "init database"
sqlite3 test.db < init_database.sql

echo "export data format separator ,"
sqlite3 test.db < export_sep_comma.sql
hexdump -C sep_comma.csv

echo "export data mode csv"
sqlite3 test.db < export_mode_csv.sql
hexdump -C mode_csv.csv



create table test3(id integer primary key, value text);
.separator ,
.import mode_csv.csv test3
.headers on
.mode column
select * from test3;


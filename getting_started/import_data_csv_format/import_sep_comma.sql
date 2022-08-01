
create table test2(id integer primary key, value text);
.separator ,
.import sep_comma.csv test2
.headers on
.mode column
select * from test2;


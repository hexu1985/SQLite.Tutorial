
.output text.csv
.separator ,
select * from test where value like 'm%';
.output stdout

create table test2(id integer primary key, value text);
.import text.csv test2


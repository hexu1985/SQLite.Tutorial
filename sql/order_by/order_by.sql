
.echo on
.mode column
.headers on
.nullvalue NULL

select * from foods where name like 'B%' order by type_id desc;

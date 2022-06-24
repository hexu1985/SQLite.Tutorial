
.echo on
.mode column
.headers on
.nullvalue NULL

select * from foods where name like 'B%' order by type_id desc, name limit 10; 

select * from foods where name like 'B%' order by type_id desc, name limit 1 offset 2;

select * from foods where name like 'B%' order by type_id desc, name limit 2,1;

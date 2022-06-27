
.echo on
.mode column
.headers on
.nullvalue NULL

select count(*) from foods where type_id=1;

select avg(length(name)) from foods;


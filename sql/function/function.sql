
.echo on
.mode column
.headers on
.nullvalue NULL

select upper('hello newman'), length('hello newman'), abs(-12);

select id, upper(name), length(name) from foods
where type_id=1 limit 10;

select id, upper(name), length(name) from foods
where length(name) < 5 limit 5;

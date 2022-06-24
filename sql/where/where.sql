
.echo on
.mode column
.headers on
.nullvalue NULL

select * from foods where name='JujyFruit' and type_id=9;

select id, name from foods where name like 'J%';

select id, name from foods where name like '%ac%P%';

select id, name from foods where name like '%ac%P%' and name not like '%Sch%';

select id, name from foods where name glob 'Pine*';

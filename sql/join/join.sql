
.echo on
.mode column
.headers on
.nullvalue NULL

select foods.name, food_types.name
from foods, food_types
where foods.type_id=food_types.id limit 10;

-- inner join
select *
from foods inner join food_types on foods.id = food_types.id;

-- cross join
select * from foods, food_types;

select * from foods cross join food_types;

-- outer join
select *
from foods left outer join foods_episodes on foods.id=foods_episodes.food_id;

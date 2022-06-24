### 表查询

表查询的语法如下:

```
select [distinct] heading
from tables
where predicate
group by columns
having predicate
order by columns
limit count,offset;
```


示例SQL语句:

```
sqlite> select id, name from food_types;
id         name
---------- ----------
1          Bakery
2          Cereal
3          Chicken/Fowl
4          Condiments
5          Dairy
6          Dip
7          Drinks
8          Fruit
9          Junkfood
10         Meat
11         Rice/Pasta
12         Sandwiches
13         Seafood
14         Soup
15         Vegetables
```


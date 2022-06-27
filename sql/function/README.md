### SQLite函数

SQLite 有许多内置函数用于处理字符串或数字数据。

示例SQL语句:

```
sqlite> select upper('hello newman'), length('hello newman'), abs(-12);
upper('hello newman')  length('hello newman')  abs(-12)
---------------------  ----------------------  ----------
HELLO NEWMAN           12                      12

sqlite> select id, upper(name), length(name) from foods
where type_id=1 limit 10;
id          upper(name)  length(name)
----------  -----------  ------------
1           BAGELS       6
2           BAGELS, RAI  14
3           BAVARIAN CR  18
4           BEAR CLAWS   10
5           BLACK AND W  23
6           BREAD (WITH  17
7           BUTTERFINGE  13
8           CARROT CAKE  11
9           CHIPS AHOY   18
10          CHOCOLATE B  15

sqlite> select id, upper(name), length(name) from foods
where length(name) < 5 limit 5;
id          upper(name)  length(name)
----------  -----------  ------------
36          PIE          3
48          BRAN         4
56          KIX          3
57          LIFE         4
80          DUCK         4
```

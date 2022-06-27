### SQLite聚合函数

SQLite聚合函数是将多行的值组合在一起作为某些条件的输入并形成单个值作为输出结果的函数。

示例SQL语句:

```
sqlite> select count(*) from foods where type_id=1;
count(*)
----------
47

sqlite> select avg(length(name)) from foods;
avg(length(name))
-----------------
12.5849514563107
```

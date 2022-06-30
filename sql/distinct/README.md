### distinct关键字

SQLite 的 DISTINCT 关键字与 SELECT 语句一起使用，来消除所有重复的记录，并只获取唯一一次记录。

有可能出现一种情况，在一个表中有多个重复的记录。当提取这样的记录时，DISTINCT 关键字就显得特别有意义，它只获取唯一一次记录，而不是获取重复记录。

用于消除重复记录的 DISTINCT 关键字的基本语法如下：

```
SELECT DISTINCT column1, column2,.....columnN
FROM table_name
WHERE [condition]
```

示例SQL语句:

```
sqlite> select distinct type_id from foods;
type_id   
----------
1         
2         
3         
4         
5         
6         
7         
8         
9         
10        
11        
12        
13        
14        
15  
```

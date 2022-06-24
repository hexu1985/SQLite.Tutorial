### limit子句

SQLite 的 LIMIT 子句用于限制由 SELECT 语句返回的数据数量.

带有 LIMIT 子句的 SELECT 语句的基本语法如下:

```
SELECT column1, column2, columnN
FROM table_name
LIMIT [no of rows]
```

示例SQL语句:

```
sqlite> select * from foods where name like 'B%' order by type_id desc, name limit 10;
id          type_id     name
----------  ----------  -----------
382         15          Baked Beans
383         15          Baked Potat
384         15          Big Salad
385         15          Brocolli
362         14          Bouillabais
328         12          BLT
327         12          Bacon Club
326         12          Bologna
329         12          Brisket San
274         10          Bacon
```

下面是 LIMIT 子句与 OFFSET 子句一起使用时的语法:

```
SELECT column1, column2, columnN
FROM table_name
LIMIT [no of rows] OFFSET [row num]
```

可以有如下同等表达:

```
SELECT column1, column2, columnN
FROM table_name
LIMIT [row num], [no of rows] 
```

`SELECT  *   FROM trom_data  LIMIT  nNumRecord   OFFSET nBaseRow`
表示从第nBaseRow行(基于0的索引)(包括该行)开始,取其后的nNumRecord条记录

例如: LIMIT 1 OFFSET 0的意思是说在查询结果中以第0条记录为基准（包括第0条），取1条记录


示例SQL语句:

```
sqlite> select * from foods where name like 'B%' order by type_id desc, name limit 1 offset 2;
id          type_id     name
----------  ----------  ----------
384         15          Big Salad

sqlite> select * from foods where name like 'B%' order by type_id desc, name limit 2,1;
id          type_id     name
----------  ----------  ----------
384         15          Big Salad
```

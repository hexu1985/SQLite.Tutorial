### order by子句

ORDER BY 子句的基本语法如下：

```
SELECT column-list
FROM table_name
[WHERE condition]
[ORDER BY column1, column2, .. columnN] [ASC | DESC];
```

示例SQL语句:
```
sqlite> select * from foods where name like 'B%' order by type_id desc
id          type_id     name
----------  ----------  -----------
382         15          Baked Beans
383         15          Baked Potat
384         15          Big Salad
385         15          Brocolli
362         14          Bouillabais
326         12          Bologna
327         12          Bacon Club
328         12          BLT
329         12          Brisket San
274         10          Bacon
275         10          Beef-A-Reen
276         10          Brisket
299         10          Bologna
214         9           Big Hunk
215         9           Black Jacks
216         9           Bubble Gum
192         8           Banana
131         7           Beaujolais
132         7           Beer
133         7           Bosco
108         5           Banana Yogu
109         5           Butter
87          4           Barbeque Sa
63          3           Broiled Chi
48          2           Bran
1           1           Bagels
2           1           Bagels, rai
3           1           Bavarian Cr
4           1           Bear Claws
5           1           Black and W
6           1           Bread (with
7           1           Butterfinge
```

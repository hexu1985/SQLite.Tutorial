### where字句


逻辑操作符, 示例SQL语句:

```
sqlite> select * from foods where name='JujyFruit' and type_id=9;
id          type_id     name
----------  ----------  ----------
244         9           JujyFruit
```

LIKE操作符, 模式中的百分号(%)可以与任意0个或多个字符匹配. 下画线(_)可以与任意单个字符匹配. 百分号是贪婪匹配, 示例SQL语句:

```
sqlite> select id, name from foods where name like 'J%';
id          name      
----------  ----------
156         Juice box 
236         Jucyfruit 
243         Jello with
244         JujyFruit 
245         Junior Min
370         Jambalaya 

sqlite> select id, name from foods where name like '%ac%P%';
id          name
----------  --------------------
38          Pie (Blackberry) Pie
127         Guacamole Dip
168         Peach Schnapps
198         Macinaw peaches

sqlite> select id, name from foods where name like '%ac%P%' and name not like '%Sch%';
id          name
----------  --------------------
38          Pie (Blackberry) Pie
127         Guacamole Dip
198         Macinaw peaches
```

GLOB操作符, SQLite 的 GLOB 运算符是用来匹配通配符指定模式的文本值.
与 LIKE 运算符不同的是, GLOB 是大小写敏感的, 对于下面的通配符, 它遵循 UNIX 的语法.
星号(*)代表零个, 一个或多个数字或字符. 问号(?)代表一个单一的数字或字符. 这些符号可以被组合使用.
示例SQL语句:

```
sqlite> select id, name from foods where name glob 'Pine*';
id          name
----------  ----------
205         Pineapple
258         Pineapple
```


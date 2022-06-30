### join子句

SQLite 的 Join 子句用于结合两个或多个数据库中表的记录。JOIN 是一种通过共同值来结合两个表中字段的手段。

SQL 定义了三种主要类型的连接：

- 内连接 - INNER JOIN

- 交叉连接 - CROSS JOIN

- 外连接 - OUTER JOIN

示例SQL语句:
```
sqlite> select foods.name, food_types.name
        from foods, food_types
        where foods.type_id=food_types.id limit 10;
name        name      
----------  ----------
Bagels      Bakery    
Bagels, ra  Bakery    
Bavarian C  Bakery    
Bear Claws  Bakery    
Black and   Bakery    
Bread (wit  Bakery    
Butterfing  Bakery    
Carrot Cak  Bakery    
Chips Ahoy  Bakery    
Chocolate   Bakery    
```

#### 内连接 - INNER JOIN

内连接（INNER JOIN）根据连接谓词结合两个表（table1 和 table2）的列值来创建一个新的结果表。查询会把 table1 中的每一行与 table2 中的每一行进行比较，找到所有满足连接谓词的行的匹配对。当满足连接谓词时，A 和 B 行的每个匹配对的列值会合并成一个结果行。

内连接（INNER JOIN）是最常见的连接类型，是默认的连接类型。INNER 关键字是可选的。

下面是内连接（INNER JOIN）的语法：

```
SELECT ... FROM table1 [INNER] JOIN table2 ON conditional_expression ...
```

为了避免冗余，并保持较短的措辞，可以使用 USING 表达式声明内连接（INNER JOIN）条件。这个表达式指定一个或多个列的列表：

```
SELECT ... FROM table1 JOIN table2 USING ( column1 ,... ) ...
```

示例SQL语句:
```
sqlite> select *
        from foods inner join food_types on foods.id = food_types.id;
id          type_id     name        id          name      
----------  ----------  ----------  ----------  ----------
1           1           Bagels      1           Bakery    
2           1           Bagels, ra  2           Cereal    
3           1           Bavarian C  3           Chicken/Fo
4           1           Bear Claws  4           Condiments
5           1           Black and   5           Dairy     
6           1           Bread (wit  6           Dip       
7           1           Butterfing  7           Drinks    
8           1           Carrot Cak  8           Fruit     
9           1           Chips Ahoy  9           Junkfood  
10          1           Chocolate   10          Meat      
11          1           Chocolate   11          Rice/Pasta
12          1           Chocolate   12          Sandwiches
13          1           Cinnamon B  13          Seafood   
14          1           Cinnamon S  14          Soup      
15          1           Cookie      15          Vegetables
```

#### 交叉连接 - CROSS JOIN

交叉连接（CROSS JOIN）把第一个表的每一行与第二个表的每一行进行匹配。如果两个输入表分别有 x 和 y 行，则结果表有 x*y 行。由于交叉连接（CROSS JOIN）有可能产生非常大的表，使用时必须谨慎，只在适当的时候使用它们。

下面是交叉连接（CROSS JOIN）的语法：

```
SELECT ... FROM table1 CROSS JOIN table2 ...
```

示例SQL语句:
```
sqlite> select * from foods, food_types;
id          type_id     name        id          name      
----------  ----------  ----------  ----------  ----------
1           1           Bagels      1           Bakery    
1           1           Bagels      2           Cereal    
1           1           Bagels      3           Chicken/Fo
1           1           Bagels      4           Condiments
1           1           Bagels      5           Dairy     
1           1           Bagels      6           Dip       
1           1           Bagels      7           Drinks    
1           1           Bagels      8           Fruit     
1           1           Bagels      9           Junkfood  
1           1           Bagels      10          Meat      
1           1           Bagels      11          Rice/Pasta
1           1           Bagels      12          Sandwiches
1           1           Bagels      13          Seafood   
1           1           Bagels      14          Soup      
1           1           Bagels      15          Vegetables
2           1           Bagels, ra  1           Bakery    
2           1           Bagels, ra  2           Cereal    
...
411         15          Veggie bur  14          Soup      
411         15          Veggie bur  15          Vegetables
412         15          Wax Beans   1           Bakery    
412         15          Wax Beans   2           Cereal    
412         15          Wax Beans   3           Chicken/Fo
412         15          Wax Beans   4           Condiments
412         15          Wax Beans   5           Dairy     
412         15          Wax Beans   6           Dip       
412         15          Wax Beans   7           Drinks    
412         15          Wax Beans   8           Fruit     
412         15          Wax Beans   9           Junkfood  
412         15          Wax Beans   10          Meat      
412         15          Wax Beans   11          Rice/Pasta
412         15          Wax Beans   12          Sandwiches
412         15          Wax Beans   13          Seafood   
412         15          Wax Beans   14          Soup      
412         15          Wax Beans   15          Vegetables
```

#### 外连接 - OUTER JOIN

外连接（OUTER JOIN）是内连接（INNER JOIN）的扩展。虽然 SQL 标准定义了三种类型的外连接：LEFT、RIGHT、FULL，但 SQLite 只支持 左外连接（LEFT OUTER JOIN）。

外连接（OUTER JOIN）声明条件的方法与内连接（INNER JOIN）是相同的，使用 ON、USING 或 NATURAL 关键字来表达。最初的结果表以相同的方式进行计算。一旦主连接计算完成，外连接（OUTER JOIN）将从一个或两个表中任何未连接的行合并进来，外连接的列使用 NULL 值，将它们附加到结果表中。

下面是左外连接（LEFT OUTER JOIN）的语法：

```
SELECT ... FROM table1 LEFT OUTER JOIN table2 ON conditional_expression ...
```

为了避免冗余，并保持较短的措辞，可以使用 USING 表达式声明外连接（OUTER JOIN）条件。这个表达式指定一个或多个列的列表：

```
SELECT ... FROM table1 LEFT OUTER JOIN table2 USING ( column1 ,... ) ...
```

示例SQL语句:
```
sqlite> select *
        from foods left outer join foods_episodes on foods.id=foods_episodes.food_id;
id          type_id     name        food_id     episode_id
----------  ----------  ----------  ----------  ----------
1           1           Bagels      1           165       
2           1           Bagels, ra  2           154       
2           1           Bagels, ra  2           165       
3           1           Bavarian C  3           115       
4           1           Bear Claws  4           67        
4           1           Bear Claws  4           82        
4           1           Bear Claws  4           169       
5           1           Black and   5           76        
...
```

#### 自然连接 - NATURAL JOIN

自然连接（NATURAL JOIN）类似于 JOIN...USING，只是它会自动测试存在两个表中的每一列的值之间相等值：

```
SELECT ... FROM table1 NATURAL JOIN table2...
```

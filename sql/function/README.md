### SQLite 常用函数

SQLite 有许多内置函数用于处理字符串或数字数据。下面列出了一些有用的 SQLite 内置函数，且所有函数都是大小写不敏感，这意味着您可以使用这些函数的小写形式或大写形式或混合形式。

| 序号 | 函数           | 描述                                                                                          |
| ---- | -------------- | --------------------------------------------------------------------------------------------- |
| 1    | COUNT          | COUNT 聚集函数是用来计算一个数据库表中的行数。                                                |
| 2    | MAX            | SQLite MAX 聚合函数允许我们选择某列的最大值。                                                 |
| 3    | MIN            | SQLite MIN 聚合函数允许我们选择某列的最小值。                                                 |
| 4    | AVG            | SQLite AVG 聚合函数计算某列的平均值。                                                         |
| 5    | SUM            | SQLite SUM 聚合函数允许为一个数值列计算总和。                                                 |
| 6    | RANDOM         | SQLite RANDOM 函数返回一个介于 -9223372036854775808 和 +9223372036854775807 之间的伪随机整数。|
| 7    | ABS            | SQLite ABS 函数返回数值参数的绝对值。                                                         |
| 8    | UPPER          | SQLite UPPER 函数把字符串转换为大写字母。                                                     |
| 9    | LOWER          | SQLite LOWER 函数把字符串转换为小写字母。                                                     |
| 10   | LENGTH         | SQLite LENGTH 函数返回字符串的长度。                                                          |
| 11   | sqlite_version | SQLite sqlite_version 函数返回 SQLite 库的版本。                                              |

在我们开始讲解这些函数实例之前，先假设 COMPANY 表有以下记录：

```
ID          NAME        AGE         ADDRESS     SALARY
----------  ----------  ----------  ----------  ----------
1           Paul        32          California  20000.0
2           Allen       25          Texas       15000.0
3           Teddy       23          Norway      20000.0
4           Mark        25          Rich-Mond   65000.0
5           David       27          Texas       85000.0
6           Kim         22          South-Hall  45000.0
7           James       24          Houston     10000.0
```

SQLite COUNT 函数:
SQLite COUNT 聚集函数是用来计算一个数据库表中的行数。下面是实例：

```
sqlite> SELECT count(*) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
count(*)
----------
7
```

SQLite MAX 函数:
SQLite MAX 聚合函数允许我们选择某列的最大值。下面是实例：

```
sqlite> SELECT max(salary) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
max(salary)
-----------
85000.0
```

SQLite MIN 函数:
SQLite MIN 聚合函数允许我们选择某列的最小值。下面是实例：

```
sqlite> SELECT min(salary) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
min(salary)
-----------
10000.0
```

SQLite AVG 函数:
SQLite AVG 聚合函数计算某列的平均值。下面是实例：

```
sqlite> SELECT avg(salary) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
avg(salary)
----------------
37142.8571428572
```

SQLite SUM 函数:
SQLite SUM 聚合函数允许为一个数值列计算总和。下面是实例：

```
sqlite> SELECT sum(salary) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
sum(salary)
-----------
260000.0
```

SQLite RANDOM 函数:
SQLite RANDOM 函数返回一个介于 -9223372036854775808 和 +9223372036854775807 之间的伪随机整数。下面是实例：

```
sqlite> SELECT random() AS Random;
```

上面的 SQLite SQL 语句将产生以下结果：

```
Random
-------------------
5876796417670984050
```

SQLite ABS 函数:
SQLite ABS 函数返回数值参数的绝对值。下面是实例：

```
sqlite> SELECT abs(5), abs(-15), abs(NULL), abs(0), abs("ABC");
```

上面的 SQLite SQL 语句将产生以下结果：

```
abs(5)      abs(-15)    abs(NULL)   abs(0)      abs("ABC")
----------  ----------  ----------  ----------  ----------
5           15                      0           0.0
```

SQLite UPPER 函数:
SQLite UPPER 函数把字符串转换为大写字母。下面是实例：

```
sqlite> SELECT upper(name) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
upper(name)
-----------
PAUL
ALLEN
TEDDY
MARK
DAVID
KIM
JAMES
```

SQLite LOWER 函数:
SQLite LOWER 函数把字符串转换为小写字母。下面是实例：

```
sqlite> SELECT lower(name) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
lower(name)
-----------
paul
allen
teddy
mark
david
kim
james
```

SQLite LENGTH 函数:
SQLite LENGTH 函数返回字符串的长度。下面是实例：

```
sqlite> SELECT name, length(name) FROM COMPANY;
```

上面的 SQLite SQL 语句将产生以下结果：

```
NAME        length(name)
----------  ------------
Paul        4
Allen       5
Teddy       5
Mark        4
David       5
Kim         3
James       5
```

SQLite sqlite_version 函数:
SQLite sqlite_version 函数返回 SQLite 库的版本。下面是实例：

```
sqlite> SELECT sqlite_version() AS 'SQLite Version';
```

上面的 SQLite SQL 语句将产生以下结果：

```
SQLite Version
--------------
3.6.20
```

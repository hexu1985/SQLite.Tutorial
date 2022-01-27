### 获取数据库的Schema信息

启动命令行，通过输入如下命令打开Shell模式的CLP：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite>
```

命令.table [pattern]可以得到所有表和视图的列表，其中[pattern]可以是任何like操作符理解的SQL：

```
sqlite> .tables
schema  test
```

若要显示一个表的索引，可以键入命令.indices [table name]： 

```
sqlite> .indices test
test_idx
```

使用.schema [table name]可以得到一个表或视图的定义语句（DDL: data
definition language）。

```
sqlite> .schema test
CREATE TABLE test (id integer primary key, value text);
CREATE INDEX test_idx on test (value);
```

如果没有提供表名，则返回所有数据库对象（包括table、index、view和triger）的定义语句：

```
sqlite> .schema
CREATE TABLE test (id integer primary key, value text);
CREATE INDEX test_idx on test (value);
CREATE VIEW schema as select * from sqlite_master
/* schema(type,name,tbl_name,rootpage,sql) */;
```



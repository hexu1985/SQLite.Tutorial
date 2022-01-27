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

更详细的schema信息可以通过SQLite的重要系统视图sqlite_master得到。

```
sqlite> .schema sqlite_master
CREATE TABLE sqlite_master (
  type text,
  name text,
  tbl_name text,
  rootpage integer,
  sql text
);
```

sqlite_master表的字段说明

| Name | Description |
| ---- | ----------- |
| type | The object’s type (table, index, view, trigger) |
| name | The object’s name |
| tbl_name | The table the object is associated with |
| rootpage | The object’s root page index in the database (where it begins) |
| sql | The object’s SQL definition (DDL) |

查询当前数据库的sqlite_master表，返回如下内容：

```
sqlite> select type, name, tbl_name, sql from sqlite_master order by type;
type        name        tbl_name    sql
----------  ----------  ----------  -------------------------------------
index       test_idx    test        CREATE INDEX test_idx on test (value)
table       test        test        CREATE TABLE test (id integer primary
view        schema      schema      CREATE VIEW schema as select * from s
```

#### 参考资料:
《SQLite权威指南》: 第2章

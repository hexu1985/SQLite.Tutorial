### SQLite 创建数据库

SQLite 的 sqlite3 命令被用来创建新的 SQLite 数据库。您不需要任何特殊的权限即可创建一个数据。

sqlite3 命令的基本语法如下：

```
$ sqlite3 DatabaseName.db
```

通常情况下，数据库名称在 RDBMS 内应该是唯一的。

另外我们也可以使用 .open 来建立新的数据库文件：

```
sqlite>.open test.db
```

上面的命令创建了数据库文件 test.db，位于 sqlite3 命令同一目录下。

打开已存在数据库也是用 .open 命令，以上命令如果 test.db 存在则直接会打开，不存在就创建它。

如果您想创建一个新的数据库 `<testDB.db>`，SQLITE3 语句如下所示：

```
$ sqlite3 testDB.db
SQLite version 3.7.15.2 2013-01-09 11:53:05
Enter ".help" for instructions
Enter SQL statements terminated with a ";"
sqlite>
```

上面的命令将在当前目录下创建一个文件 testDB.db。该文件将被 SQLite 引擎用作数据库。如果您已经注意到 sqlite3 命令在成功创建数据库文件之后，将提供一个 sqlite> 提示符。

一旦数据库被创建，您就可以使用 SQLite 的 .databases 命令来检查它是否在数据库列表中，如下所示：

```
sqlite>.databases
seq  name             file
---  ---------------  ----------------------
0    main             /home/sqlite/testDB.db
```

我们可以创建一个表:

```
sqlite> create table test (id integer primary key, value text);
```

向表中插入几行数据：

```
sqlite> insert into test (id, value) values(1, 'eenie');
sqlite> insert into test (id, value) values(2, 'meenie');
sqlite> insert into test (value) values('miny');
sqlite> insert into test (value) values('mo');
```

查询表中的数据：

```
sqlite> .mode column
sqlite> .headers on
sqlite> select * from test;
id          value
----------  ----------
1           eenie
2           meenie
3           miny
4           mo
```

使用SQL函数last_insert_rowid()获得最后插入的自动增量值：

```
sqlite> select last_insert_rowid();
last_insert_rowid()
-------------------
4
```

添加索引和视图：

```
sqlite> create index test_idx on test (value);
sqlite> create view schema as select * from sqlite_master;
```

使用.exit命令退出Shell：

```
sqlite> .exit
```

您也可以使用 SQLite .quit 命令退出 sqlite 提示符，如下所示：

```
sqlite>.quit
$
```

.dump 命令

您可以在命令提示符中使用 SQLite .dump 点命令来导出完整的数据库在一个文本文件中，如下所示：

```
$sqlite3 testDB.db .dump > testDB.sql
```

上面的命令将转换整个 testDB.db 数据库的内容到 SQLite 的语句中，并将其转储到 ASCII 文本文件 testDB.sql 中。您可以通过简单的方式从生成的 testDB.sql 恢复，如下所示：

```
$sqlite3 testDB.db < testDB.sql
```




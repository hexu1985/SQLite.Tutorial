### 创建数据库

从创建名为test.db的数据库开始。启动命令行，通过输入如下命令打开Shell模式的CLP：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite>
```

创建一个表，从Shell中启动如下语句：

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

#### 参考资料:
《SQLite权威指南》: 第2章

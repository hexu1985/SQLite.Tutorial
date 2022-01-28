### 导入数据

.read命令用来导入.dump命令创建的文件。

```
$ sqlite3 test2.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .read file.sql
sqlite> .headers on
sqlite> .mode column
sqlite> select * from test;
id          value
----------  ----------
1           eenie
2           meenie
3           miny
4           mo
```

如果使用前面作为备份文件所导出的file.sql，需要先移除已经存在的数据库对象（test表和schema视图），然后用下面的方法重新导入：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> drop table test;
sqlite> drop view schema;
sqlite> .read file.sql
sqlite> .headers on
sqlite> .mode column
sqlite> select * from test;
id          value
----------  ----------
1           eenie
2           meenie
3           miny
4           mo
```

对于test.db，如果重复导入file.sql，会提示如下错误：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .read file.sql
Error: near line 3: table test already exists
Error: near line 4: UNIQUE constraint failed: test.id
Error: near line 5: UNIQUE constraint failed: test.id
Error: near line 6: UNIQUE constraint failed: test.id
Error: near line 7: UNIQUE constraint failed: test.id
Error: near line 8: index test_idx already exists
Error: near line 9: table schema already exists
```

#### 参考资料:
《SQLite权威指南》: 第2章

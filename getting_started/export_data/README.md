### 导出数据

使用.dump命令可以将数据库对象导出成SQL格式。

在Shell模式中，默认情况下，.dump命令的输出定向到屏幕。如果您想要将输出重定向到文件，请使用.output [filename]命令，此命令将所有的输出重定向到指定的文件中。若要恢复输出到屏幕，只需要执行.output stdout。

例如，要将当前数据库（test.db）导出到文件file.sql，可以输入如下命令:

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .output file.sql
sqlite> .dump
sqlite> .output stdout
```

导出的file.sql长这样：

```
PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE test (id integer primary key, value text);
INSERT INTO test VALUES(1,'eenie');
INSERT INTO test VALUES(2,'meenie');
INSERT INTO test VALUES(3,'miny');
INSERT INTO test VALUES(4,'mo');
CREATE INDEX test_idx on test (value);
CREATE VIEW schema as select * from sqlite_master;
COMMIT;
```

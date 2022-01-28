### 导入CSV格式数据

首先，我们将test表中以字母m开始的值导出并以逗号分隔，导出到test.csv文件：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .output text.csv
sqlite> .separator ,
sqlite> select * from test where value like 'm%';
sqlite> .output stdout
```

然后，我们将CSV数据导入到与test表结构类似的表（称为test2），可以执行下列操作：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> create table test2(id integer primary key, value text);
sqlite> .separator ,
sqlite> .import text.csv test2
sqlite> select * from test2;
2,meenie
3,miny
4,mo
```

注意，.import [file] [table]命令，默认是通过管道字符（`|`）作为分隔符解析文件中的每一行，并将已分析的列插入到表中。所以，需要通过.separator命令将分隔符指定为逗号（`,`）。

使用.show命令，可以查询用户Shell中定义的所有设置。

```
$ sqlite3
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
sqlite> .show
        echo: off
         eqp: off
     explain: auto
     headers: off
        mode: list
   nullvalue: ""
      output: stdout
colseparator: "|"
rowseparator: "\n"
       stats: off
       width:
    filename: :memory:
```


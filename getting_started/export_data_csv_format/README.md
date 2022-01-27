### 导出数据格式化

.mode命令可以设置结果数据的几种输出格式。可选的格式有csv、column、html、insert、line、list、tabs和tcl，每种格式都用不同的用途。默认值是list，list模式下显示结果集时列间以默认的分割符分割。

如果想以CSV格式输出一个表的数据，可进行如下操作：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .output file.csv
sqlite> .separator ,
sqlite> select * from test;
sqlite> .output stdout
```

文件file.csv的内容如下所示：

```
1,eenie
2,meenie
3,miny
4,mo
```

另外可以使用Shell中已定义的CSV模式导出数据：

```
.output file.csv
.mode csv
select * from test;
.output stdout
```

得到的结果是相同的。

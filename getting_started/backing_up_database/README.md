### 备份数据库

有两种方式可以完成数据库的备份：
- SQL转储
- 备份二进制文件

生成转储的标准方式是使用CLP的.dump命令。从命令行可以这样做，如下所示：

```
$ sqlite3 test.db .dump > test.sql
```

在Shell中，可以将输出重定向到外部文件，执行命令，恢复屏幕输出，如下所示：

```
$ sqlite3 test.db
SQLite version 3.31.1 2020-01-27 19:55:54
Enter ".help" for usage hints.
sqlite> .output test.sql
sqlite> .dump
sqlite> .output stdout
sqlite> .exit
```

同样，容易将SQL转储作为CLP的输入流实现数据库导入：

```
$ sqlite3 test.db < test.sql
```

备份二进制数据库只是比复制文件稍多做一点工作。备份之前需要清理数据库，这样可以释放一些已删除对象不再使用的空间。这数据库文件就会变小，因此，二进制的副本也会较小：

```
$ sqlite3 test.db vacumm
$ cp test.db test.backup
```

#### 参考资料:
《SQLite权威指南》: 第2章

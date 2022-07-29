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

您可以使用 SQLite .quit 命令退出 sqlite 提示符，如下所示：

```
sqlite>.quit
$
```


### 命令行模式的CLP（Command Line Program）

你可以从命令行使用CLP，执行如导入/导出数据、返回结果集和一般的批处理工作。
使用Shell脚本来自动管理数据库是理想的使用方式。从Shell上启动CLP -help，可以看到CLP在命令行模式下提供了什么功能。

```
$ sqlite3 -help
Usage: sqlite3 [OPTIONS] FILENAME [SQL]
FILENAME is the name of an SQLite database. A new database is created
if the file does not previously exist.
OPTIONS include:
   -A ARGS...           run ".archive ARGS" and exit
   -append              append the database to the end of the file
   -ascii               set output mode to 'ascii'
   -bail                stop after hitting an error
   -batch               force batch I/O
   -column              set output mode to 'column'
   -cmd COMMAND         run "COMMAND" before reading stdin
   -csv                 set output mode to 'csv'
   -deserialize         open the database using sqlite3_deserialize()
   -echo                print commands before execution
   -init FILENAME       read/process named file
   -[no]header          turn headers on or off
   -help                show this message
   -html                set output mode to HTML
   -interactive         force interactive I/O
   -line                set output mode to 'line'
   -list                set output mode to 'list'
   -lookaside SIZE N    use N entries of SZ bytes for lookaside memory
   -maxsize N           maximum size for a --deserialize database
   -memtrace            trace all memory allocations and deallocations
   -mmap N              default mmap size set to N
   -newline SEP         set output row separator. Default: '\n'
   -nofollow            refuse to open symbolic links to database files
   -nullvalue TEXT      set text string for NULL values. Default ''
   -pagecache SIZE N    use N slots of SZ bytes each for page cache memory
   -quote               set output mode to 'quote'
   -readonly            open the database read-only
   -separator SEP       set output column separator. Default: '|'
   -stats               print memory stats before each finalize
   -version             show SQLite version
   -vfs NAME            use NAME as the default VFS
   -zip                 open the file as a ZIP Archive
```

命令行中的CLP可以接受以下参数：
- 可选列表（可选的）
- 数据库文件名（可选的）
- 要执行的SQL命令（可选的）

从命令行转存test.db数据库，执行以下命令：

```
$ sqlite3 test.db .dump
```

可以通过输出重定向到文件：

```
$ sqlite3 test.db .dump > test.sql
```

若要选择test表的所有记录，执行如下命令：

```
$ sqlite3 test.db "select * from test"
```

第二种在命令行模式中调用CLP的方法是将定向到的一个文件作为输入流。例如，若要从数据库dump文件test.sql中创建新的数据库test2.db，执行以下操作：

```
$ sqlite3 test2.db < test.sql
```

从test.sql文件创建数据库的另一种方式是使用init选项，并将test.sql作为参数：

```
$ sqlite3 -init test.sql test3.db .exit
```

#### 参考资料:
《SQLite权威指南》: 第2章

### 连接数据库

下面的 Python 代码显示了如何连接到一个现有的数据库。如果数据库不存在，那么它就会被创建，最后将返回一个数据库对象。

实例
```
#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('test.db')

print ("数据库打开成功")
```

在这里，您也可以把数据库名称复制为特定的名称 :memory:，这样就会在 RAM 中创建一个数据库。现在，让我们来运行上面的程序，在当前目录中创建我们的数据库 test.db。您可以根据需要改变路径。保存上面代码到 sqlite.py 文件中，并按如下所示执行。如果数据库成功创建，那么会显示下面所示的消息：

```
$chmod +x sqlite.py
$./sqlite.py
Open database successfully
```

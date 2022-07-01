### 创建表
下面的 Python 代码段将用于在先前创建的数据库中创建一个表：

实例
```
#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('test.db')
print ("数据库打开成功")
c = conn.cursor()
c.execute('''CREATE TABLE COMPANY
       (ID INT PRIMARY KEY     NOT NULL,
       NAME           TEXT    NOT NULL,
       AGE            INT     NOT NULL,
       ADDRESS        CHAR(50),
       SALARY         REAL);''')
print ("数据表创建成功")
conn.commit()
conn.close()
```
上述程序执行时，它会在 test.db 中创建 COMPANY 表，并显示下面所示的消息：

```
数据库打开成功
数据表创建成功
```

#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
print ("数据库打开成功")
cur = conn.cursor()
cur.execute('''CREATE TABLE COMPANY
       (ID INT PRIMARY KEY     NOT NULL,
       NAME           TEXT    NOT NULL,
       AGE            INT     NOT NULL,
       ADDRESS        CHAR(50),
       SALARY         REAL);''')
print ("数据表创建成功")
conn.commit()
conn.close()

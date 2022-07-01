#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
print ("数据库打开成功")
cur = conn.cursor()
cur.execute('''DROP TABLE COMPANY;''')
print ("数据表删除成功")
conn.commit()
conn.close()

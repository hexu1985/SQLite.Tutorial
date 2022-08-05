#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
cur = conn.cursor()
print ("数据库打开成功")

cur.execute("DELETE from COMPANY where ID=:id;", {"id":1})
conn.commit()
print("Total number of rows deleted : {}".format(conn.total_changes))

print ("数据操作成功")
conn.close()

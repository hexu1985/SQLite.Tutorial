#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
cur = conn.cursor()
print ("数据库打开成功")

cur.execute("UPDATE COMPANY set SALARY = 25000.00 where ID=1")
conn.commit()
print("Total number of rows updated : {}".format(conn.total_changes))

cursor = conn.execute("SELECT id, name, address, salary  from COMPANY")
for row in cursor:
   print("ID = {}".format(row[0]))
   print("NAME = {}".format(row[1]))
   print("ADDRESS = {}".format(row[2]))
   print("SALARY = {}".format(row[3]))
   print("")

print ("数据操作成功")
conn.close()

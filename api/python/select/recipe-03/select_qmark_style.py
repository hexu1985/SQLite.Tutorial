#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
cur = conn.cursor()
print ("数据库打开成功")

cursor = cur.execute("SELECT id, name, address, salary from COMPANY where SALARY < ?", (30000,))
for row in cursor:
   print("ID = {}".format(row[0]))
   print("NAME = {}".format(row[1]))
   print("ADDRESS = {}".format(row[2]))
   print("SALARY = {}".format(row[3]))
   print("")

print ("数据操作成功")
conn.close()

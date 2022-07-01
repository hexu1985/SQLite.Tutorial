#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
cur = conn.cursor()
print ("数据库打开成功")

cursor = cur.execute("SELECT id, name, address, salary from COMPANY")
for row in cursor:
    for field in row:
        print("'{}' ".format(field), end="")
    print("")

print ("数据操作成功")
conn.close()

#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import sqlite3

conn = sqlite3.connect('test.db')
cur = conn.cursor()
print ("数据库打开成功")

employee_list = [
        (1, 'Paul', 32, 'California', 20000.00 ),
        (2, 'Allen', 25, 'Texas', 15000.00 ),
        (3, 'Teddy', 23, 'Norway', 20000.00 ),
        (4, 'Mark', 25, 'Rich-Mond ', 65000.00 ),
        ]

cur.executemany("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (?, ?, ?, ?, ?)", employee_list)

conn.commit()
print ("数据插入成功")
conn.close()

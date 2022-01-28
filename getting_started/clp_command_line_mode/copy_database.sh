#!/usr/bin/env bash

sqlite3 test.db .dump > test.sql
sqlite3 test2.db < test.sql

### 创建数据库表

创建数据库表的语法如下:

```
create [temp] table table_name (column_definitions [, constraints]);
```

数据库示例, 表结构如下:

![food database](food_database.png)

SQL语句:

```
create table episodes (
  id integer primary key,
  season int,
  name text );

create table foods(
  id integer primary key,
  type_id integer,
  name text );

create table food_types(
  id integer primary key,
  name text );

create table foods_episodes(
  food_id integer,
  episode_id integer );
```

从命令行创建数据库表:

```
$ sqlite3 foods.db < foods.sql
```

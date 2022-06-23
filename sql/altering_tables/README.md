### 修改数据库表

修改数据库表的语法如下:

```
alter table table { rename to name | add column column_def }
```


示例SQL语句:

```
sqlite> create table contacts ( id integer primary key,
                        name text not null collate nocase,
                        phone text not null default 'UNKNOWN',
                        unique (name,phone) );

sqlite> alter table contacts
        add column email text not null default '' collate nocase;

sqlite> .schema contacts

create table contacts ( id integer primary key,
                        name text not null collate nocase,
                        phone text not null default 'UNKNOWN',
                        email text not null default '' collate nocase,
                        unique (name,phone) );

```


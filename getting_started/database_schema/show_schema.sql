.echo on

.tables

.indices test

.schema test

.schema

.schema sqlite_master

.mode column
.headers on
select type, name, tbl_name, sql from sqlite_master order by type;



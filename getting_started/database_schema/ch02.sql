.tables

.indices test

.schema test

.schema

.mode column
.headers on
select type, name, tbl_name, sql from sqlite_master order by type;



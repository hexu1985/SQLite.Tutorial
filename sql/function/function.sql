
.echo on
.mode column
.headers on
.nullvalue NULL

SELECT count(*) FROM COMPANY;

SELECT max(salary) FROM COMPANY;

SELECT min(salary) FROM COMPANY;

SELECT avg(salary) FROM COMPANY;

SELECT sum(salary) FROM COMPANY;

SELECT random() AS Random;

SELECT abs(5), abs(-15), abs(NULL), abs(0), abs("ABC");

SELECT upper(name) FROM COMPANY;

SELECT lower(name) FROM COMPANY;

SELECT name, length(name) FROM COMPANY;

SELECT sqlite_version() AS 'SQLite Version';

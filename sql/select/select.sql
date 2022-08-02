.echo on

SELECT * FROM COMPANY;

.header on
.mode column
SELECT * FROM COMPANY;

SELECT ID, NAME, SALARY FROM COMPANY;

.width 10, 20, 10
SELECT * FROM COMPANY;

SELECT tbl_name FROM sqlite_master WHERE type = 'table';

.header off
.width 0, 0, 0
SELECT sql FROM sqlite_master WHERE type = 'table' AND tbl_name = 'COMPANY';

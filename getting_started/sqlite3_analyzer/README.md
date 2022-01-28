### 通过sqlite3_analyzer获取数据库文件的信息

sqlite3_analyzer提供有关SQLite数据库磁盘结构的详细技术信息，这些信息包括数据库、表和索引分类的单个对象，以及聚合的统计信息。它提供从数据库属性如页面大小、表的总数、索引、文件大小和页面平均密度（利用率）到单个数据库对象的详细说明等信息。

sqlite3_analyzer的输出信息如下：

```
$ sqlite3_analyzer test.db
/** Disk-Space Utilization Report For test.db

Page size in bytes................................ 4096
Pages in the whole file (measured)................ 3
Pages in the whole file (calculated).............. 3
Pages that store data............................. 3          100.0%
Pages on the freelist (per header)................ 0            0.0%
Pages on the freelist (calculated)................ 0            0.0%
Pages of auto-vacuum overhead..................... 0            0.0%
Number of tables in the database.................. 2
Number of indices................................. 1
Number of defined indices......................... 1
Number of implied indices......................... 0
Size of the file in bytes......................... 12288
Bytes of user payload stored...................... 29           0.24%

*** Page counts for all tables with their indices *****************************

TEST.............................................. 2           66.7%
SQLITE_MASTER..................................... 1           33.3%

*** Page counts for all tables and indices separately *************************

SQLITE_MASTER..................................... 1           33.3%
TEST.............................................. 1           33.3%
TEST_IDX.......................................... 1           33.3%

*** All tables and indices ****************************************************

Percentage of total database...................... 100.0%
Number of entries................................. 11
Bytes of storage consumed......................... 12288
Bytes of payload.................................. 267          2.2%
Average payload per entry......................... 24.27
Average unused bytes per entry.................... 1077.91
Maximum payload per entry......................... 74
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 3
Overflow pages used............................... 0
Total pages used.................................. 3
Unused bytes on primary pages..................... 11857       96.5%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 11857       96.5%

*** All tables ****************************************************************

Percentage of total database......................  66.7%
Number of entries................................. 7
Bytes of storage consumed......................... 8192
Bytes of payload.................................. 235          2.9%
Average payload per entry......................... 33.57
Average unused bytes per entry.................... 1116.14
Maximum payload per entry......................... 74
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 2
Overflow pages used............................... 0
Total pages used.................................. 2
Unused bytes on primary pages..................... 7813        95.4%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 7813        95.4%

*** All indices ***************************************************************

Percentage of total database......................  33.3%
Number of entries................................. 4
Bytes of storage consumed......................... 4096
Bytes of payload.................................. 32           0.78%
Average payload per entry......................... 8.00
Average unused bytes per entry.................... 1011.00
Maximum payload per entry......................... 10
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 1
Overflow pages used............................... 0
Total pages used.................................. 1
Unused bytes on primary pages..................... 4044        98.7%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 4044        98.7%

*** Table SQLITE_MASTER *******************************************************

Percentage of total database......................  33.3%
Number of entries................................. 3
Bytes of storage consumed......................... 4096
Bytes of payload.................................. 206          5.0%
Average payload per entry......................... 68.67
Average unused bytes per entry.................... 1256.67
Maximum payload per entry......................... 74
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 1
Overflow pages used............................... 0
Total pages used.................................. 1
Unused bytes on primary pages..................... 3770        92.0%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 3770        92.0%

*** Table TEST and all its indices ********************************************

Percentage of total database......................  66.7%
Number of entries................................. 8
Bytes of storage consumed......................... 8192
Bytes of payload.................................. 61           0.74%
Average payload per entry......................... 7.62
Average unused bytes per entry.................... 1010.88
Maximum payload per entry......................... 10
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 2
Overflow pages used............................... 0
Total pages used.................................. 2
Unused bytes on primary pages..................... 8087        98.7%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 8087        98.7%

*** Table TEST w/o any indices ************************************************

Percentage of total database......................  33.3%
Number of entries................................. 4
Bytes of storage consumed......................... 4096
Bytes of payload.................................. 29           0.71%
Average payload per entry......................... 7.25
Average unused bytes per entry.................... 1010.75
Maximum payload per entry......................... 9
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 1
Overflow pages used............................... 0
Total pages used.................................. 1
Unused bytes on primary pages..................... 4043        98.7%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 4043        98.7%

*** Index TEST_IDX of table TEST **********************************************

Percentage of total database......................  33.3%
Number of entries................................. 4
Bytes of storage consumed......................... 4096
Bytes of payload.................................. 32           0.78%
Average payload per entry......................... 8.00
Average unused bytes per entry.................... 1011.00
Maximum payload per entry......................... 10
Entries that use overflow......................... 0            0.0%
Primary pages used................................ 1
Overflow pages used............................... 0
Total pages used.................................. 1
Unused bytes on primary pages..................... 4044        98.7%
Unused bytes on overflow pages.................... 0
Unused bytes on all pages......................... 4044        98.7%

*** Definitions ***************************************************************

Page size in bytes

    The number of bytes in a single page of the database file.
    Usually 1024.

Number of pages in the whole file

    The number of 4096-byte pages that go into forming the complete
    database

Pages that store data

    The number of pages that store data, either as primary B*Tree pages or
    as overflow pages.  The number at the right is the data pages divided by
    the total number of pages in the file.

Pages on the freelist

    The number of pages that are not currently in use but are reserved for
    future use.  The percentage at the right is the number of freelist pages
    divided by the total number of pages in the file.

Pages of auto-vacuum overhead

    The number of pages that store data used by the database to facilitate
    auto-vacuum. This is zero for databases that do not support auto-vacuum.

Number of tables in the database

    The number of tables in the database, including the SQLITE_MASTER table
    used to store schema information.

Number of indices

    The total number of indices in the database.

Number of defined indices

    The number of indices created using an explicit CREATE INDEX statement.

Number of implied indices

    The number of indices used to implement PRIMARY KEY or UNIQUE constraints
    on tables.

Size of the file in bytes

    The total amount of disk space used by the entire database files.

Bytes of user payload stored

    The total number of bytes of user payload stored in the database. The
    schema information in the SQLITE_MASTER table is not counted when
    computing this number.  The percentage at the right shows the payload
    divided by the total file size.

Percentage of total database

    The amount of the complete database file that is devoted to storing
    information described by this category.

Number of entries

    The total number of B-Tree key/value pairs stored under this category.

Bytes of storage consumed

    The total amount of disk space required to store all B-Tree entries
    under this category.  The is the total number of pages used times
    the pages size.

Bytes of payload

    The amount of payload stored under this category.  Payload is the data
    part of table entries and the key part of index entries.  The percentage
    at the right is the bytes of payload divided by the bytes of storage
    consumed.

Average payload per entry

    The average amount of payload on each entry.  This is just the bytes of
    payload divided by the number of entries.

Average unused bytes per entry

    The average amount of free space remaining on all pages under this
    category on a per-entry basis.  This is the number of unused bytes on
    all pages divided by the number of entries.

Non-sequential pages

    The number of pages in the table or index that are out of sequence.
    Many filesystems are optimized for sequential file access so a small
    number of non-sequential pages might result in faster queries,
    especially for larger database files that do not fit in the disk cache.
    Note that after running VACUUM, the root page of each table or index is
    at the beginning of the database file and all other pages are in a
    separate part of the database file, resulting in a single non-
    sequential page.

Maximum payload per entry

    The largest payload size of any entry.

Entries that use overflow

    The number of entries that user one or more overflow pages.

Total pages used

    This is the number of pages used to hold all information in the current
    category.  This is the sum of index, primary, and overflow pages.

Index pages used

    This is the number of pages in a table B-tree that hold only key (rowid)
    information and no data.

Primary pages used

    This is the number of B-tree pages that hold both key and data.

Overflow pages used

    The total number of overflow pages used for this category.

Unused bytes on index pages

    The total number of bytes of unused space on all index pages.  The
    percentage at the right is the number of unused bytes divided by the
    total number of bytes on index pages.

Unused bytes on primary pages

    The total number of bytes of unused space on all primary pages.  The
    percentage at the right is the number of unused bytes divided by the
    total number of bytes on primary pages.

Unused bytes on overflow pages

    The total number of bytes of unused space on all overflow pages.  The
    percentage at the right is the number of unused bytes divided by the
    total number of bytes on overflow pages.

Unused bytes on all pages

    The total number of bytes of unused space on all primary and overflow
    pages.  The percentage at the right is the number of unused bytes
    divided by the total number of bytes.

*******************************************************************************
The entire text of this report can be sourced into any SQL database
engine for further analysis.  All of the text above is an SQL comment.
The data used to generate this report follows:
*/
BEGIN;
CREATE TABLE space_used(
   name clob,        -- Name of a table or index in the database file
   tblname clob,     -- Name of associated table
   is_index boolean, -- TRUE if it is an index, false for a table
   nentry int,       -- Number of entries in the BTree
   leaf_entries int, -- Number of leaf entries
   payload int,      -- Total amount of data stored in this table or index
   ovfl_payload int, -- Total amount of data stored on overflow pages
   ovfl_cnt int,     -- Number of entries that use overflow
   mx_payload int,   -- Maximum payload size
   int_pages int,    -- Number of interior pages used
   leaf_pages int,   -- Number of leaf pages used
   ovfl_pages int,   -- Number of overflow pages used
   int_unused int,   -- Number of unused bytes on interior pages
   leaf_unused int,  -- Number of unused bytes on primary pages
   ovfl_unused int,  -- Number of unused bytes on overflow pages
   gap_cnt int,      -- Number of gaps in the page layout
   compressed_size int  -- Total bytes stored on disk
);
INSERT INTO space_used VALUES('sqlite_master','sqlite_master',0,3,3,206,0,0,74,0,1,0,0,3770,0,0,4096);
INSERT INTO space_used VALUES('test','test',0,4,4,29,0,0,9,0,1,0,0,4043,0,0,4096);
INSERT INTO space_used VALUES('test_idx','test',1,4,4,32,0,0,10,0,1,0,0,4044,0,0,4096);
COMMIT;
```

如何在Ubuntu上安装sqlite3_analyzer

```
$ sudo apt-get install -y tcl8.6-dev:i386
$ wget -c "http://www.sqlite.org/2013/sqlite-analyzer-linux-x86-3080200.zip"
$ unzip sqlite-analyzer-linux-x86-3080200.zip
$ sudo mv sqlite3_analyzer /usr/local/bin/
```

#### 参考资料:
《SQLite权威指南》: 第2章
[〖Linux〗Ubuntu 64位安装sqlite3_analyzer](https://www.cnblogs.com/scue/p/3535231.html)

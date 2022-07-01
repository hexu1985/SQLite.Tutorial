#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void transaction_begin(sqlite3 *db)
{
    sqlite3_exec(db, "BEGIN", NULL, NULL, NULL);
}

void transaction_commit(sqlite3 *db)
{
    sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
}

void transaction_rollback(sqlite3 *db)
{
    sqlite3_exec(db, "ROLLBACK", NULL, NULL, NULL);
}

int exec_insert(sqlite3 *db, const char *sql)
{
    int rc;
    char *zErr;
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);

    if (rc != SQLITE_OK) {
        if (zErr != NULL) {
            fprintf(stderr, "SQL error: %s\n", zErr);
            sqlite3_free(zErr);
        }
    }
    return rc;
}

#define EXEC_INSERT(db, sql) \
    do { \
        if (exec_insert(db, sql) != SQLITE_OK) \
            goto exec_rollback; \
    } while (0)

int main()
{
    sqlite3 *db;
    int rc;

    rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("数据库打开成功\n");

    transaction_begin(db);

    EXEC_INSERT(db ,"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (1, 'Paul', 32, 'California', 20000.00 );");
    EXEC_INSERT(db ,"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (2, 'Allen', 25, 'Texas', 15000.00 );");
    EXEC_INSERT(db ,"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );");
    EXEC_INSERT(db ,"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );");

    EXEC_INSERT(db ,"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (1, 'Paul', 32, 'California', 20000.00 );");

    transaction_commit(db);
    sqlite3_close(db);
    return 0;

exec_rollback:
    transaction_rollback(db);
    sqlite3_close(db);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    int rc;
    sqlite3_stmt *stmt;
    char *sql;
    const char *tail;

    rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("数据库打开成功\n");

    sql = "UPDATE COMPANY set SALARY=? where ID=?";

    rc = sqlite3_prepare(db, sql, (int)strlen(sql), &stmt, &tail);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", tail);
        sqlite3_close(db);
        exit(1);
    } 

    sqlite3_bind_double(stmt, 1, 25000);
    sqlite3_bind_int(stmt, 2, 1);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    printf("Total number of rows updated : %d\n", sqlite3_changes(db));

    printf("数据操作成功\n");

    sqlite3_close(db);

    return 0;
}


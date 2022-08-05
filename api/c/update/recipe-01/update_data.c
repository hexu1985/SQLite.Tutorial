#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    char *zErr;
    int rc;
    char *sql;

    rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE, NULL);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("数据库打开成功\n");

    sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1";

    rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);

    if (rc != SQLITE_OK) {
        if (zErr != NULL) {
            fprintf(stderr, "SQL error: %s\n", zErr);
            sqlite3_free(zErr);
        }
    } else {
        printf("Total number of rows updated : %d\n", sqlite3_changes(db));
    }

    printf("数据操作成功\n");

    sqlite3_close(db);

    return 0;
}


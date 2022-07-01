#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main()
{
    sqlite3 *db;
    char *zErr;
    int rc;
    char *sql;

    rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("数据库打开成功\n");

    sql = "CREATE TABLE COMPANY "
          "(ID      INT     PRIMARY KEY   NOT NULL, "
          "NAME     TEXT    NOT NULL, "
          "AGE      INT     NOT NULL, "
          "ADDRESS  CHAR(50), "
          "SALARY   REAL);";
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);

    if (rc != SQLITE_OK) {
        if (zErr != NULL) {
            fprintf(stderr, "SQL error: %s\n", zErr);
            sqlite3_free(zErr);
        }
    } else {
        printf("数据表创建成功\n");
    }

    sqlite3_close(db);

    return 0;
}


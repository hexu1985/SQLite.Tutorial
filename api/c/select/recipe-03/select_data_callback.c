#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int callback(void* data, int ncols, char** values, char** headers);

int main()
{
    sqlite3 *db;
    char *zErr;
    int rc;
    char *sql;
	char* data;

    rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    printf("数据库打开成功\n");

    data = "Callback function called";
    sql = "SELECT id, name, address, salary from COMPANY;";

    rc = sqlite3_exec(db, sql, callback, data, &zErr);

    if (rc != SQLITE_OK) {
        if (zErr != NULL) {
            fprintf(stderr, "SQL error: %s\n", zErr);
            sqlite3_free(zErr);
        }
    } else {
        printf("数据操作成功\n");
    }

    sqlite3_close(db);

    return 0;
}

int callback(void* data, int ncols, char** values, char** headers)
{
    int i;
    //fprintf(stderr, "%s: \n", (const char*)data);
    for(i=0; i < ncols; i++) {
        fprintf(stderr, "%s = %s\n", headers[i], values[i]);
    }

    fprintf(stderr, "\n");
    return 0;
}

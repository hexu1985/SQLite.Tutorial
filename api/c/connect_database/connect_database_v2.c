#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

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
    sqlite3_close(db);

    return 0;
}


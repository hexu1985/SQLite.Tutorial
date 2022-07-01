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

    sql = "DELETE from COMPANY where ID=:id;";

    rc = sqlite3_prepare(db, sql, (int)strlen(sql), &stmt, &tail);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", tail);
        goto close_db;
    } 

    sqlite3_bind_int(stmt, sqlite3_bind_parameter_index(stmt, ":id"), 1);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    printf("Total number of rows deleted : %d\n", sqlite3_changes(db));

    sql = "SELECT id, name, address, salary from COMPANY;";

    rc = sqlite3_prepare(db, sql, (int)strlen(sql), &stmt, &tail);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        goto close_db;
    }
    
    rc = sqlite3_step(stmt);
    while(rc == SQLITE_ROW) {
        fprintf(stderr, "ID = %s\n", sqlite3_column_text(stmt, 0));
        fprintf(stderr, "NAME = %s\n", sqlite3_column_text(stmt, 1));
        fprintf(stderr, "ADDRESS = %s\n", sqlite3_column_text(stmt, 2));
        fprintf(stderr, "SALARY = %s\n", sqlite3_column_text(stmt, 3));
        fprintf(stderr, "\n");

        rc = sqlite3_step(stmt);
    }

    printf("数据操作成功\n");

    sqlite3_finalize(stmt);

close_db:

    sqlite3_close(db);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void reset_bind_exec(sqlite3_stmt *stmt, int id, const char *name, int age, const char *address, double salary)
{
    sqlite3_reset(stmt);
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, name, strlen(name), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_text(stmt, 4, address, strlen(address), SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 5, salary);
    sqlite3_step(stmt);
} 

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

    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (?, ?, ?, ?, ?)";

    rc = sqlite3_prepare(db, sql, (int)strlen(sql), &stmt, &tail);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", tail);
        goto close_db;
    } 

    reset_bind_exec(stmt, 1, "Paul", 32, "California", 20000.00);

    reset_bind_exec(stmt, 2, "Allen", 25, "Texas", 15000.00);

    reset_bind_exec(stmt, 3, "Teddy", 23, "Norway", 20000.00);

    reset_bind_exec(stmt, 4, "Mark", 25, "Rich-Mond ", 65000.00);

    sqlite3_finalize(stmt);

    printf("数据插入成功\n");

close_db:

    sqlite3_close(db);

    return 0;
}


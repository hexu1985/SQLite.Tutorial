#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    db.exec("DROP TABLE COMPANY;");

    printf("数据表删除成功\n");

    return 0;
}


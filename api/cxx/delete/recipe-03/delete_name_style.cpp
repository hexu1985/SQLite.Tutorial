
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    SQLite::Statement qry(db, "DELETE from COMPANY where ID=:id;");
    qry.bind(":id", 1);
    qry.exec();
    printf("Total number of rows deleted : %d\n", qry.getChanges());

    printf("数据操作成功\n");

    return 0;
}


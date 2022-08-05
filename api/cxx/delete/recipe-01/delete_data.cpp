#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE);
    printf("数据库打开成功\n");

    db.exec("DELETE from COMPANY where ID=2;");
    printf("Total number of rows deleted : %d\n", db.getChanges());

    printf("数据操作成功\n");

    return 0;
}


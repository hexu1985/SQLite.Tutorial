#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    db.exec("UPDATE COMPANY set SALARY = 25000.00 where ID=1");
    printf("Total number of rows updated : %d\n", db.getChanges());

    printf("数据操作成功\n");

    return 0;
}


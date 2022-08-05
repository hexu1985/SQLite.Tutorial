#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE);
    printf("数据库打开成功\n");

    SQLite::Statement qry(db, "DELETE from COMPANY where ID=?;");
    qry.bind(1, 3);
    qry.exec();
    printf("Total number of rows deleted : %d\n", qry.getChanges());

    printf("数据操作成功\n");

    return 0;
}



#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/ExecuteMany.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    SQLite::Statement qry(db, "UPDATE COMPANY set SALARY=? where ID=?");
    bind_exec(qry, std::make_tuple(25000.00, 1));
    printf("Total number of rows updated : %d\n", qry.getChanges());

    printf("数据操作成功\n");

    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/Transaction.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    {
        SQLite::Transaction transaction(db);

        db.exec("DROP TABLE COMPANY;");

        transaction.commit();

        printf("数据表删除成功\n");
    }

    return 0;
}


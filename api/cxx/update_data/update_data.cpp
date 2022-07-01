
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    db.exec("UPDATE COMPANY set SALARY = 25000.00 where ID=1");
    printf("Total number of rows updated : %d\n", db.getChanges());

    SQLite::Statement query(db, "SELECT id, name, address, salary from COMPANY");
    while (query.executeStep()) {
        std::cout << "ID = " << query.getColumn(0) << "\n";
        std::cout << "NAME = " << query.getColumn(1) << "\n";
        std::cout << "ADDRESS = " << query.getColumn(2) << "\n";
        std::cout << "SALARY = " << query.getColumn(3) << "\n";
        std::cout << std::endl;
    }

    printf("数据操作成功\n");

    return 0;
}


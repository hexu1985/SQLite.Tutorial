
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    printf("数据库打开成功\n");

    SQLite::Statement query(db, "SELECT id, name, address, salary from COMPANY");
    int ncols = query.getColumnCount();
    while (query.executeStep()) {
        for(int i=0; i < ncols; i++) {
            std::cout << "'" << query.getColumn(i) << "' ";
        }
        std::cout << std::endl;
    }

    printf("数据操作成功\n");

    return 0;
}


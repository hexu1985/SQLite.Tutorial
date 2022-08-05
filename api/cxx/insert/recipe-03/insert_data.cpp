#include <cstdio>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/ExecuteMany.h>

int main()
{
    SQLite::Database db("test.db", SQLite::OPEN_READWRITE);
    printf("数据库打开成功\n");

    execute_many(db, 
            "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (?, ?, ?, ?, ?)",
            std::make_tuple(1, "Paul", 32, "California", 20000.00 ),
            std::make_tuple(2, "Allen", 25, "Texas", 15000.00 ),
            std::make_tuple(3, "Teddy", 23, "Norway", 20000.00 ),
            std::make_tuple(4, "Mark", 25, "Rich-Mond ", 65000.00 ));

    printf("数据插入成功\n");

    return 0;
}



#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <SQLiteCpp/SQLiteCpp.h>

int main()
{
    SQLite::Database db("test.db3", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
    //SQLite::Database db("test.db3");
    std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

    return 0;
}


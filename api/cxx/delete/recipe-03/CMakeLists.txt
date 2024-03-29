# Example CMake file for compiling & linking a project with the the SQLiteCpp wrapper
#
# Copyright (c) 2012-2020 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT)
cmake_minimum_required(VERSION 3.1) # for "CMAKE_CXX_STANDARD" version
project(SQLiteCpp_Example VERSION 2.0)

# SQLiteC++ 3.x now requires C++11 compiler
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SQLite3 C++ wrapper around sqlite3 library (and sqlite3 itself provided for ease of use)
# Here you can set CMake variables to avoid building Example, as well as cpplint, cppcheck...
# or set them in the cmake command line (see for instance provided build.bat/build.sh scripts)
set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)
#add_subdirectory(SQLiteCpp)

find_package(SQLiteCpp REQUIRED)

# Add main.cpp example source code to the executable
add_executable(delete_named_style delete_named_style.cpp)

# Link SQLiteCpp_example1 with SQLiteCpp
#target_link_libraries(SQLiteCpp_Example SQLiteCpp)
target_link_libraries(delete_named_style PRIVATE SQLiteCpp)


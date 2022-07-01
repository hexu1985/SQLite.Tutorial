### SQLiteC++ api

- 编译SQLiteCpp

```
$ git clone https://github.com/SRombauts/SQLiteCpp.git      # git@github.com:hexu1985/SQLiteCpp.git
$ cmake -H. -Bbuild -DCMAKE_INSTALL_PREFIX=~/local/SQLiteCpp \
    -DCMAKE_BUILD_TYPE=Debug \
    -DSQLITECPP_INTERNAL_SQLITE=OFF \
    -DSQLITECPP_USE_ASAN=ON \
    -DSQLITECPP_USE_GCOV=OFF \
    -DSQLITECPP_BUILD_EXAMPLES=ON \
    -DSQLITECPP_BUILD_TESTS=OFF

$ cmake --build build --target install
```


#### 参考文档:

- [SQLiteCpp主页](http://srombauts.github.io/SQLiteCpp/)
- [SQLiteCpp仓库](https://github.com/SRombauts/SQLiteCpp)
- [SQLiteCpp_Example仓库](https://github.com/SRombauts/SQLiteCpp_Example)

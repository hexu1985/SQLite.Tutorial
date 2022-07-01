# exit on first error
set -e

cmake -H. -Bbuild -DCMAKE_INSTALL_PREFIX=~/local/SQLiteCpp \
    -DCMAKE_BUILD_TYPE=Debug \
    -DSQLITECPP_INTERNAL_SQLITE=OFF \
    -DSQLITECPP_USE_ASAN=OFF \
    -DSQLITECPP_USE_GCOV=OFF \
    -DSQLITECPP_BUILD_EXAMPLES=ON \
    -DSQLITECPP_BUILD_TESTS=OFF

cmake --build build --target install

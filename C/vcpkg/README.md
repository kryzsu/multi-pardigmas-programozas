## package management
no, but

vcpkg
* c/C++ package management solution
* json descriptor (dependency)
* platform independent
* https://github.com/microsoft/vcpkg#quick-start-unix

### install


### using

search

```shell
vcpkg search mysql
```

install and its dependencies
```shell
vcpkg install mysql
```

if success

```shell
Total elapsed time: 8.009 min

The package libmysql provides CMake targets:

    find_package(libmysql REQUIRED)
    target_link_libraries(main PRIVATE ${MYSQL_LIBRARIES})
```

list installed package
```shell
vcpkg list
```

example for result
```shell
libmysql:x64-linux                                 8.0.20#2         A MySQL client library for C development
lz4:x64-linux                                      1.9.3#3          Lossless compression algorithm, providing compre...
openssl:x64-linux                                  1.1.1l#1         OpenSSL is an open source project that provides ...
vcpkg-cmake-config:x64-linux                       2021-09-27       
vcpkg-cmake:x64-linux                              2021-09-13       
zlib:x64-linux                                     1.2.11#12        A compression library

```

### practice: using any dependency

simple source file, main.cpp
```c
#include <fmt/core.h>
#include <zlib.h>

int main()
{
    fmt::print("fmt version is {}\n"
               "zlib version is {}\n", 
               FMT_VERSION, ZLIB_VERSION);
    return 0;
}
```

CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.18)

project(versionstest CXX)

add_executable(main main.cpp)

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)
```

vcpkg.json
```json
{
    "name": "versions-test",
    "version": "1.0.0",
    "dependencies": [
        {
            "name": "fmt",
            "version>=": "7.1.3#1"
        }, 
        "zlib"
    ],
    "builtin-baseline": "3426db05b996481ca31e95fff3734cf23e0f51bc"
}
```

Compiling the binary
```shell
mk biuld
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../../vcpkg/scripts/buildsystems/vcpkg.cmake  ..
make
./main
```
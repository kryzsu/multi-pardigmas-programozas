# multi-pardigmas-programozas

# C / C++

## project tool

### cmake

CMakeLists.txt¶

* main description (separate can be existed in every folder)
* additional arguments from command line (`cmake .. -DCMAKE_INSTALL_PREFIX=../_install`)

suggested steps

1. mkdir build && cd build
2. cmake .. -DCMAKE_C_COMPILER=gcc
3. cmake --build .


typical lib definition

```
cmake_minimum_required(VERSION 2.8)
project(libtest_project)
add_library(test STATIC test.c)
install(TARGETS test DESTINATION lib)
install(FILES test.h DESTINATION include)
```

import the static library for executable

```
add_library(test SHARED test.c)
```

```
cmake_minimum_required(VERSION 2.8)
project(myapp)
add_subdirectory(libtest_project)
add_executable(myapp main.c)
target_link_libraries(myapp test)
install(TARGETS myapp DESTINATION bin)
```

use ExternalProject_Add for 
including external libraries using other build systems


### practice 

step1
    simple executable project

step2
    executable project and library

step3
    cmake SWITCH for using the library. If not present then sqrt is used from math.h

step4
    easier library include usage (automatically)

step5
    install file by cmake

step6
    testing

step7
    packaging

Pls compare the folders to recognize the required modifications

```shell
cd Step1_build
cmake ../Step1
cmake build .
./Tutorial
```

```shell
cd Step2_build
cmake ../Step2
cmake build .
./Tutorial
```

Step3

first
```shell
cmake ../Step3
make
./Tutorial 23
```
check the header file, and the output

then

```shell
rm -rf *
cmake ../Step3 -DUSE_MYMATH=OFF
make
./Tutorial 23
```
check the header file, and the output


```shell
cmake ../Step5
cmake --install . --prefix ../install/
ls -lR ../install/
```

```shell
cmake ../Step6
ctest
```

```shell
cmake ../Step7
cpack
cp Tutorial-3.0-Linux.sh ../install/
cd ../install/
sh Tutorial-3.0-Linux.sh
ls -lR
```

```shell
cpack -G DEB
```
ctest -C Debug -VV in debug mode
### Useful options

set(CMAKE_VERBOSE_MAKEFILE ON)

make VERBOSE=1;

cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON $path_to_project_source;


message(STATUS "USE_MYMATH ${USE_MYMATH}")

```shell
mkdir Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

```shell
mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

if (UNIX)
set(EXTRA_LIBS ${EXTRA_LIBS} m)
endif (UNIX)


```
- project
  - .gitignore
  - README.md
  - LICENCE.md
  - CMakeLists.txt
  - cmake
    - FindSomeLib.cmake
    - something_else.cmake
  - include
    - project
      - lib.hpp
  - src
    - CMakeLists.txt
    - lib.cpp
  - apps
    - CMakeLists.txt
    - app.cpp
  - tests
    - CMakeLists.txt
    - testlib.cpp
  - docs
    - CMakeLists.txt
  - extern
    - googletest
  - scripts
    - helper.py
```

## usefull links

https://notabug.org/mazurov/awesome-c

https://awesomeopensource.com/project/Bfgeshka/awesome-c


# C / C++

## debugger

* special compilation
* bigger size

```shell
gcc -g source.c
```

```C
  #include <stdlib.h>

  void f(void)
  {
     int* x = malloc(10 * sizeof(int));
     x[10] = 0;        // problem 1: heap block overrun
  }                    // problem 2: memory leak -- x not freed

  int main(void)
  {
    int a = 10;
    a++;     
    f();
    return 0;
  }
```


### gdb

* command line

b main - Puts a breakpoint at the beginning of the program

b - Puts a breakpoint at the current line

b N - Puts a breakpoint at line N

b +N - Puts a breakpoint N lines down from the current line

b fn - Puts a breakpoint at the beginning of function "fn"

d N - Deletes breakpoint number N

info break - list breakpoints

r - Runs the program until a breakpoint or error

c - Continues running the program until the next breakpoint or error

f - Runs until the current function is finished

s - Runs the next line of the program

s N - Runs the next N lines of the program

n - Like s, but it does not step into functions

u N - Runs until you get N lines in front of the current line

p var - Prints the current value of the variable "var"

bt - Prints a stack trace

u - Goes up a level in the stack

d - Goes down a level in the stack

q - Quits gdb


print x
set x=5

call myfunction()



show environment
set environment varname

#### unbelievable feature

reverse running

reverse-step
reverse-next

```
(gdb) b main
Breakpoint 1 at 0x1174: file demo.c, line 10.
(gdb) r
Starting program: /home/kry/devel/c/a.out

Breakpoint 1, main () at demo.c:10
10	  {
(gdb) record
(gdb) next
13		a = 10;
(gdb) next
14		a++;
(gdb) p a
$1 = 10
(gdb) n
15	     	f();
(gdb) p a
$2 = 11
(gdb) reverse-next
14		a++;
(gdb) p a
$3 = 10
```



## project tool

### make, nmake

```
blah: blah.o
    cc blah.o -o blah # Runs third

blah.o: blah.c
    cc -c blah.c -o blah.o # Runs second

blah.c:
    echo "int main() { return 0; }" > blah.c # Runs first
```

```makefile
hellomake: hellomake.c hellofunc.c
     gcc -o hellomake hellomake.c hellofunc.c -I.
```

```makefile
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
```

```makefile
clean:
	rm -f $(ODIR)/*.o
```


### cmake

CMakeLists.txt¶

* main description (separate can be exist in every folder)
* additional arguments from command line (`cmake .. -DCMAKE_INSTALL_PREFIX=../_install`)

suggested steps

1. mkdir build && cd build
2. cmake .. -DCMAKE_C_COMPILER=gcc
3. make


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


## package management
no, but 

vcpkg
* c/C++ package management solution
* json descriptor (dependency)
* platform independent
* https://github.com/microsoft/vcpkg#quick-start-unix


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
```
cmake_minimum_required(VERSION 3.18)

project(versionstest CXX)

add_executable(main main.cpp)

find_package(ZLIB REQUIRED)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE ZLIB::ZLIB fmt::fmt)
```

vcpkg.json
```
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

```
mk biuld
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../../vcpkg/scripts/buildsystems/vcpkg.cmake  ..
make
./main
```

## Example


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


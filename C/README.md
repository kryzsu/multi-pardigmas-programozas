# multi-pardigmas-programozas

# C / C++



## compiler
### gcc, gxx
### lcc
### MS compiler

## ide

### clion

### Visual Studio

### VS code

### Eclipse

### Xcode (mac)

* Command Line Tools for Xcode 13 has to be installed


### making big projects
1. download/create the source
2. download all dependencies (lib + header)
3. compile and install dependencies
4. compile the source code

Normal flow
1. make
2. sudo make install

Extended flow
1. .configure
2. make
3. sudo make install

cmake flow
1. mkdir build
2. cd build
3. cmake 
4. cmake --build . ( or make) 
5. sudo make install

Dependencies
* library - the implementation
* header file - declarations

creating binary

include folders:

* -I command line switch
* C_INCLUDE_PATH (Each variable’s value is a list of directories separated by a special character, much like PATH, in which to look for header files. The special character, PATH_SEPARATOR, is target-dependent and determined at GCC build time.)

library path
* -L command line switch
* LIBRARY_PATH (colon-separated list of directories)

f.e.
```shell
gcc imagefilter.c -o imagefilter \ 
-I/home/savio/opencv-3.0.0/include/opencv \ 
-L/home/savio/opencv-3.0.0/cmake_binary_dir/lib \ 
-lopencv_core -lopencv_highgui -lopencv_imgproc 
```


https://web.archive.org/web/20090129230009if_/http://www.network-theory.co.uk/docs/gccintro/gccintro_23.html

## Suggested structure


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


ugly code

```C
/*
 * File: hello.c
 */
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *string, 
    *string_so_far;
    int i, length;     
    length = 0;
    for(i=0; i<argc; i++) {
        length += strlen(argv[i])+1;
        string = (char *) malloc(length+1);
 
        /*  * Copy the string built so far. */
        if(string_so_far != (char *)0) {
            strcpy(string, string_so_far);
        }
        else *string = '\0';
        strcat(string, argv[i]);
        if(i < argc-1) strcat(string, " ");
        string_so_far = string;
    }
    printf("You entered: %s\n", string_so_far);
    return (0);
}
```

## usefull links

https://notabug.org/mazurov/awesome-c

https://awesomeopensource.com/project/Bfgeshka/awesome-c


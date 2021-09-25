# multi-pardigmas-programozas

# C / C++

ugly code

```C
/*
 * File: hello.c
 */
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *string, *string_so_far;
    int i, length;     length = 0;
    for(i=0; i<argc; i++) {
        length += strlen(argv[i])+1;
        string = malloc(length+1);
 
        /*  * Copy the string built so far. */
        if(string_so_far != (char *)0)
            strcpy(string, string_so_far);
        else *string = '\0';
        strcat(string, argv[i]);
        if(i < argc-1) strcat(string, " ");
        string_so_far = string;
    }
    printf("You entered: %s\n", string_so_far);
    return (0);
}
```

## ide

### clion

### 
## linter, static source code analizer
## memeory leak detector

Try to find any big fault, semantic problem.

### Valgrind

* linux only

we can

* Finding Invalid Pointer
* Finding Memory Leaks
* Detecting The Use Of Uninitialized Variables
* improper uses of memory

Install

```shell
./configure
make
make install
```

Using

```shell
valgrind --tool=memcheck program_name
```

```shell
valgrind --tool=memcheck --leak-check=yes program_name
```

## debugger

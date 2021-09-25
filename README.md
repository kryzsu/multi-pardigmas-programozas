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

## compiler
### gcc, gxx
### lcc
### MS compiler

## ide

### clion

### Visual Studio

### VS code

### Eclipse

## linter, static source code analizer

## memeory leak detector

Try to find any big fault, semantic problem.

### custom solution

writing out to file the `__FILE__`, `__LINE__` and opinter address

* In case of C: wrapper method for malloc, free
* C++ override the `new` and `delete` operator

### Valgrind

* linux only
* command line tool
* hard to understand

we can

* Finding Invalid Pointer
* Finding Memory Leaks
* Detecting The Use Of Uninitialized Variables
* improper uses of memory

Install

`sudo apt install`

```shell
./configure
make
make install
```

Using

```shell
valgrind --tool=memcheck program_name arg1 arg2
```

```shell
valgrind --tool=memcheck --leak-check=yes program_name arg1 arg2
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
     f();
     return 0;
  }
```

output
```
valgrind ./a.out
==6100== Memcheck, a memory error detector
==6100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6100== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==6100== Command: ./a.out
==6100==
==6100== Invalid write of size 4
==6100==    at 0x10916B: f (in /home/kry/devel/c/a.out)
==6100==    by 0x109180: main (in /home/kry/devel/c/a.out)
==6100==  Address 0x4a84068 is 0 bytes after a block of size 40 alloc'd
==6100==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==6100==    by 0x10915E: f (in /home/kry/devel/c/a.out)
==6100==    by 0x109180: main (in /home/kry/devel/c/a.out)
==6100==
==6100==
==6100== HEAP SUMMARY:
==6100==     in use at exit: 40 bytes in 1 blocks
==6100==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==6100==
==6100== LEAK SUMMARY:
==6100==    definitely lost: 40 bytes in 1 blocks
==6100==    indirectly lost: 0 bytes in 0 blocks
==6100==      possibly lost: 0 bytes in 0 blocks
==6100==    still reachable: 0 bytes in 0 blocks
==6100==         suppressed: 0 bytes in 0 blocks
==6100== Rerun with --leak-check=full to see details of leaked memory
==6100==
==6100== For lists of detected and suppressed errors, rerun with: -s
==6100== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

## debugger

special compaliton

```shell
gcc -g source.c
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

#### unbelivable feature

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

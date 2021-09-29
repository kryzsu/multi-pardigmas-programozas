# C / C++

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

`sudo apt install valgrind`

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





https://www.softwaretestinghelp.com/memory-leak-detection-tools/

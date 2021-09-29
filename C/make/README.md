# C / C++

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
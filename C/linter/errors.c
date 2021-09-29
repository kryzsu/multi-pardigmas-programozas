/*
 * File: hello.c
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char* kMessage = "Hello World!";
void getMessage(char* buf) {
    memcpy(buf, kMessage, sizeof(kMessage));
}

void bad_malloc(char *str) {
    char *c = (char*) malloc(strlen(str + 1));
}

int main(int argc, char *argv[]) {

    #define BUFLEN 42
    char buf[BUFLEN];
    memset(buf, 0, sizeof(BUFLEN));

    long size = 294967296l;
    for (short i = 0; i < size; ++i) {}


    int i = 0, j = 0;

    while (i < 10) {
        ++j;
    }
}

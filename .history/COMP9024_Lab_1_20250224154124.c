// #include "mystrlen.h"
#include "stdio.h"

int mystrlen(char *s) {
    // *s always point to the start char of the string
    int length = 0;
    while (s != '\0')
    {
        length++;
        s++;
    }
    return length;

}

int main(void) {

}
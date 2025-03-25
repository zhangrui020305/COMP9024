// #include "mystrlen.h"
#include "stdio.h"

int mystrlen(char *s)
{
    // *s always point to the start char of the string
    int length = 0;
    while (*s != '\0'){
        length++;
        printf(*s);
        s++;
    }
    return length;
}

int main(void)
{
    char str[] = "Hello";
    printf('%c\n', mystrlen(str));
    return 0;
}
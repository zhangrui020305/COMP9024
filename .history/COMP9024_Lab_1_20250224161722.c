// #include "mystrlen.h"
#include "stdio.h"

int mystrlen(char *s)
{
    // *s always point to the start char of the string
    int length = 0;
    while (*s != '\0'){
        length++;
        printf("%d\n", s);
        s++;
        printf("%c\n", *s);
    }
    return length;
}

int main(void)
{
    char str[] = "Hello";
    printf("%d\n", mystrlen(str));
    return 0;
}
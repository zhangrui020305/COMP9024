#include "mystrlen.h"
#include "stdio.h"

int mystrlen(char *s)
{
    int len = 0;
    // your code here to implement mystrlen
    // *s means value and s means address
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

int main(void)
{
    // your code here to test mystrlen
    char test[] = "12345";
    printf("%d\n", mystrlen(test));
    return 0;
}
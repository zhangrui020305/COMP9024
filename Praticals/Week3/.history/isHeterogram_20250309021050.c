#include "stdio.h"
#include "stdbool.h"

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

bool isHeterogram(char A[])
{
    bool seen[26] = {false};
    int len = mystrlen(A);
    for (int i = 0; i < len; i++)
    {
        printf("%c", A[i]);
    }
}

void main(){
    isHeterogram("rabbit");
    return 0;
}
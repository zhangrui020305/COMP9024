#include "stdio.h"

long factorial(int n)
{
    int result = 1;
    while (n > 0)
    {
        int temp = n;
        result = result * temp;
        n--;
    }
    return result;
}

int main(void)
{
    char str[100];

    while (1)
    {
        printf("Enter a word or phrase: ");
        fgets(str, sizeof(str), stdin);
        

    }

    printf("%ld", factorial(7));
}
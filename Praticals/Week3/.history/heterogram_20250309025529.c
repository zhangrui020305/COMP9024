#include "stdio.h"
#include "stdbool.h"
#include "string.h"

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
    int len = strlen(A);
    for (int i = 0; i < len; i++)
    {
        if (A[i] == ' ')
        {
            continue;
        }
        int index = A[i] - 'a';
        if (seen[index] == true)
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

int main()
{
    while (1)
    {
        char str[100];
        printf("Enter a word or phrase: ");
        fgets(str, sizeof(str), stdin);

        str[strcspn(str, "\n")] = '\0';

        if (isHeterogram(str))
        {
            printf("\"%s\" is a heterogram\n", str);
        }
        else
        {
            printf("\" %s \" is a not heterogram\n", str);
        }
    }
    return 0;
}
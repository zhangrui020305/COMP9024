#include <stdio.h>
#include "mystrlen.c"

int main(void) {
   char s[MAXLEN];
   int len;

   // your code here to repeatedly prompt the user for a string 
   // and print its length using mystrlen
    int value = 0;
    scanf("%d", &value);
    while (1)
    {
        // char *p = s;
        // while (*p != '\0' && *p != '\n')
        // {
        //     p++;

        // }
        len = mystrlen(s);
        printf("%d\n", len);
    }
    

   return 0;
}
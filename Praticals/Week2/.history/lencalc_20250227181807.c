#include <stdio.h>
#include "mystrlen.h"

int main(void) {
    char s[MAXLEN];
    // int len;

    // Modify this section of the code
    // -------------------------------

    while (1)
    {
        /* code */
        printf("Enter a string:");
        fgets(s, MAXLEN, stdin);
        // printf(s);
        if (mystrlen(s) - 1 == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        printf("%d\n", mystrlen(s));
        
    }
    
    // -------------------------------

    return 0;
}
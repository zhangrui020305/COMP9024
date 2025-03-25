#include <stdio.h>
#include "mystrlen.h"

int main(void) {
    char s[MAXLEN];
    int len;

    // Modify this section of the code
    // -------------------------------

    while (1)
    {
        /* code */
        printf("Enter a string:");
        fgets(s, MAXLEN, stdin);
        if (*s == '\0')
        {
            printf("Goodbye!");
            break;
        }
        printf(mystrlen(s));
        
    }
    

    printf("Enter a string: ");
    fgets(s, MAXLEN, stdin);
    printf("You entered: %s", s);
    
    // -------------------------------

    return 0;
}
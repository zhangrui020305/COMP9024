#include <stdio.h>
#include "mystrlen.h"

int main(void) {
    char s[MAXLEN];
    int len;

    // Modify this section of the code
    // -------------------------------

    printf("Enter a string: ");
    fflush(stdout)
    fgets(s, MAXLEN, stdin);
    printf("You entered: %s", s);
    
    // -------------------------------

    return 0;
}
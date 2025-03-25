#include "stdio.h"
#include "math.h"

float growth(int n)
{
    while (1)
    {
        scanf("Enter an integer: %d", &n);
        printf("For n = %d", n);
        if (n <= 0){
            printf("Goodbye!");
            return 0;
        }
        printf("log(n)     = ");
        printf("sqrt(n)    = ");
        printf("n          = ");
        printf("n * log(n) = ");
        printf("n^2        = ");
        printf("n^3        = ");
        printf("2^n        = ");
        printf("n!         = ");
        printf("log(n)     = ");
    }
    
}
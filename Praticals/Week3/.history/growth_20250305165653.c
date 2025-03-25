#include "stdio.h"
#include "math.h"

void growth(int n)
{
    printf("Enter an integer: ");
    // fflush(stdout);
    scanf("%d", &n);
    return;
    // while (1)
    // {
    //     printf("Enter an integer: ");
    //     // fflush(stdout);
    //     scanf("%d", &n);
    //     printf("For n = %d", n);
    //     if (n <= 0)
    //     {
    //         printf("Goodbye!");
    //         return ;
    //     }
    //     printf("log(n)     = %lf", log(n));
    //     printf("sqrt(n)    = %lf", sqrt(n));
    //     printf("n          = %d\n", n);
    //     printf("n * log(n) = ");
    //     printf("n^2        = ");
    //     printf("n^3        = ");
    //     printf("2^n        = ");
    //     printf("n!         = ");
    //     printf("n^n        = ");
    // }
}

int main(void)
{
    growth(1);
    return 0;
}
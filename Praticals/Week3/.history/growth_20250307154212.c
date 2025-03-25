#include "stdio.h"
#include "math.h"

void growth(int n)
{
    while (1)
    {
        printf("Enter an integer: ");
        scanf("%d", &n);
        printf("For n = %d", n);
        if (n <= 0)
        {
            printf("Goodbye!");
            return;
        }
        printf("log(n)     = %lf\n", log(n));
        printf("sqrt(n)    = %lf\n", sqrt(n));
        printf("n          = %d\n", n);
        printf("n * log(n) = \n", n * log(n));
        printf("n^2        = \n", n * n);
        printf("n^3        = \n", n * n * n);
        printf("2^n        = \n", pow(2, n));
        printf("n!         = \n", factorial(n));
        printf("n^n        = \n", pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}
#include "stdio.h"
#include "math.h"

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

void growth(int n)
{
    while (1)
    {
        printf("Enter an integer: ");
        scanf("%d", &n);
        printf("For n = %d\n", n);
        if (n <= 0)
        {
            printf("Goodbye!\n");
            return;
        }
        printf("log(n)     = %g\n", log(n));
        printf("sqrt(n)    = %g\n", sqrt(n));
        printf("n          = %g\n", n);
        printf("n * log(n) = %g\n", n * log(n));
        printf("n^2        = %g\n", n * n);
        printf("n^3        = %g\n", n * n * n);
        printf("2^n        = %g\n", pow(2, n));
        printf("n!         = %g\n", factorial(n));
        printf("n^n        = %g\n", pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}
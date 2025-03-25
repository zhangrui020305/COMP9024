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
        printf("log(n)     = %lf\n", log(n));
        printf("sqrt(n)    = %lf\n", sqrt(n));
        printf("n          = %d\n", n);
        printf("n * log(n) = %lf\n", n * log(n));
        printf("n^2        = %d\n", n * n);
        printf("n^3        = %d\n", n * n * n);
        printf("2^n        = %lf\n", pow(2, n));
        printf("n!         = %ld\n", factorial(n));
        printf("n^n        = %lf\n", pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}
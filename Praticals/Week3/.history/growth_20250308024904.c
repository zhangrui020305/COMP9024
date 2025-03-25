#include <stdio.h>
#include <math.h>

long factorial(int n)
{
    long result = 1;  // 用 long 存储阶乘
    while (n > 0)
    {
        result *= n;
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

        printf("log(n)     = %.0f\n", log(n));
        printf("sqrt(n)    = %.0f\n", sqrt(n));
        printf("n          = %d\n", n);
        printf("n * log(n) = %.0f\n", n * log(n));
        printf("n^2        = %d\n", n * n);
        printf("n^3        = %d\n", n * n * n);
        printf("2^n        = %.0f\n", pow(2, n));
        printf("n!         = %ld\n", factorial(n));  // 用 %ld 输出 long
        printf("n^n        = %.0f\n", pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}

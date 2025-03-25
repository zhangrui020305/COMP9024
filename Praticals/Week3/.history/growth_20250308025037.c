#include <stdio.h>
#include <math.h>

long factorial(int n)
{
    long result = 1;
    while (n > 0)
    {
        result *= n;
        n--;
    }
    return result;
}

void print_number(double value) {
    if (fmod(value, 1.0) == 0.0) {
        printf("%d\n", (int)value);  // 整数，去掉小数部分
    } else {
        printf("%lf\n", value);  // 非整数，保留小数
    }
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

        printf("log(n)     = "); print_number(log(n));
        printf("sqrt(n)    = "); print_number(sqrt(n));
        printf("n          = %d\n", n);
        printf("n * log(n) = "); print_number(n * log(n));
        printf("n^2        = %d\n", n * n);
        printf("n^3        = %d\n", n * n * n);
        printf("2^n        = "); print_number(pow(2, n));
        printf("n!         = %ld\n", factorial(n));
        printf("n^n        = "); print_number(pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}

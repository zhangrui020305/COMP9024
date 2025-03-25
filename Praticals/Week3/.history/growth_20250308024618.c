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

        if (fmod(log(n), 1.0) == 0.0){
            printf("log(n)     = %d\n", log(n));
        } else{
            printf("log(n)     = %lf\n", log(n));
        }
        // printf("log(n)     = %lf\n", log(n));

        if (fmod(sqrt(n), 1.0) == 0.0){
            printf("sqrt(n)    = %d\n", sqrt(n));
        } else {
            printf("sqrt(n)    = %lf\n", sqrt(n));
        }
        // printf("sqrt(n)    = %lf\n", sqrt(n));
        
        printf("n          = %d\n", n);

        if (fmod(n * log(n), 1.0) == 0.0){
            printf("n * log(n) = %d\n", n * log(n));
        } else{
            printf("n * log(n) = %lf\n", n * log(n));
        }
        // printf("n * log(n) = %lf\n", n * log(n));

        if (fmod(n * n, 1.0) == 0.0){
            printf("n^2 = %d\n", n * n);
        } else{
            printf("n^2 = %lf\n", n * n);
        }
        // printf("n^2        = %d\n", n * n);

        if (fmod(n * n * n, 1.0) == 0.0){
            printf("n^3 = %d\n", n * n * n);
        } else{
            printf("n^3 = %lf\n", n * n * n);
        }
        // printf("n^3        = %d\n", n * n * n);

        if (fmod(pow(2, n), 1.0) == 0.0){
            printf("2^n = %d\n", pow(2, n));
        } else{
            printf("2^n = %lf\n", pow(2, n));
        }
        // printf("2^n        = %lf\n", pow(2, n));

        if (fmod(factorial(n), 1.0) == 0.0){
            printf("n! = %d\n", factorial(n));
        } else{
            printf("n! = %lf\n", factorial(n));
        }
        // printf("n!         = %ld\n", factorial(n));

        if (fmod(pow(n, n), 1.0) == 0.0){
            printf("n^n = %d\n", pow(n, n));
        } else{
            printf("n^n = %lf\n", pow(n, n));
        }
        // printf("n^n        = %lf\n", pow(n, n));
    }
}

int main(void)
{
    growth(1);
    return 0;
}
#include "stdio.h"
#include "math.h"

void growth(int n)
{
    printf("111111");
    while (1)
    {
        printf("222222");
        scanf("Enter an integer: %d", &n);
        printf("For n = %d", n);
        if (n <= 0)
        {
            printf("Goodbye!");
            return ;
        }
        printf("log(n)     = ");
        printf("sqrt(n)    = ");
        printf("n          = ");
        printf("n * log(n) = ");
        printf("n^2        = ");
        printf("n^3        = ");
        printf("2^n        = ");
        printf("n!         = ");
        printf("n^n        = ");
    }
}

int main(void){
    growth(1);
    return 0;
}
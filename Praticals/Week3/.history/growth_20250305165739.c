#include "stdio.h"
#include "math.h"

void growth(int n)
{
    printf("Enter an integer: ");
    // fflush(stdout);
    scanf("%d", &n);
    return;
}

int main(void)
{
    growth(1);
    return 0;
}
#include <stdio.h>
#include <math.h>

void growth(int n)
{
    printf("Enter an integer:\n");  // 添加 '\n' 强制输出
    scanf("%d", &n);
    return;
}

int main(void)
{
    growth(1);
    return 0;
}

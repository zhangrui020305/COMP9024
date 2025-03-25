#include <stdio.h>

void growth(int n)
{
    printf("Before scanf\n");  // 调试信息
    printf("Enter an integer:\n");  // 添加 `\n`
    printf("After printf\n");  // 另一条调试信息
    scanf("%d", &n);
    printf("After scanf\n");  // 检查 `scanf` 是否执行
}

int main(void)
{
    printf("Program starts\n");  // 额外的调试信息
    growth(1);
    printf("Program ends\n");
    return 0;
}

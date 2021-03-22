#include<stdio.h>

int main()
{
	int a, b,c;
	printf("请输入两个整数:\n");
	scanf_s("%d %d", &a, &b);
	c = a + b;
	printf("%d+%d=%d\n", a, b, c);
	return 0;
}
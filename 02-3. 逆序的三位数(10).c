#include<stdio.h>

int main()
{
	int x,x1,x2,x3,y;
	scanf_s("%d", &x);
	x1 = x / 100;
	x2 = x % 100 / 10;
	x3 = x % 100 % 10;
	y = x3 * 100 + x2 * 10 + x1;
	printf("%d", y);
	return 0;
}
#include<stdio.h>

int main()
{
	int a,x,y;
	scanf_s("%d", &a);
	x = a / 16;
	y = a % 16;
	printf("%x", 10*x + y);
	return 0;
}
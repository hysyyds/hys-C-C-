#include<stdio.h>

int main()
{
	int x,t=0,d;
	scanf_s("%d", &x);
	do {
		 d = x % 10;
		t = t * 10 + d;
		x /= 10;
	} while (x > 0);
	do {
		d = t % 10;
		printf("%d", d);
		if (t > 9)printf(" ");
		t /= 10;
	} while (x > 0);
}
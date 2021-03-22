#include<stdio.h>
int main()
{
	float a;
	float b;
	int c;
	char d;
	scanf_s("%f %d %c %f", &a,&c,&d,1,&b);
	printf("%c %d %.2f %.2f", d, c, a, b);

} 
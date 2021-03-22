#include<stdio.h>

int main()
{
	int a, b,t,i,j;
	scanf_s("%d/%d",&a,&b);
	i = a;
	j = b;
	while (j != 0) {
		t = i % j;
		i = j;
		j = t;
	}
	a /= i;
	b /= i;
	printf("%d/%d", a, b);
	return 0;
} 
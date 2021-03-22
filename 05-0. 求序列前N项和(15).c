#include<stdio.h>

int main()
{
	int n,count;
	double i = 1, j = 1;//intª·‘ΩΩÁ
	double t;
	double sum=0;
	scanf_s("%d",&n);
	for (count = 0; count < n; count++) {
		t = j;
		j = i;
		i+=t;
		sum += i/j;
	}
	printf("%.2lf", sum);
	return 0;
} 
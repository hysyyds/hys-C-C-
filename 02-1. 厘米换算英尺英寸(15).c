#include<stdio.h>

int main()
{
	int meter;
	scanf_s("%d", &meter);
	int foot_all = ((meter / 100.0) / 0.3048 * 12);
	printf("%d %d", foot_all / 12, foot_all % 12);
	return 0;

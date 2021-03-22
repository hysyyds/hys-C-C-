#include<stdio.h>

int main()
{
	int day;
	scanf_s("%d", &day);
	if (day % 5 <=3)
		if (day % 5 != 0)
		printf("Fishing in day %d", day);
		else
		printf("Drying in day %d", day);
	else
	printf("Drying in day %d", day);
}
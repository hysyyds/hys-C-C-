#include<stdio.h>

int main()
{
	int speed;
	scanf_s("%d", &speed);
	if (speed > 60)
	{
		printf("Speed: %d - Speeding",speed);
	}
	else
	{
		printf("Speed: %d - OK", speed);
	}
	return 0;
}
#include<stdio.h>

int main()
{
	int time_past,minute_pass;
	scanf_s("%d %d", &time_past, &minute_pass);
	int hour_past = time_past / 100;
	int minute_past = time_past % 100;
	int allminute_now = hour_past * 60 + minute_past + minute_pass;
	int hour_now = allminute_now / 60;
	int minute_now = allminute_now % 60;
	int time_now = hour_now * 100 + minute_now;
	printf("%d",time_now);
	return 0;
}
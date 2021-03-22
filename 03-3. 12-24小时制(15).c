#include<stdio.h>

int main()
{
	int hour, minute;
	scanf_s("%d:%d", &hour,&minute);
	if (hour > 12) {
		if (hour == 24) {
			printf("0:0 AM");
		}
		else {
			hour -= 12;
			printf("%d:%d PM", hour, minute);
		}
	}
	else {
		if (hour == 12) {
			printf("12:0 PM");
		}
		else {
			printf("%d:%d AM", hour, minute);
		}
	}
	return 0;
}
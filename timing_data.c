#include<stdio.h>
#include"timing.h"
Stime* gettime(Stime* p) {
	scanf_s("%d%d%d", &p->day, &p->month, &p->year);
	if (p->month > 12) {
		printf("EROOR MONTH PLEASE REPUT\n");
		p = NULL;
	}
	else if (p->day > daysofmonth(p)) {
		printf("EROOR DATE PLEASE REPUT\n");
		p = NULL;
	}
	return p;
}
int daysofmonth(const Stime* p) {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapyear(p)) {
		days[1] = 29;
	}
	return days[p->month - 1];
}
int leapyear(const Stime* p) {
	int bool = 0;
	if (p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400 == 0) {
		bool = 1;
	}
	return bool;
}
Stime* tomorrow(Stime* p) {
	if (p->day == daysofmonth(p)) {
		p->day = 1;
		if (p->month == 12) {
			p->month = 1;
			p->year += 1;
		}
		else p->month += 1;
	}
	else p->day += 1;
	return p;
}
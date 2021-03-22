#include<stdio.h>

struct time {
	int day, month, year;
};
typedef struct time time;
struct time*  gettime(struct time* p);//用户输入当前时间dd-mm-yy
int daysofmonth(struct time *p);//获取当前月份天数
int leapyear(struct time* p);//判断是否为闰年
struct time* tomorrow(struct time* p);//明天
int main() {
	struct time now;
	struct time* p;
	int gap_time,i;
	p = &now;
	while (scanf("%d", &gap_time) != EOF) {
		while(gettime(p)==NULL){
		printf("ERROR TIME,please reput time\n");
		p = &now;
		}
		for (i = 0; i < gap_time; i++) {
		tomorrow(p);
		}
		printf("%d day later is %d-%d-%d\n", gap_time, now.year, now.month, now.day);
	}
	return 0;
}
struct time*  gettime(struct time* p) {
	scanf_s("%d%d%d", &p->day, &p->month, &p->year);
	if (p->day > daysofmonth(p)) {
		p = NULL;
	}
	return p;
}
int daysofmonth(struct time* p) {
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapyear(p)) {
		days[1] = 29;
	}
	return days[p->month - 1];
}
int leapyear(struct time* p) {
	int bool = 0;
	if (p->year % 4 == 0 && p->year % 100 != 0 || p->year % 400==0) {
		bool = 1;
	}
	return bool;
}
struct time* tomorrow(struct time* p) {
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

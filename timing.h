#ifndef __TIMING_H__
#define __TIMING_H__
typedef struct time {
	int day, month, year;
}Stime;
Stime* gettime(Stime* p);//用户输入当前时间dd-mm-yy
int daysofmonth(const Stime* p);//获取当前月份天数
int leapyear(const Stime* p);//判断是否为闰年
Stime* tomorrow(Stime* p);//明天
#endif
#include<iostream>
#include"stdy.h"
using std::cout;
class Time {
private:int year,day,month;
public:Time(int y=0,int m=1,int d=1);
	  Time(const Time& temp);
	  friend int gapdate(const Time& t1, const Time& t2);
	  int year_();
	  int day_();
	  int month_();
};
bool leapyear(int y) {
	bool t=1;
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) {
		t = 0;
	}
	return t;
}
int daysofmonth(int y, int m) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (!leapyear(y)) {
			a[1] = 29;
		}
		return a[m - 1];
}
Time::Time(int y, int m, int d) {
	year = y;
	if (m > 0 && m < 13) {
		month = m;
	}
	if ((d <= daysofmonth(y, m)) && d > 0) {
		day = d;
	}
}
Time::Time(const Time& temp) {
	year = temp.year;
	day = temp.day;
	month = temp.month;
}
int gapdate(const Time& t1, const Time& t2) {
	int gapday=0;
	int i;
	for (i = t2.year; i < t1.year; i++) {
		if (leapyear(i)) {
			gapday += 365;
		}
		else gapday += 366;
	}
	for (i = 1; i < t1.month; i++) {
		gapday += daysofmonth(t1.year,i);
	}
	for (i = 1; i < t2.month; i++) {
		gapday -= daysofmonth(t2.year, i);
	}
	gapday += t1.day;
	gapday -= t2.day;
	return gapday;
}
int Time::year_() {
	return year;
}
int Time::day_() {
	return day;
}
int Time::month_() {
	return month;
}
int main(int argc, char** argv) {
	Time begin(2010, 1, 1);
	FILE* fp1, *fp2;
	fp2 = fopen("out.txt", "a");
	fp1 = fopen("in.txt", "r");
	int i,sum;
	if (fp1 == NULL) {
		cout << "ERROR NO SUCH FILE";
		exit(1);
	}
	int y, m, d;
	for (i = 0; i < count; i++) {
		fscanf(fp1, "%d%d%d", &y, &m, &d);
		Time t(y, m, d);
		sum=gapdate(t, begin);
		if (sum%5<4) {
			fprintf(fp2, "%d年%d月%d日距%d年%d月%d日共%d天，此时他在打鱼。\n\n", t.year_(), t.month_(),t.day_(), begin.year_(), begin.month_(), begin.day_(),sum);
		}else fprintf(fp2, "%d年%d月%d日距%d年%d月%d日共%d天，此时他在晒网。\n\n", t.year_(), t.month_(), t.day_(), begin.year_(), begin.month_(), begin.day_(),sum);
		sum = 0;
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
int dayofmon(int year, int mon);
bool leapyear(int year);
class Time {
private:int year, month, day, hour, minute, second;
public:void printTime();
	  Time(int y=0, int mon=1, int d=1, int h=0, int m=0, int s=0);
	  void  setTime(int y, int mon, int d, int h, int m, int s);
	 /* int daysofmon();
	  bool leapyear();*/
	  Time& operator--();
	  Time operator--(int);
	  Time& operator++();
	  Time operator++(int);
	  Time& subonesecond();
	  Time& addonesecond();
	  friend Time operator+(int number, Time t1);
	  friend int operator-(Time t1, Time t2);
};
int dayofmon(int year, int mon) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (!leapyear(year)) {
		a[1] = 29;
	}
	return a[mon - 1];
}
bool leapyear(int year) {
	bool t = 1;
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		t = 0;
	}
	return t;
}

void Time::printTime()
{
	cout << year << "/" << month << "/" << day
		<< " " << setfill('0') << setw(2) << hour
		<< ":" << setw(2) << minute << ":"
		<< setw(2) << second << endl;
}
Time::Time(int y, int mon, int d, int h, int m, int s) {
	year = y; month = mon; day = d; hour = h; minute = m; second = s;
}
void Time::setTime(int y, int mon, int d, int h, int m, int s) {
	year = y; month = mon; day = d; hour = h; minute = m; second = s;
}
Time& Time::subonesecond() {
	if (--second < 0) {
		second = 59;
		if (--minute < 0) {
			minute = 59;
			if (--hour < 0) {
				hour = 23;
				if (--day < 1) {
					if (month-- < 1) {
						month = 12;
						year--;
					}
					day = dayofmon(year,month);
				}
			}
		}
	}
	return *this;
}
Time& Time::addonesecond() {
	if (++second > 59) {
		second = 0;
		if (++minute > 59) {
			minute = 0;
			if (++hour > 23) {
				hour = 0;
				if (++day > dayofmon(year, month)) {
					day = 1;
					if (++month> 12) {
						month = 1;
						year++;
					}
				}
			}
		}
	}
	return *this;
}
Time& Time::operator--() {
	subonesecond();
	return *this;
}
Time& Time::operator++() {
	addonesecond();
	return *this;
}
Time Time::operator--(int) {
	Time temp;
	temp = *this;
	subonesecond();
	return temp;
}
Time Time::operator++(int) {
	Time temp;
	temp = *this;
	addonesecond();
	return temp;
}
//bool Time::leapyear() {
//	bool t=1;
//	if (year% 400 == 0 || year % 4 == 0 && year % 100 != 0) {
//		t = 0;
//	}
//	return t;
//}
//int Time::daysofmon() {
//	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (!leapyear()) {
//		a[1] = 29;
//	}
//	return a[month - 1];
//}
Time operator+(int number, Time t1) {
	int t = number;
	if(t<=0){
		for (; t < 0; t++) {
			t1--;
		}
	}
	else if (t > 0) {
		for (; t > 0; t--) {
			t1++;
		}
	}
	return t1;
}
int operator-(Time t1, Time t2) {
	int i, sumdayt1 = 0, sumdayt2 = 0;
	long long int sum=0;
	for (i = 1; i < t1.month; i++) {
		sumdayt1 += dayofmon(t1.year,i);
	}
	for (i = 1; i < t2.month; i++) {
		sumdayt2 += dayofmon(t2.year,i);
	}
	sum += (sumdayt1 + t1.day - sumdayt2 - t2.day) * 24 * 60 * 60 + (t1.hour - t2.hour) * 60 * 60 + (t1.minute - t2.minute) * 60 + t1.second - t2.second;
	return sum;
}

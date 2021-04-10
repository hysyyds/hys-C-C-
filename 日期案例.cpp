#include<iostream>
using namespace std;
class Cmytime {
	int y, m, d;
public:Cmytime(int year=0, int month=1, int day=1) {
	y = year; m = month; d = day;
}
	  void dayp();//一天后
	  void dayl();//一天前
	  void Show();
	  int dom();
	  bool leap(Cmytime d1);
	  Cmytime operator++(int);
	  Cmytime operator++();
	  Cmytime operator--();
	  Cmytime operator--(int);
	  int year();
	  int month();
	  int day();
	  friend ostream& operator<<(ostream& ot,const Cmytime& t1);
	  friend istream& operator>>(istream& ci,Cmytime& t1);
};
istream& operator>>(istream& ci, Cmytime& t1) {
	ci >> t1.y >> t1.m >> t1.d;
	return ci;
}
ostream& operator<<(ostream& ot, const Cmytime& t1) {
	ot << t1.y << "/" << t1.m << "/" << t1.d;
	return ot;
}
void Cmytime::Show() {
	cout << y << "/" << m << "/" << d;
}
bool Cmytime::leap(Cmytime d1){
	bool a = 1;
	if (d1.y % 400 == 0 || d1.y % 4 == 0 && d1.y % 100 != 0) {
		a = 0;
	}
	return a;
}
int Cmytime::dom() {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (!leap(y)) {
		a[1] = 29;
	}
	return a[m - 1];
}
void Cmytime::dayp() {
	if (++d > dom()) {
		d = 1;
		if (++m > 12) {
			m = 1;
			++y;
		}
	}
}
void Cmytime::dayl() {
	if (--d<=0) {
		if (--m <= 0) {
			m = 12;
			--y;
		}
		d = dom();
	}
}
Cmytime Cmytime::operator++(int) {
	Cmytime d1;
	d1=*this;
	dayp();
	return d1;

}
Cmytime Cmytime::operator++() {
	dayp();
	return *this;
}
Cmytime Cmytime::operator--() {
	dayl();
	return *this;
}
Cmytime Cmytime::operator--(int) {
	Cmytime temp;
	temp = *this;
	dayl();
	return temp;
}
int Cmytime::year() {
	return y;
}
int Cmytime::month() {
	return m;
}
int Cmytime::day() {
	return d;
}
int main() {
	Cmytime t1(2020,1,1),t2;
	t2=--t1;
	cout << t2.year();
	cout<<t2.month();
	cout<<t2.day();
	return 0;
}

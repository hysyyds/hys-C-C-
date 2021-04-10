#include<iostream>
#include<iomanip>
using namespace std;

class Cmycomplex {
private:double x, y;
public:
friend istream& operator>>(istream& ci, Cmycomplex& c);
friend ostream& operator<<(ostream& ci, Cmycomplex c);
Cmycomplex operator+(Cmycomplex& t);
Cmycomplex operator-(Cmycomplex& t);
Cmycomplex operator*(Cmycomplex& t);
Cmycomplex operator/(Cmycomplex& t);

};
istream& operator>>(istream& ci, Cmycomplex& c) {
	ci >> c.x >> c.y;
	return ci;
}
ostream& operator<<(ostream& ci, Cmycomplex c) {
	ci << setiosflags(ios::fixed);
	if (c.y == 0) {
		ci << setprecision(0)<< c.x;
	}
	else if (c.y < 0) {
		ci  << setprecision(2) << c.x << setprecision(2) << c.y << "i";
	}
	else if (c.y > 0) {
		ci << setprecision(2) << c.x <<"+"<< setprecision(2) << c.y << "i";
	}
	return ci;
}
Cmycomplex Cmycomplex::operator+(Cmycomplex& t) {
	Cmycomplex r;
	r.x = x + t.x;
	r.y = y + t.y;
	return r;
}
Cmycomplex Cmycomplex::operator-(Cmycomplex& t) {
	Cmycomplex r;
	r.x = x - t.x;
	r.y = y - t.y;
	return r;
}
Cmycomplex Cmycomplex::operator*(Cmycomplex& t) {
	Cmycomplex r;
	r.x = x * t.x - y * t.y;
	r.y = x * t.y + y * t.x;
	return r;
}
Cmycomplex Cmycomplex::operator/(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = (x * t2.x + y * t2.y) / (t2.x * t2.x + t2.y * t2.y);
	r.y = (-x * t2.y + y * t2.x) / (t2.x * t2.x + t2.y * t2.y);
	return r;
}

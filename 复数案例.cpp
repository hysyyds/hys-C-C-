#include<iostream>
#include<iomanip>
using namespace std;

class Cmycomplex {
public:double x, y;
public:
	 Cmycomplex(double x1 = 1, double y1 = 1);
	  void Show();
	  Cmycomplex Add(Cmycomplex& t2);
	  Cmycomplex operator+(Cmycomplex& t2);
	  void	Set(double x1, double y1);
	  Cmycomplex operator-(Cmycomplex& t2);
	  Cmycomplex operator*(Cmycomplex& t2);
	  Cmycomplex operator/(Cmycomplex& t2);
	  bool operator==(Cmycomplex& t2);
	  bool operator!=(Cmycomplex& t2);
	  friend ostream& operator<<(ostream& ot, Cmycomplex t2);
};
Cmycomplex operator+(Cmycomplex &t2,double a) {
	t2.x += a;
	return t2;
}
ostream& operator<<(ostream& ot, Cmycomplex t2) {
	ot << setiosflags(ios::fixed);
	if (t2.y > 0) {
		ot << "(" << setprecision(2) << t2.x << "+" << setprecision(2) << t2.y << "i" << ")";
	}
	else if (t2.y < 0) {
		ot << "(" << setprecision(2) << t2.x << setprecision(2) << t2.y << "i" << ")";
	}
	return ot;
}
int main()
{
	Cmycomplex t1;
	Cmycomplex t2 = t1+5;
	cout << t2;
	return 0;
}
Cmycomplex::Cmycomplex(double x1 , double y1 ) {
	x = x1; y = y1;
}
void Cmycomplex::Show() {
	cout << setiosflags(ios::fixed);
	if (y > 0) {
		cout << "(" << setprecision(2) << x << "+" << setprecision(2) << y << "i" << ")";
	}
	else if (y < 0) {
		cout << "(" << setprecision(2) << x << setprecision(2) << y << "i" << ")";
	}
}
Cmycomplex Cmycomplex::Add(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = x + t2.x;
	r.y = y + t2.y;
	return r;
}
Cmycomplex	Cmycomplex::operator+(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = x + t2.x;
	r.y = y + t2.y;
	return r;
}
void	Cmycomplex::Set(double x1, double y1) {
	x = x1; y = y1;
}
Cmycomplex Cmycomplex::operator-(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = x - t2.x;
	r.y = y - t2.y;
	return r;
}
Cmycomplex Cmycomplex::operator*(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = x * t2.x - y * t2.y;
	r.y = x * t2.y + y * t2.x;
	return r;
}
Cmycomplex Cmycomplex::operator/(Cmycomplex& t2) {
	Cmycomplex r;
	r.x = (x * t2.x + y * t2.y) / (t2.x * t2.x + t2.y * t2.y);
	r.y = (-x * t2.y + y * t2.x) / (t2.x * t2.x + t2.y * t2.y);
	return r;
}
bool Cmycomplex::operator==(Cmycomplex& t2) {
	return x == t2.x && y == t2.y;
}
bool Cmycomplex::operator!=(Cmycomplex& t2) {
	return x != t2.x || y != t2.y;
}

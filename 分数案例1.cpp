#include<iostream>
#include<cmath>
using namespace std;
class Fraction {
private:int p, q;
public:Fraction(int a=1, int b = 1);
	  void Set(int a, int b);
	  void Show();
	  Fraction reduction();
	  Fraction operator+(const Fraction&);
	  Fraction operator-(const Fraction&);
	  Fraction operator*(const Fraction&);
	  Fraction operator/(const Fraction&);
	  bool operator==(const Fraction& t1);
	  bool operator!=(const Fraction& t1);
	  bool operator<(const Fraction& t1);
	  bool operator<=(const Fraction& t1);
	  bool operator>(const Fraction& t1);
	  bool operator>=(const Fraction& t1);
	  Fraction operator++();
	  Fraction operator++(int);
	  friend ostream& operator<< (ostream& ot,Fraction t1);
	  friend istream& operator>>(istream& ci, Fraction& t1);
};
int gcd(int a, int b);
ostream& operator<<(ostream& ot,Fraction t1) {
	t1.Show();
	return ot;
}
istream& operator>>(istream& ci, Fraction& t1) {
	ci >> t1.p>>t1.q;
	if (t1.p != 0 && t1.q != 0) {
		t1.reduction();
	}
	return ci;
}
Fraction::Fraction(int a,int b) {
		Set(a, b);
}
void Fraction::Set(int a, int b) {
	if (b != 0&&a!=0) {
		p = a; q = b;
		reduction();
	}
	else if (b != 0) {
		p = a; q = b;
	}
}
void Fraction::Show() {
	if (q != 0) {
		if (p != 0) {
			reduction();
			if(q<0){
				p=-p;
				q=-q;
			}
		//	if (q != 1) {
				cout << p << "/" << q;
		//	}
		//	else {
		//		cout << p;
		//	}
		}
		else cout << "0";
	}
}
Fraction Fraction::reduction() {
	int t = gcd(p, q);
	p /= t; q /= t;
	return *this;
}
Fraction Fraction::operator+(const Fraction& t1) {
	Fraction temp;
	temp.p = p * t1.q + q * t1.p;
	temp.q = q * t1.q;
	return temp;
}
Fraction Fraction::operator-(const Fraction& t1) {
	Fraction temp;
	temp.p = p * t1.q - q * t1.p;
	temp.q = q * t1.q;
	return temp;
}
Fraction Fraction::operator*(const Fraction& t1) {
	Fraction temp;
	temp.p = p * t1.p;
	temp.q = q * t1.q;
	return temp;
}
Fraction Fraction::operator/(const Fraction& t1) {
	Fraction temp;
	temp.p = p * t1.q;
	temp.q = q * t1.p;
	return temp;
}
Fraction Fraction::operator++(){
	q += 1;
	return *this;
}
Fraction Fraction::operator++(int) {
	Fraction temp;
	temp = *this;
	q += 1;
	return temp;
}
int gcd(int a, int b) {
	int t=1;
	while (b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
bool Fraction::operator==(const Fraction& t1){
	bool a=0;
	if(p==t1.p&&q==t1.q){
		a=1;
	}
	return a;
}
bool Fraction::operator!=(const Fraction& t1){
	bool a=1;
	if(p==t1.p&&q==t1.q){
		a=0;
	}
	return a;
}
bool Fraction::operator<(const Fraction& t1){
	bool a=0;
	double b,c;
	b=1.0*p/q;
	c=1.0*t1.p/t1.q;
	if(b<c){
		a=1;
	}
	return a;
}
bool Fraction::operator<=(const Fraction& t1){
	bool a=0;
	double b,c;
	b=1.0*p/q;
	c=1.0*t1.p/t1.q;
	if(b<c||fabs(a-b)<=1e-10){
		a=1;
	}
	return a;
}
bool Fraction::operator>=(const Fraction& t1){
	bool a=0;
	double b,c;
	b=1.0*p/q;
	c=1.0*t1.p/t1.q;
	if (b > c || fabs(b - c) <= 1e-10) {
		a=1;
	}
	return a;
}
bool Fraction::operator>(const Fraction& t1){
	bool a=0;
	double b,c;
	b=1.0*p/q;
	c=1.0*t1.p/t1.q;
	if(b>c){
		a=1;
	}
	return a;
}
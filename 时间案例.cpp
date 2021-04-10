#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
class Cmytime {
private:int h, m, s;
public:
Cmytime(int hour=0,int min=0,int sec=0) {
    Set(hour,min,sec);
}
    int Set(int hour, int min,int sec);
    void Show();
    void printTime();
    void  SubOneSecond();
    void  AddOneSecond();
    Cmytime& operator--();
    Cmytime operator--(int);
    Cmytime& operator++();
    Cmytime operator++(int);
    Cmytime operator+(const Cmytime& t1);
    Cmytime operator-(const Cmytime& t1);
 //   friend ostream& operator<<(ostream& ot, Time t1);
 //  friend istream& operator>>(istream& ot, Time t1);
    friend Cmytime operator+(int increase, const Cmytime& t1);
};
int Cmytime::Set(int hour, int min, int sec) {
    int err = 0;
    if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59) {
        err = 1;
        h = hour; m = min; s = sec;
    }
    return err;
}
void Cmytime::Show() {
    cout << h << ":" << m << ":" << s;
}
void Cmytime::printTime()
{
    cout << setfill('0') << setw(2) << h
        << ":" << setw(2) << m << ":"
        << setw(2) << s << endl;
}
void Cmytime::SubOneSecond() {
    if (--s == -1) {
        s = 59;
        if (--m == -1) {
            m = 59;
            if (--h == -1) {
                h = 23;
            }
        }
    }

}
void  Cmytime::AddOneSecond(){
	if(++s==60){
		s=0;
		if(++m==60){
			m=0;
			if(++h==24){
				h=0;
			}
		}
	}
}
Cmytime Cmytime::operator--(int) {
	Cmytime temp;
	temp=*this;
    SubOneSecond();
    return temp;
}//บ๓ืบ
Cmytime& Cmytime::operator--() {
    SubOneSecond();
    return *this;
}
Cmytime& Cmytime::operator++(){
	AddOneSecond();
	return *this;
}
Cmytime Cmytime::operator++(int){
	Cmytime temp;
	temp=*this;
	AddOneSecond();
	return temp;
}
Cmytime Cmytime::operator+(const Cmytime& t1) {
    Cmytime temp;
    int as, am, ah;
    as = s + t1.s;
    am = m + t1.m + as / 60;
    ah = h + t1.h + am / 60;
    temp.s = as % 60;
    temp.m = am% 60;
    temp.h = ah % 24;
    return temp;
}
Cmytime Cmytime::operator-(const Cmytime& t1) {
    Cmytime temp;
    int as;
    as = h * 3600 + m * 60 + s - t1.h * 3600 - t1.m * 60 - t1.s;
    while (as < 0) {
        as = 24 * 3600 + as;
    }
    temp.s = as % 60;
    temp.m = (as - temp.s) % 3600/60;
    temp.h = as / 3600;
    return temp;
}
//ostream& operator<<(ostream& ot, time t1) {
//    ot << t1.h << ":" << t1.m << ":" << t1.s;
//    return ot;
//}
//istream& operator>>(istream& ot, time t1) {
//    ot >> t1.h >> t1.m >> t1.s;
//    return ot;
//}
Cmytime operator+(int increase, const Cmytime& t1) {
    Cmytime temp;
    int as, am, ah;
    as = t1.s + increase;
    am = t1.m + as / 60;
    ah = t1.h + am / 60;
    temp.s =as%60;
    temp.m = am%60;
    temp.h = ah % 24;
        return temp;
}
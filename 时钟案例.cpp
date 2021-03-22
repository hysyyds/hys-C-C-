#include<iostream>
using namespace std;
class Cmytime {
private:int h, m, s,y,mon,d;;
public:Cmytime(int year = 0, int month = 0, int day = 0,int hour=0,int min=0,int sec=0) {
    y = year; mon = month; d = day; h = hour; m = min; s = sec;
}
      int Set(int year, int month, int day, int hour, int min, int sec);
      void Show();
      void  SubOneSecond();
      Cmytime operator--();
      Cmytime operator--(int);
      void dayp();
      int dom();
      bool leap(Cmytime d1);
      Cmytime operator++(int);
      int year();
      int month();
      int day();
};
int Cmytime::Set(int year , int month , int day , int hour , int min , int sec ) {
    int err = 0;
    if (hour >= 0 && hour <= 23 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59&&month>=1&&month<=12&&day>=0&&day<=dom()) {
        err = 1;
        h = hour; m = min; s = sec; y = year; mon = month; d = day;
    }
    return err;
}
void Cmytime::Show() {
    cout <<y<<":"<<mon<<":"<<d<<":"<< h << ":" << m << ":" << s<<endl;
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
Cmytime Cmytime::operator--(int) {
    Cmytime t1;
    t1.Set(y,mon,d,h,m,s);
    SubOneSecond();
    return t1;
}//บ๓ืบ
Cmytime Cmytime::operator--() {
    Cmytime t1;
    SubOneSecond();
    t1.Set(y, mon, d, h, m, s);
    return t1;
}
bool Cmytime::leap(Cmytime d1) {
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
    return a[mon - 1];
}
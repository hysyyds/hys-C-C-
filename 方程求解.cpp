#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Complex {
public: double a, b;
};
int main()
{
    int a, b,c,d;
    double x1, x2;
    cin >> a >> b>>c;
    d = b * b - 4 * a * c ;
    cout << setiosflags(ios::fixed)<<setprecision(3);
    if (d>=0) {
        x1 = (-b + sqrt(d)) / 2 / a;
        x2= (-b -sqrt(d)) / 2 / a;
        cout << "x1" << "=" <<x1<<" "<< "x2" << "=" <<x2;
    }
    else if (d < 0) {
        Complex x1, x2;
        x1.a = -b / 2.0 / a;
        x2.a = x1.a;
        x1.b = sqrt(-d)/2/a;
        x2.b = -x1.b;
        cout << "x1=" << x1.a << "+"  << x1.b << "i";
        cout << " x2="  << x2.a  << x2.b << "i";


    }
    return 0;
}

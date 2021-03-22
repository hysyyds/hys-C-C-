#include<iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) <<" "<< lcm(a, b);
    return 0;
}
int gcd(int a, int b) {
    if (b != 0) {
        gcd(b, a % b);
    }
    else return a;
}
int lcm(int a, int b) {
    return a * b / (gcd(a, b));
}
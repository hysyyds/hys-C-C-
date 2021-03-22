#include<stdio.h>

int main()
{
    double x,y;
    scanf("%lf", &x);
    y = 5 * (x - 32) / 9;
    printf("c=%.2f", y);
    return 0;
}
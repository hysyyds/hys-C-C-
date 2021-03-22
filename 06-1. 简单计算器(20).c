/*
输入格式：

输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式：

在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。

输入样例：
1+2*10-10/2=
输出样例：
10
*/
#include<stdio.h>
int main()
{
	char c;
	double num=0,sum=0;
	int i=0,j=1,err=0;
	do{
		scanf_s("%c", &c,1);
		if (c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
			i = 1;
		}
		else {
			if (i == 0) {
				err = 1;
		}
			i = 0;
		}
		if (i==0) {
			switch (j) {
			case 1:sum += num; break;
			case 2:sum -= num; break;
			case 3:sum *= num; break;
			case 4:if (num != 0) { sum /= num; }
				  else { err = 1; } break;
			}
		}
		if (c == '+') {
			j = 1;
			num = 0;
		}
		else if (c == '-') {
			j = 2;
			num = 0;
		}
		else if (c == '*') {
			j = 3;
			num = 0;
		}
		else if (c == '/') {
			j = 4;
			num = 0;
		}
		else if (i!=1&&c!='=') {
			err = 1;
		}
	} while (c != '=');
	if (!err) {
		printf("%.2f",sum);
	}
	else {
		printf("ERROR");
	}
} 
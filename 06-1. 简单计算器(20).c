/*
�����ʽ��

������һ���и���һ������������ʽ��û�пո���������һ�������������Ⱥš�=��˵�����������

�����ʽ��

��һ���������ʽ�����������������������ĸΪ0���зǷ�������������������Ϣ��ERROR����

����������
1+2*10-10/2=
���������
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
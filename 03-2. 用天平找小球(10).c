#include<stdio.h>

int main() {
	int a, b, c,d;
	scanf_s("%d %d %d",&a,&b,&c);
	if (a = b) {
		d = 3;
	}
	else if (a = c) {
		d = 2;
	}
	else {
		d = 1;
	}
	switch (d) {
	case 1:printf("A");break;
	case 2:printf("B"); break;
	case 3:printf("C"); break;
	}
}
#include<stdio.h>

int main() {
	int n,t,mask=1;
	scanf_s("%d",&n);
	if (n < 0) {
		printf("fu ");
		n = -n;
	}
	t = n;
	while (t > 9) {
		t /= 10;
		mask *= 10;
	}
	do {
		t = n / mask;
		n %= mask;
		mask /= 10;
		switch (t) {
		case  0:printf("ling"); break;
		case  1:printf("yi"); break;
		case  2:printf("er"); break;
		case  3:printf("san"); break;
		case  4:printf("yi"); break;
		case  5:printf("wu"); break;
		case  6:printf("liu"); break;
		case  7:printf("qi"); break;
		case  8:printf("ba"); break;
		case  9:printf("jiu"); break;
		}
		if (mask > 0) {
			printf(" ");
		}
	} while (mask > 0);
	return 0;
}
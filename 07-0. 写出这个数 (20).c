#include<stdio.h>

void dushu(int n);
int main() {
	char n;
	int sum=0;
	do
	{
		scanf_s("%c", &n,1);
		if (n != '\n') {
			sum += n - '0';
		}
	} while (n!='\n');
	dushu(sum);
	return 0;
}
void dushu(int n) {
	int mask=1,t;
	t = n;
	while (t>9) {
		t /=10;
		mask *= 10;
	}
	while (mask> 0) {
		t = n / mask;
		n %= mask;
		switch (t) {
		case 1:printf("yi"); break;
		case 2:printf("er"); break;
		case 3:printf("san"); break;
		case 4:printf("si"); break;
		case 5:printf("wu"); break;
		case 6:printf("liu"); break;
		case 7:printf("qi"); break;
		case 8:printf("ba"); break;
		case 9:printf("jiu"); break;
		case 10:printf("shi"); break;
		}
		if (mask> 9) {
			printf(" ");
		}
		mask /= 10;
	}
}
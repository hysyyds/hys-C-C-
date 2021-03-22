#include<stdio.h>

int main() {
	int i,count=0;
	int x1, x2, x3, x4, x5, x6;
	int j,k,l,minus=1;
	scanf_s("%d", &i);
	int total = (i + 3) * 100 + (i + 2) * 10 + i + 1;
	do {
		j= total % 10;
		k = total / 10 % 10;
		l = total / 100;
		x1 = 100 * i + 10 * j + k;
		x2 = 100 * i + 10 * j + l;
		x3 = 100 * i + 10 * k + j;
		x4 = 100 * i + 10 * k + l;
		x5 = 100 * i + 10 * l + j;
		x6 = 100 * i + 10 * l + k;
		printf("%d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6);
		count++;
		total -= minus;
		minus = minus * 10;//强行不用switch想出的奇怪方法
		i++;
	} while (i!= i -count+ 4);
	return 0;
}
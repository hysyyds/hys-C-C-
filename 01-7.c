#include<stdio.h>

int main() {
	int a, b;
	int sum;
	scanf("%d%d", &a, &b);
	sum = (a - b) * (a + b);
	printf("%d", sum);
	return 0;
}
#include<stdio.h>
int num(int n);
int main() {
	int n;
	while (scanf("%d", &n)&&n) {
		printf("%d\n", num(n));
	}
	return 0;
}
int num(int n) {
	if (n <= 3)
		return n;
	else return num(n - 1) + num(n - 3);
}
#include<stdio.h>

int isPrime(int a);

int main() {
	int m, n;
	int cnt=0,i,j=0;
	scanf_s("%d%d", &m, &n);
	for (i = 2; cnt < n; i++) {
		if (isPrime(i)) {
			cnt++;
			if (cnt >= m) {
				printf("%d", i);
				j++;
				if (j == 10) {
					printf("\n");
					j = 0;
				}
				else if (cnt < n) {
					printf(" ");
				}
			}
		}
	}
	return 0;
}
int isPrime(int a) {
	int i;
	int prime = 1;
	for (i = 2; i < a; i++) {
		if (a % i == 0) {
			prime = 0;
			break;
		}
	}
	return prime;
}
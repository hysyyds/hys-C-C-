#include<stdio.h>

int main()
{
	int x,n,cnt=0;
	int isPrime = 1;//xÊÇËØÊı
	int i;
	scanf_s("%d", &n);
	for (x = 1; cnt<n; x++) {
		for (i = 2; i < x; i++) {
			if (x % i == 0) {
				isPrime = 0;
			}
		}
		if (isPrime == 1) {
			printf("%d\t", x);
				cnt++;
				if (cnt % 5 == 0) {
					printf("\n");
				}
		}
		isPrime = 1;
	}
	return 0;
} 
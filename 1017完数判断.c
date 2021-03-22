#include<stdio.h>
int main(int argc, char* argv[]) {
	long long n;
	long long i,j;
	scanf("%lld", &n);
	for (i = 6; i < n; i++) {
		if (i % 10 == 6 || i % 10 == 8&&i%100==28) {
			long long sum=0;
			for (j = 1; j <= i / 2; j++) {
				if (i % j == 0) {
					sum += j;
				}
			}
			if (sum == i) {
				printf("%lld its factors are ", i);
				for (j = 1; j <= i / 2; j++) {
					if (i % j == 0) {
						printf("%lld ", j);
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
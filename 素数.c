#include<stdio.h>

int isPrime(int x, int Knownnprime[], int numberOfprime);

int main() {
	const int number = 200000;
	int prime[number] = { 2 };
	int cnt = 1;
	int i;
	for (i = 3; cnt < number; i++) {
		if (isPrime(i, prime, cnt)) {
			prime[cnt++] = i;
		}
	}
	for(i=0;i<number;i++){
		printf("%d\t", prime[i]);
		if (i < number - 1) {
			printf(" ");
		}
		if ( (i+1) % 5 == 0) {
			printf("\n");
		}
	}
	return 0;
}
int isPrime(int x, int Knownnprime[], int numberOfprime)
{
	int i;
	int ret = 1;
	for (i = 0; i < numberOfprime; i++) {
		if (x % Knownnprime[i] == 0) {
			ret = 0;
			break;
		}
	}
	return ret;
}
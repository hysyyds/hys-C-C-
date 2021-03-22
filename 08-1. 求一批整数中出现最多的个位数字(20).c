#include<stdio.h>

void count(int n, int a[]);
int main() {
	const int a_number = 10;
	int n,i,number;
	int t = 0;
	scanf_s("%d", &n);
	int a[a_number] = { 0 };
	for (i = 0; i < n; i++) {
		scanf_s("%d", &number);
		count(number , a);
	}
	for (i = 0; i < a_number; i++) {
		if (a[i] > t) {
			t = a[i];
		}
	}
	printf("%d:", t);
	for (i = 0; i < a_number; i++) {
		if (a[i] == t) {
			printf("%d", i);
			if (i < 9) {
				printf(" ");
			}
		}
	}
	return 0;
}
void count(int n, int a[]) {
	int t;
	while (n > 0) {
		t =n%10;
		n /= 10;
		a[t]++;
	}
}
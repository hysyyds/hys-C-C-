#include<stdio.h>

int main() {
	int n,x;
	int a[20];
	int i;
	scanf_s("%d", &n);
	scanf_s("%d", &x);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		if (x == a[i]) {
			break;
		}
	}
	if (i == n) {
		printf("Not Found");
	}
	else {
		printf("%d", i);
	}
	return 0;
}

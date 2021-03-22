#include<stdio.h>

int main() {
	const int number = 10;
	int i,j;
	int a[number];
	for (i = 0; i < number; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 1; i < number; i++) {
		if (a[i]) {
			a[i] -= 1;
			printf("%d", i);
			break;
		}
	}
	for (i = 0; i < number; i++) {
		for (j = 0; j < a[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}
#include<stdio.h>

int main() {
	int a[10];
	int i,j;
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 9; i >0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				int t;
				t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
		printf("%d", a[i]);
		if (i < 10) {
			printf(" ");
		}
	}
	return 0;
}
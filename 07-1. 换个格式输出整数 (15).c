#include<stdio.h>

int main() {
	int n,t,i=1;
	int mask = 1;
	scanf_s("%d",&n);
	t = n;
	while (t > 9) {
		t /= 10;
		mask *= 10;
	}
	while (mask > 0) {
		t = n / mask;
		n %= mask;
		while (t > 0) {
			if (mask ==100) {
				printf("B");
				t--;
			}
			else if (mask == 10) {
				printf("S");
				t--;
			}
			else if (mask == 1) {
				printf("%d", i);
				i++;
				t--;
			}
		}
		mask /= 10;
		i = 1;
	}
	return 0;
}
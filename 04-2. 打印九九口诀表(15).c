#include<stdio.h>

int main() {
	int x;
	int count=0,count1=1;
	scanf_s("%d", &x);
	do {
		count++;
		while (count1 <= count) {
			if (count1<count){ 
			printf("%d*%d=%d", count1, count, count1 * count);
			if (count1 * count > 9) {
				printf("  ");
			}
			else {
				printf("   ");
			}
			count1++;
			}
			else {
			printf("%d*%d=%d\n", count1, count, count1 * count);
			count1++;
			}
		}
		count1 = 1;
	} while (count != x);
}
#include<stdio.h>

int main() {
	int a[5];
	int cnt=0,i,temp;
	for (i = 0; i < 5; i++) {
		temp = getchar();
		if (temp == '\n') break;
		cnt++;
		a[i] = temp;
		
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++) {
		putchar(a[i]);
		if (i < cnt - 1) {
			putchar(' ');
		}
		else putchar('\n');
	}
	for (i = cnt - 1; i >= 0; i--) {
		putchar(a[i]);
	}
}
#include<stdio.h>

int main()
{
	int x,i,j,k;
	scanf_s("%d", &x);
	j = x;
	for (i = 0; j != 0; i++) {
		j /= 10;
	}
	for (; i >0; i--) {
		j = x;
		for (k = 1;i>k; k++) {
			j = j / 10;
		}
		j = j % 10;
		printf("%d", j);
		if (i != 1) {
			printf(" ");
		}
	}
} 
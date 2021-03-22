#include<stdio.h>

int main() {
	const int number = 10;
	int n;
	int i;
	int a[number];
	for (i = 0; i < number; i++) {
		a[i] = 0;
	}
	do {
		scanf("%d",&n);
		if(n>-1&&n<10){
			a[n]++;
		}
	}while(n != -1);
	for (i = 0; i < number; i++) {
		printf("%d:%d",i, a[i]);
		if (i != 9){
			printf(" ");
		}
	}

	return 0;
}
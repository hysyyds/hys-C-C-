#include<stdio.h>

int main() {
	int a, n,i,sum=0,t=0;
	scanf("%d %d",&a,&n);
	for (i = 0; i < n; i++) {
		t = t * 10 + a;
		sum += t;
	}
	printf("%d", sum);
	return 0;
}
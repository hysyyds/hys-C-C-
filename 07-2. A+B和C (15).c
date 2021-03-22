#include<stdio.h>
void compare(int a, int b, int  c, int d);
int main() {
	int cnt=0;
	int n;
	int a, b, c;
	scanf_s("%d",&n);
	while (cnt < n) {
		cnt++;
		scanf_s("%d%d%d", &a, &b, &c);
		compare(cnt, a, b, c);
	}
	return 0;
}
void compare(int a, int  b, int  c, int  d) {
	if (b + c > d) {
		printf("Case #%d: true\n", a);
	}
	else {
		printf("Case #%d: false\n", a);
	}
}
#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int a[1000] = { 0 }, b;
	int i;
	for (i = 0; i < 10; i++) {
		scanf("%d", &b);
		a[b]++;
	}
	for (i = 0; i < 1000; i++) {
		while (a[i]) {
			printf("%d", i);
			a[i]--;
		}
	}
	return 0;
}
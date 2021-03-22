#include<iostream>
using namespace std;

int main() {
	int i,j;
	int a[10];
	for (i = 1; i < 10; i++) {
		cin >> a[i];
	}
	for (i = 9; i > 0; i--) {
		for (j = 9; j > 9 - i; j--) {
			if (a[j] < a[j - 1]) {
				int t;
				t = a[j];
				a[j] = a[j-1];
				a[j - 1] = t;
			}
		}
		cout << a[9 - i]<<" ";
	}
	cout << a[9];
	return 0;
}
#include<iostream>
using namespace std;

int main() {
	int i, j,sum1=0,sum2=0;
	int a[3][3];
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cin >> a[i][j];
			if (i == j) {
				sum1 += a[i][j];
			}
			if (i + j == 2) {
				sum2 += a[i][j];
			}
		}
	}
	cout << sum1<<" "<< sum2;
	return 0;
}
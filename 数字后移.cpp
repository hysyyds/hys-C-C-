#include<iostream>
using namespace std;
void function(int** a, int len, int m);
int main(int argc, char** argv) {
	int len,m,i;
	cin >> len;
	int* a = new int[len];
	for (i = 0; i < len; i++) {
		cin >> a[i];
	}
	cin >> m;
	function(&a, len, m);
	for (i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	delete[] a;
	return 0;
}
void function(int** a, int len, int m) {
	int i;
	int *temp = new int[len];
	for (i = m ; i < len; i++) {
		temp[i] = (*a)[i - m ];
	}
	for (i = 0; i < m ; i++) {
		temp[i] = (*a)[len - m + i];
	}
	delete [] *a;
	*a = temp;
}
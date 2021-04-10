#include<iostream>
template<typename T>
void QuickSort(T* a, int Left, int Right);
int main() {
	int a[] = { 5,9,9,7,5,3,4,2,1 };
	QuickSort(a, 0, 8);
	int i;
	for (i = 0; i < 9; i++) {
		std::cout << a[i];
	}
	return 0;
}
template<typename T>
void QuickSort(T* a, int Left, int Right) {
	int i, j;
	if (Left > Right) {
		return ;
	}
	i = Left; j = Right;
	T base = a[Left];
	while (i != j) {
		while (a[j] >= base&&i<j) {
			j--;
		}
		while (a[i] <= base&&i<j) {
			i++;
		}
		if (i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[Left] = a[i];
	a[i] = base;
	QuickSort(a,Left, i-1);
	QuickSort(a,i+1, Right);
	return ;
}
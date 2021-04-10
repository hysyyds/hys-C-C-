#include<iostream>

template<typename T>
class DynamicArray {
	T* array;
	int Size;
	int begin;
public:DynamicArray(const T& content, int size=0, int begin=0);
	  DynamicArray() { array = NULL; Size = 0; begin = 0; };
	  ~DynamicArray();
	  DynamicArray(const DynamicArray<T>& OneArray);
	  T& operator[](int a)const;
	  DynamicArray<T>& operator=(const DynamicArray& OneArray);
	  int resize(unsigned int newSize, const T& ValOfNewItems);
};
template <typename T>
DynamicArray<T>::DynamicArray(const T& content, int size , int begin ) {
	this->array = new T[size];
	this->begin = begin;
	this->Size = size;
	int i;
	for (i =0 ; i < this->Size; i++) {
		this->array[i] = content;
	}
}
template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[]this->array;
	this->array = NULL;
}
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& OneArray) {
	this->Size = OneArray.Size;
	this->begin = OneArray.begin;
	this->array = new T[Size];
	int i;
	for (i = 0; i < this->Size; i++) {
		this->array[i] = OneArray->array[i];
	}
}
template<typename T>
T& DynamicArray<T>::operator[](int a)const {
	return this->array[a - this->begin];
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& OneArray) {
	this->Size = OneArray.Size;
	this->begin = OneArray.begin;
	delete[]this->array;
	this->array = new T[this->Size];
	int i;
	for (i = begin; i < begin + Size; i++) {
		(*this)[i] = OneArray[i];
	}
	return *this;
}
template<typename T>
int DynamicArray<T>::resize(unsigned int newSize, const T& ValOfNewItems) {
	cout << "\nresize is called";
	int signal = 0, i;
	if (mallocSize < newSize) {
		signal = 1;
		T* temp;
		temp = new T[newSize];
		for (i = 0; i < mallocSize; i++) {
			temp[i] = array[i];
		}
		for (i = mallocSize; i < newSize; i++) {
			temp[i] = ValOfNewItems;
		}
		mallocSize = newSize;
		delete[]array;
		array = temp;
	}
	else if (mallocSize > newSize) {
		signal = -1;
		T* temp;
		temp = new T[newSize];
		for (i = 0; i < newSize; i++) {
			temp[i] = array[i];
		}
		delete[]array;
		mallocSize = newSize;
		array = temp;
	}
	return signal;
}

int main(int argc, char** argv) {
	DynamicArray<int> a(2, 2, -1),b;
	DynamicArray<DynamicArray<int>>c(a, 2, -1);
	std::cout << c[-1][-1];
	return 0;
}
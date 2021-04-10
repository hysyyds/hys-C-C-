#include<iostream>
#include<new>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
class Point{
	int x, y;
public:
	//constructor£¬ cout<<"\nPoint is called!";  
	Point(int x=0,int y=0) {
		this->x = x;
		this->y = y;
		cout << "\nPoint is called!";
	}
	//deconstructor£¬    cout<<"\n~Point is called!";
	~Point() {
		cout << "\n~Point is called!";
	}
	//cout <<  overload        "("<<p.x<<","<<p.y<<")";
	friend ostream& operator<<(ostream& ot,const Point& p);
};
template <typename T>
class DynamicArray{
private:
	T* array; //pointer  £¬
	unsigned int mallocSize; //

public:
	//Constructors 
	// cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	DynamicArray(unsigned length, const T& content);
	DynamicArray() { mallocSize = 0; array = NULL; };// mallocSize=length, and the new element is  content
	//Copy Constructor
	// cout<<endl<< "Copy Constructor is called";
	DynamicArray(const DynamicArray<T>& anotherDA);
	 
	// Destructors
	// cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	~DynamicArray();

	//return the this->mallocSize
	unsigned int capacity() const;

	// for the array[i]=someT.
	T& operator[](unsigned int i);
	DynamicArray<T>& operator= (const DynamicArray<T>& anotherDA);
	int resize(unsigned int newSize, const T& ValOfNewItems);
};
ostream& operator<<(ostream& ot,const Point& p) {
	ot<< "(" << p.x << "," << p.y << ")";
	return ot;
}
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& anotherDA)
{
	int i;
	mallocSize = anotherDA.mallocSize;
	cout << endl << "operator = is called";
	if (this != &anotherDA) {
		delete[]array;
		array = new T[mallocSize];
		for (i = 0; i < mallocSize; i++) {
			array[i] = anotherDA.array[i];
		}
	}
	return *this;
}
template <typename T>
DynamicArray<T>::DynamicArray(unsigned length, const T& content) {
	int i;
	mallocSize = length;
	cout << endl << "new T[" << this->mallocSize << "] malloc " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	array = new T[length];
	for (i = 0; i < length; i++) {
		array[i] = content;
	}
}
template <typename T>
DynamicArray<T>::~DynamicArray() {
	cout << endl << "delete[] array free " << this->mallocSize << "*" << sizeof(T) << "=" << this->mallocSize * sizeof(T) << " bytes memory in heap";
	delete[] array;
	array = NULL;
}
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& anotherDA) {
	int i;
	mallocSize = anotherDA.mallocSize;
	cout << endl << "Copy Constructor is called";
	array=new T[mallocSize];
	for (i = 0; i < mallocSize; i++) {
		array[i] = anotherDA.array[i];
	}
}
template <typename T>
unsigned int DynamicArray<T>::capacity() const {
	return this->mallocSize;
}
template <typename T>
T& DynamicArray<T>::operator[](unsigned int i){
	return array[i];
}
template <typename T>
int DynamicArray<T>::resize(unsigned int newSize, const T& ValOfNewItems) {
	cout << "\nresize is called";
	int signal=0,i;
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
	}else if (mallocSize > newSize) {
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
//StudybarCommentBegin
int main()
{
	int i, j;
	DynamicArray<int>  a(20, 0);
	DynamicArray<DynamicArray<int> > b(10, a);
	b[0].resize(30, 1);
	b[5].resize(10, 5);
	for (i = 0; i < 10; i++)
	{
		cout << "\n";
		for (j = 0; j < b[i].capacity(); j++)
		{
			cout << " " << b[i][j];
		}
	}
	return 0;
}
//StudybarCommentEnd
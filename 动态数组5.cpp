#include<iostream>
using namespace std;
template<typename T>
class DynamicArray
{
	private:
		int mallocSize;
	    T *array;
	public:
		DynamicArray(int a,const T& b);
		DynamicArray();
		~DynamicArray();
		DynamicArray &operator =(const DynamicArray<T>& x) ;
		int capacity();	
		T& operator[](int index);
		int resize(unsigned int newSize, const T& ValOfNewItems) ;
} ;
template<typename T>
DynamicArray<T>::DynamicArray()
{
	array=NULL; 
	mallocSize=0;
}
template<typename T>
DynamicArray<T>::DynamicArray(int len,const T& b)
{
	int i;
	this->mallocSize=len;
	cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	array=new T[this->mallocSize];
	for(i=0;i<this->mallocSize;i++)
	{
		array[i]=b;
	}
}
template<typename T>
DynamicArray<T>::~DynamicArray()
{delete [] array;
	cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
    

}
template<typename T>
DynamicArray<T>&DynamicArray<T>::operator =(const DynamicArray<T> & x)
{
	cout<<endl<<"operator = is called";
	if(this==&x)
	return *this;
	else
	{
	delete[] array;
	this->mallocSize=x.mallocSize;
	array=new T[this->mallocSize];
	int i;
	for(i=0;i<this->mallocSize;i++)
	{
		array[i]=x.array[i];
	}
    
    return *this;
	}
}

template<typename T>
int DynamicArray<T>::capacity()
{
	return mallocSize;
}
template<typename T>
T& DynamicArray<T>::operator[](int index)
{
	return array[index];
}
template<typename T>
int DynamicArray<T>::resize(unsigned int newsize, const T& ValOfNewItems) 
{
	cout<<endl<<"resize is called";
	int i;
	if(newsize>mallocSize)
	{
		T* temp=new T[newsize];
		for(i=0;i<mallocSize;i++)
		{
			temp[i]=array[i];
		}
		for(i=mallocSize;i<newsize;i++)
		temp[i]=ValOfNewItems;
		delete []array;
		array=temp;
		mallocSize=newsize;
		return 1;
	}
	else if(newsize==mallocSize)
	{
		return 0;
	} 
	if(newsize<mallocSize)
	{   
	    mallocSize =newsize;
		T* temp=new T[newsize];
		//temp[0]=p[0];
		for(i=0;i<newsize;i++)
		temp[i]=array[i];
		delete []array;
		array=temp;
		return -1;
	}
}
int main()
{
	int i,j;
	DynamicArray<int>  a(20,0);	
	DynamicArray<DynamicArray<int> > b(10,a);
	b[0].resize(30,1);
	b[5].resize(10,5);
	for(i=0;i<10;i++)
	{	cout<<"\n";		
		for(j=0;j<b[i].capacity();j++)
		{	cout<<" "<<b[i][j] ;}
	}
	return 0;
}

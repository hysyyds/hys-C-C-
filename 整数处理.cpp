/*����10����������������С�������һ�����Ի����������������һ�����Ի���д���������� ������10�������ڽ��д��������10������*/
#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
void tenin(int*a);
void change(int*a);
void tenout(int*a);
int main(int argc,char** argv){
int a[10];
tenin(a);
change(a);
tenout(a);
return 0;
}
void tenin(int*a){
	int i;
	for(i=0;i<10;i++){
		cin>>a[i];
	}
}
void change(int*a){
	int max=a[0],min=a[0],i,max_i=0,min_i=0;
	for(i=0;i<10;i++){
		if(max<a[i]){
			max=a[i];
			max_i=i;
		}
		if(min>a[i]){
			min=a[i];
			min_i=i;
		}
	}
	if(a[0]==max){
	max_i = min_i;
	}
	a[min_i] = a[0];
	a[max_i] = a[9];
	a[0] = min;
	a[9] = max;

}
void tenout(int*a){
	int i;
	for(i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}


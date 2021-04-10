#include<iostream>
using namespace std;
int main()
{   int a,i,j;
	int* p=new int[100000000];
	memset(p,0,100000000);
	int* cnt = new int[100000000];
	memset(cnt, 0, 100000000);
	cin>>a;
	for(i=2;i<=a;i++){
		if(!p[i]){
			cnt[++cnt[0]]=i;
		}
		for(j=1;j<=cnt[0]&&i*cnt[j]<=a;j++){
			p[i*cnt[j]]=1;
			if(i%cnt[j]==0){
				break;
			}
		}
	}
	for(i=1;i<=cnt[0];i++){
		cout<<cnt[i]<<endl;
	}
	cout<<cnt[0]<<endl;
	delete[]p;
	delete[]cnt;
 	system("pause");
  
    return 0;
}

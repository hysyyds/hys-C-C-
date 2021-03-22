#include<stdio.h>

int main() {
	const int number = 200000;
	int Notprime_bool[number] = {1,1};//number 2=2;
	int i,j,cnt=0;
	for (i = 2; i < number; i++) {
		if (!Notprime_bool[i]) {
			for (j = 2; i * j < number; j++) {
				Notprime_bool[i * j] = 1;
			}
		}
	}
	for (i = 0; i < number; i++) {
		if (!Notprime_bool[i]) {
			printf("%d\t", i );
			cnt++;
			if (cnt% 5==0) {
				printf("\n");
			}
		}
	}
	printf("\n¹²ÓĞ:%d", cnt);
	return 0;
}
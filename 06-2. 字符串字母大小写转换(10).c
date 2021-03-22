#include<stdio.h>

int main(){
	char c;
	do {
		scanf_s("%c",&c, 1);
		if (c >= 'a' && c <= 'z') {
			c = c - 'a' + 'A';
			printf("%c", c);
		}
		else if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
			printf("%c", c);
		}
		else if(c!='#'){
			printf("%c", c);
		}
	} while (c != '#');
}
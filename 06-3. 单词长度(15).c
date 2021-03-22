#include<stdio.h>

int main() {
	char c;
	int cnt=0,k=0,err=0;
	do {
		scanf_s("%c",&c, 1);
		if (c == ' ' || c == '.') {
			if(err){ k++; }
		}
		if (c != ' ') {
			if (cnt!=0&&k != 0) {
				printf("%d", cnt);
				if (c != '.') {
					printf(" ");
				}
				cnt = 0;
				k = 0;
			}
			if (c != '.') {
				err++;
				cnt++;
			}
		}
	} while (c != '.');
	if (!err) {
		printf("ERROR");
	}
}
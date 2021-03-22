#include<stdio.h>
#include<string.h>

int main() {
	char a[80];
	char* b[80] = {0};
	int i = 0,j=0;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') {
			b[j] = &a[i];
			j++;
		}
	}
	for (i = 0; i < j; i++) {
		*b[i] = '\0';
	}
	for (i = j-1; i >=0; i--) {
		if (*(b[i] + 1) != '\0') {
			b[i] += 1;
			printf("%s ", b[i]);
		}
	}
	printf("%s", a);
	return 0;
}
#include<stdio.h>
#include<string.h>

int main() {
	char a[80];
	char* p = NULL;
	gets(a);
	p = a + strlen(a);
	while (1) {
		if (p == a) {
			printf("%s", p);
			break;
		}
		if (*p == ' ') {
			*p = '\0';
			if (*(p+1)!='\0') {
				printf("%s ", (p + 1));
			}
		}
		p--;
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Replace(char** str) {
	
	int i, l=0,len=strlen(*str);
	for (i = 0; i < len; i++) {
		if ((*str)[i] == ' ') {
			l++;
		}
	}
	char* p;
	int at=0;
	p = (char*)malloc(sizeof(char) * (len + l+1));
	for (i = 0; i < len; i++) {
		if ((*str)[i] == ' ') {
			p[at++] = '%';
			p[at++] = 's';
		}
		else p[at++] = (*str)[i];
	}
	p[at] = '\0';
	*str = p;
}
int main(int argc, char** argv) {
	char* a="hello world!";
	Replace(&a);
	printf("%s", a);
	return 0;
}
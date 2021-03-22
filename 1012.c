#include <stdio.h>

int main() {
	int num=0, ch=0, spc=0, oth=0;
	int i;
	while ((i = getchar()) != '\n') {
		if (i >= '0' && i <= '9') {
			num++;
		}
		else if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z') {
			ch++;
		}
		else if (i == ' ') {
			spc++;
		}
		else {
			oth++;
		}
	}
	printf("%d %d %d %d", ch, num, spc, oth);
	return 0;
}
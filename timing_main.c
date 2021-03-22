#include<stdio.h>
#include"timing.h"

int main() {
	Stime now;
	Stime* p;
	int gap_time,i;
	p = &now;
	while (scanf_s("%d", &gap_time) != EOF) {
		while (gettime(p) == NULL) {
			p = &now;
		}
		for (i = 0; i < gap_time; i++) {
			tomorrow(p);
		}
		if (gap_time == 1) {
			printf("%d day later is %d-%d-%d\n", gap_time, now.year, now.month, now.day);
		}
		else {
			printf("%d days later is %d-%d-%d\n", gap_time, now.year, now.month, now.day);
		}
	}
	return 0;
}


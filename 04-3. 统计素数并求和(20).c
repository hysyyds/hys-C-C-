#include<stdio.h>

int main() {
	int m, n;
	int sum=0, count=0;
	int number1, number2,number3;
	int p;
	scanf_s("%d %d", &m, &n);
	number1 = m-1;
	while (number1 < n) {
		p = 1;
		number2 = 2;
		number1++;
		if (number1 == 1)
			p = 0;
		if (number1 == 2)
			p = 0;
		while (number2 < number1) {
			number3 = number1 / number2;
			if (number2 * number3 == number1)
				p = 0;
			number2++;
		}
		if (p == 1) {
			sum += number1;
			count++;
		}
	}
	printf("%d %d", count, sum);
}
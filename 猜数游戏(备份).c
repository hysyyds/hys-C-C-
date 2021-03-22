#include<stdio.h>
#include<stdlib.h>;
#include<time.h>
//和要求不同的版本
int main()
{
	srand(time(0));
	//int a = rand() % 100 + 1;
	int a = 50;
	int count=0,number,n;
	scanf_s("%d %d", &number, &n);
	if (n <=1) {
		if (number != a) {
			count = -1;
			if (number >= 0) {
				if (a > number) {
					printf("Too small\n");
				}
				else if (a < number) {
					printf("Too big\n");
				}
				else {}
			}
		}else {
			count = 1;
		}
	}else{
		if (number >= 0) {
			count++;
			if (a > number) {
				printf("Too small\n");
			}
			else if (a < number) {
				printf("Too big\n");
			}
		}
		else {
			count = -1;
		}
	}
	if (count > 0) {
		if (count < n) {
			while (a != number)
			{
				if (count < n) {
					scanf_s("%d", &number);
					if (number >= 0) {
						count++;
						if (a > number) {
							printf("Too small\n");
						}
						else if (a < number) {
							printf("Too big\n");
						}
					}
					else {
						count = -1;
						number = a;
					}
				}else {
					count = -1;
					number = a;
				}
			}
		}
	}
	if (count > 0) {
		switch (count) {
		case 1:
		case 2:printf("Bingo!"); break;
		case 3:
		case 4:printf("Lucky You!"); break;
		default:printf("Good Guess!"); break;
		}
	}else{
		printf("Game Over");
	}
	return 0;
} 
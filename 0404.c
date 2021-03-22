#include<stdio.h>

int main() {
	int n, r;
	scanf_s("%d %d",&r,&n);
	int cnt = 0;
	int inp;
	int finished = 0;
	do {
		scanf_s("%d", &inp);
		cnt++;
		if (inp < 0) {
			printf("Game Over\n");
			finished = 1;
		}
		else if (inp > r) {
			printf("Too big\n");
		}
		else if (inp < r) {
			printf("Too small\n");
		}
		else {
			if (cnt == 1) {
				printf("Bingo!\n");
			}
			else if (cnt <= 3) {
				printf("Lucky you");
			}
			else {
				printf("Good Guess!\n");
			}
			finished = 1;
		}
		if (cnt == n) {
			if (!finished) {
				printf("Game Over");
				finished = 1;
			}
		}
	} while (!finished);
	return 0;
}
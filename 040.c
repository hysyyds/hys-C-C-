#include<stdio.h>

int main() {
	int a;
	scanf_s("%d",&a);
	int i, j, k;
	int count=0;
	i = a;
	while (i <= a + 3) {
		j = a;
		while (j <= a + 3) {
			k = a;
			while (k <= a + 3) {
				if (k != j) {
					if (i != k) {
						if (i != j) {
							printf("%d", 100 * i + 10 * j+k);
							count++;
								if (count == 6) {
									printf("\n");
									count = 0;
								}
								else {
									printf(" ");
								}
						}
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
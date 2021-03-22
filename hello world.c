#include<stdio.h>

int main()
{
	int price=0;
	int amount = 100;
	printf("请输入金额\n");
	scanf_s("%d", &price);
	print("请输入票面\n");
	scanf_s("%d", &amount);
	int change = amount - price;
	printf("找%d元\n", change);
}

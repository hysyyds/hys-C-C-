#include<stdio.h>

int main()
{
	int price=0;
	int amount = 100;
	printf("��������\n");
	scanf_s("%d", &price);
	print("������Ʊ��\n");
	scanf_s("%d", &amount);
	int change = amount - price;
	printf("��%dԪ\n", change);
}

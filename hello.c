#include<stdio.h>
int main()
{
	int a[11], i, j,t;
		printf("请输入10个数\n");
		for (i = 1;i < 11;i++)
			scanf_s("%d",&a[i]);
		for(i=1;i<10;i++)
			for(j=1;j<11-i;j++)
				if (a[j] > a[j + 1])
				{
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
		printf("结果为\n");
		for (i = 1; i <= 10; i++)
			printf("%d\n", a[i]);
		return 0;
}
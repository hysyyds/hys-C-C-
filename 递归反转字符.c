#include <stdio.h>
int main()
{
	void add();
	add();
	return 0;
}
void add()
{
	char c;
	scanf("%c", &c);
	if (c != '\n')
	{
		add();
		printf("%c", c);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, i, x = 0, y = 1, tmp = 0;
	char str[128];

	printf("Emaidazu zenbaki arrunt bat:");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	for (i = 2; i < n; i++)
	{
		tmp = x + y;
		x = y;
		y = tmp;
	}
	printf("%d", tmp);
	printf("\n");
	printf("Sakatu \"return\" amaitzeko...");
	fgets(str, 128, stdin);
	return 0;
}
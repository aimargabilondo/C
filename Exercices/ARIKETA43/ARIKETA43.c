#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	
	float i = 0, Gehiketa = 0;
	char str[128];


	do {
		i++;
		Gehiketa += 1 / i;
		
	} while (Gehiketa < 3);
	
	printf("%f", i);
	printf("\n");
	printf("Sakatu \"return\" amaitzeko...");
	fgets(str, 128, stdin);
	return 0;
}
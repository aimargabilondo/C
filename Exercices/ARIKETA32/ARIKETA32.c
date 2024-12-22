#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Hondarra = 1, i=0;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	while (n > 0) { 
		n = n / 10;
		i++;
	}
	printf("Zenbakiak %d digitu ditu", i);
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  n;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	if (n < 0) {
		n = n * -1;
	}
	printf("Balio absolutua: %d", n);
	
	return 0;
}
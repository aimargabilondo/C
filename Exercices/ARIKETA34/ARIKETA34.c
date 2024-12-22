#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Kont = 0, i;
	char str[128];

	printf("Zenbaki bat sartu: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		
		Kont += i;
		if (Kont > 500) {
			printf("500 baino gehiago lortzeko %d zenbaki arte.", i);
			i = n;
		}
		
	}
	if (Kont < 500) {
		printf("Zenbaki horrekin ezin da 500 baino gehiago lortu");
	}

	return 0;
}
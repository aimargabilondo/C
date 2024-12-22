#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, Biderketa = 1, n;
	char str[128];


	printf("Zenbaki bat sakatu : ");
	scanf("%d", &n);
	
	if (n == 0) {
		printf("Faktoriala 1 da.");
	}

	for (i = n; i > 0; i--) {
		Biderketa = Biderketa * i;
	}

	printf("Faktoriala %d\n", Biderketa);
	


	return 0;
}
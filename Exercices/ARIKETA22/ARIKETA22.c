#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	char str[128];

	printf("Zenbakia sakatu : ");
	scanf("%d", &n);

	if (n < 0) {
		printf("Zenbakia negatiboa da.");
	}
	else {
		printf("Zenbakia positiboa da.");
	}
	
	return 0;
}
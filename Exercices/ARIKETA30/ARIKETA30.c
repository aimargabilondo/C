#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	float n;
	char str[128];

	printf("Soldata gordina: ");
	scanf("%f", &n);

	if (n < 15001) {
		n = n * 0.90;
	}
	else {
		n = n * 0.84;
	}
	printf("Soldata garbia: %f", n);

	return 0;
}	
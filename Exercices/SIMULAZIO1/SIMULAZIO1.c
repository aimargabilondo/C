#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i=1;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	for (i = 1; i < n; i++) {

		if (i % 3 == 0 || i % 5 == 0) {
			if (n % i == 0) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}
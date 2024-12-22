#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, kapikua = 0, zenb;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	zenb = n;
	while (zenb > 0) {
		kapikua = kapikua * 10 + zenb % 10;
		zenb = zenb / 10;
	}

	if (kapikua == n) {
		printf("Kapikua da.\n");
	}
	else {
		printf("EZ da kapikua.\n");
	}

	return 0;
}
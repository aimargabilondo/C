#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i,n;
	char str[128];

	printf("Zenbat gradu daude:\n ");
	scanf("%d", &i);

	printf("KELVINETAN NAHI BADEZU 1 SAKATU, FARENHEITETAN NAHI BADEZU 2 SAKATU:\n");
	scanf("%d", &n);

	if (n == 1) {
		i = i + 273;
		printf("\n%d Gradu Kelvin", i);
	}
	else {
		i = i + 56;
		printf("\n%d Gradu Farenheit", i);
	}

	return 0;
}
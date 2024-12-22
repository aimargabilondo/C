#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	char str[128];

	printf("Zenbakia eman:\n ");
	scanf("%d", &n);
	
	if (n % 2 == 0) {
		printf("Bikoitia da");
	}
	else {
		printf("Bakoitia da");
	}

	return 0;
}
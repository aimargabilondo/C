#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	char str[128];

	printf("Zenbakia sakatu : ");
	scanf("%d", &n);

	if (n % 2 == 0) {
		printf("Zenbakia BIKOITIA da.");
	}
	else {
		printf("Zenbakia BAKOITIA da.");
	}

	return 0;
}
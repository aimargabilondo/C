#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int  n, m;
	char str[128];

	printf("Zenbakia sakatu : ");
	scanf("%d", &n);
	printf("2. Zenbakia sakatu : ");
	scanf("%d", &m);

	if (n % m == 0) {
		printf("%d Zenbakia %d ren zatitzailea da.", n, m);
	}
	else {
		printf("Ez da zatitzailea");
	}



	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n=0, m=0, p=0;
	char str[128];

	printf("Lehenengo zenbakia eman:\n ");
	scanf("%d", &n);
	printf("Bigarren zenbakia eman:\n ");
	scanf("%d", &m);
	printf("Hirugarren zenbakia eman:\n ");
	scanf("%d", &p);

	if ((n * n) + (m * m) == (p * p)) {
		printf("Hirukide piragorikoa da.");
	}
	else {
		printf("Ez da hirukide pitagorikoa.");
	}
	

	return 0;
}
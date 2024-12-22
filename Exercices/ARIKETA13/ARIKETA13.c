#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i, j, Biderketa,Batuketa = 0;
	char str[128];

	printf("Zenbaki bat sartu: \n ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		Biderketa = 1;
		for(j = i; j > 0; j--){
			
			Biderketa *= i;
		}
		Batuketa =  Batuketa + Biderketa;
	}

	printf("Hau da lortutako Biderketa %d", Batuketa);



	return 0;
}
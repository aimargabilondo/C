#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Digitu, kapikua = 0, zenb, Hondarra = 0, Digitua = 0;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	printf("Digitua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &Digitu);

	zenb = n;
	while (zenb > 0 && Hondarra!=Digitu) {

		Hondarra = zenb % 10;
		zenb = zenb / 10;
		Digitua++;	
	}
	if (Hondarra == Digitu) {
		printf("Zenbakia %d digituan dago.", Digitua);
	}
	else {
		printf("Digitua ez dago zenbakian");
	}


	return 0;
}
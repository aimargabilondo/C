#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, Digitu, Alderantzizko = 0, Zenbaki, Hondarra = 0, Digitua = 0;
	char str[128];

	printf("Emaidazu zenbaki bat: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &n);

	printf("Digitua: ");
	fgets(str, 128, stdin);
	sscanf(str, "%d", &Digitu);

	while (n > 0) {
		Alderantzizko = Alderantzizko * 10 + n % 10;
		n = n / 10;
	}

	Zenbaki = Alderantzizko;

	while (Zenbaki > 0 && Hondarra != Digitu) {

		Hondarra = Zenbaki % 10;
		Zenbaki = Zenbaki / 10;
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
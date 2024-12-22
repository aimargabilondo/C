#include "orokorrak.h"
#include "diska.h"
#include "menua.h"

int main() {
	DISKA* ptr_hasiera = NULL;
	DISKA* ptr_berria = NULL;
	char str[64];
	int aukera = 0;

	do {
		aukera = menua();
		garbitu();
		ptr_hasiera = exekutatu_menua(aukera, ptr_hasiera, ptr_berria);
		garbitu();
	} while (aukera != IRTEN);

	return 0;
}
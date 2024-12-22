#ifndef DISKA_H
#define DISKA_H
typedef struct s_zenbakia {
	int id;
	char izenburua[MAX_STR];
	char autorea[MAX_STR];
	int estiloa;
	float prezioa;
}DISKA;

typedef struct Nodo_diska {
	DISKA diska;
	struct Nodo_diska* ptrHurrengoa;
}NODOA;

int menua();
NODOA* exekutatu_menua(int aukera, NODOA* ptrHasiera);

NODOA* sortu_diskak(NODOA* ptrHasiera);
NODOA* diskaSortu();
NODOA* sartuBuruan(NODOA* ptrHasiera, NODOA* ptrBerria);
NODOA* sartuBukaeran(NODOA* ptrHasiera, NODOA* ptrBerria);

void bistaratu_zerrenda(NODOA* ptrHasiera);
void diskaBatBistaratu(DISKA diska);

NODOA* aurkitu_bat(NODOA* ptrHasiera, int id, int estiloa, char izena[], int i);
void bistaratu_bat(NODOA* ptrHasiera, int id);
void bistaratu_estilo_bateko_diskak(NODOA* ptrHasiera, int estilo, int id);
void aurkitu_izenburua(NODOA* ptrHasiera, char izena[], int estilo, int id);
void modifikatuPrezioa(NODOA * ptr_hasiera, char izenburua[], float prezio_berria);

#endif

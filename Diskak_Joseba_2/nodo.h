
#ifndef NODO_H_
#define NODO_H_

#define MAX_STR 64
typedef enum{ROCK, JAZZ, BLUES, ELECTRONICA, PUNK, POP}ESTILOA;

typedef struct Nodo_Diska{
	int id;
	char izenburua[MAX_STR];
	char taldea[MAX_STR];
	ESTILOA estiloa;
	int edizio_urtea;
	struct Diska* ptr_hurrengoa;
}NODO_DISKA;


typedef struct Diska{
	int id;
	char izenburua[MAX_STR];
	char taldea[MAX_STR];
	ESTILOA estiloa;
	int edizio_urtea;
	int prezioa;
}DISKA;

typedef struct Nodoa{
	DISKA  elementua;
	struct Nodoa* ptr_hurrengoa;
}NODOA;

//DISKA* sartu_buruan(DISKA* ptr_hasiera, DISKA* ptr_berria);
//void bistaratu_zerrenda(DISKA* ptr_hasiera);

NODOA* sortu_nodo_bat();
NODOA* sortu_nodo_bat_v1();


void sortu_nodo_bat_josu(NODOA* ptr_berria);
NODOA* sartu_buruan(NODOA* ptr_hasiera, NODOA* ptr_berria);
NODOA* sartu_bukaeran(NODOA* ptr_hasiera, NODOA* ptr_berria);
void bistaratu_zerrenda(NODOA* ptr_hasiera);

void bistaratu_zerrenda_alderantziz(NODOA* ptr_hasiera);

void bistaratu_diska(DISKA diska);
void bistaratu_estilo_batekoak(NODOA* ptr_hasiera, ESTILOA estiloa);

NODOA* aurkitu_elementua(NODOA* ptr_hasiera, char str[MAX_STR]);
void modifikatu_prezioa(NODOA* ptr_aux);

//void hustu_zerrenda(NODOA* ptr_hasiera);
NODOA* hustu_zerrenda(NODOA* ptr_hasiera);
//NODOA* hustu_zerrenda(NODOA* ptr_hasiera); .... return NULL;

int jarraitu();

NODOA* lotu_bi_zerrenda(NODOA* ptr_hasiera1, NODOA* ptr_hasiera2);
NODOA* kendu_elementua(NODOA* ptr_hasiera, int id); //free barruan
//NODOA* atara_elementua(NODOA** ptr_hasiera, char izenburua[]);
NODOA* sartu_urtez_ordenaturik(NODOA* ptr_hasiera,NODOA* ptr_berria);//*


#endif /* NODO_H_ */

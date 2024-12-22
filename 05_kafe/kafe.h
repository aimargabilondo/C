#ifndef KAFE_H
#define KAFE_H

#define MAX_STR 128

#define SORTU 1
#define N_EGUNAK 2
#define DIFERENTZIA 3
#define EBOLUZIOA 4
#define ENPRESA_SORTU 5
#define PRODUKZIOA_SORTU 6
#define ENPRESAK_BISTARATU 7
#define IRTEN 5

typedef struct Kafe {
	int data;
	float kafe_ekoizpena;
	float kafeina;
}KAFE;
typedef struct Nodo_kafe {
	struct Kafe kafe;
	struct Nodo_kafe* ptrHurrengoa;
}NODO_KAFE;
typedef struct Enpresa {
	char Izena[MAX_STR];
	struct Nodo_Kafe* produkzioa;
}ENPRESA;
typedef struct Nodo_enpresa {
	struct Enpresa enpresa;
	struct Nodo_enpresa* ptrHurrengoa;
}NODO_ENPRESA;

int menua();
NODO_KAFE* menua_exekutatu(int aukera, NODO_KAFE* ptrHasiera, NODO_KAFE* ptrBerria);
void N_egunetako_produkzioa(NODO_KAFE* ptrHasiera);
void produkzio_diferentzia(NODO_KAFE* ptrHasiera);
NODO_KAFE* sortu_datuak();
void bistaratu_egun_bat(NODO_KAFE* ptrEguna);
NODO_KAFE* sartuNodoaBuruan(NODO_KAFE* ptrHasiera, NODO_KAFE* ptrBerria);
void bistaratu_eboluzioa(NODO_KAFE* ptrHasiera);
#endif
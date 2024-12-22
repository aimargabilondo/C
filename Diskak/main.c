#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128
#define NULL 0

typedef enum { ROCK, BLUES, POP, PUNK, ELECTRONICA, JAZZ }ESTILOA;

typedef struct Diska {
    int id;
    int edizio_urtea;
    char izena[MAX_STR];
    ESTILOA estiloa;
    char izenburua[MAX_STR];

    struct Diska* ptr_hurrengoa;
}DISKA;

int main() {
    DISKA diska_bat;
    diska_bat.id = 1;
    diska_bat.estiloa = ROCK;

    int i = 2;
    DISKA diska_arraia[10];
    diska_arraia[i].id = 1;
    diska_arraia[i].estiloa = ROCK;
    strcpy(diska_arraia[i].izena, "Bob Dylan");

    DISKA* ptr_lehen_elementua = NULL;
    DISKA* ptr_tmp = NULL;
    ptr_lehen_elementua = &diska_bat;
    printf("%s\n", ptr_lehen_elementua->izena); // jimi hendix
    ptr_lehen_elementua = diska_arraia + i;
    printf("%s\n", ptr_lehen_elementua->izena); // bob dilan

    // =========== ZERRENDA KATEATUA ================

    ptr_lehen_elementua = malloc(sizeof(DISKA));
    strcpy(ptr_lehen_elementua->izena, "Rosalia");
    ptr_lehen_elementua->estiloa = ELECTRONICA;
    printf("%s\n", ptr_lehen_elementua->izena); // rosalia

    ptr_tmp = malloc(sizeof(DISKA));

    strcpy(ptr_tmp->izena, "John Contrane");
    ptr_tmp->estiloa = JAZZ;
    printf("%s\n", ptr_tmp->izena); // john contrane

    //KATEATU

    ptr_lehen_elementua->ptr_hurrengoa = ptr_tmp;

    printf("%s\n", ptr_lehen_elementua->izena); // lehen elementua

    printf("%s\n", ptr_lehen_elementua->ptr_hurrengoa->izena); // bigarrena elementua
    
    ptr_tmp = ptr_lehen_elementua->ptr_hurrengoa;

    printf("%s\n", ptr_tmp->izena); // bigarrena elementua


    return 0;
}
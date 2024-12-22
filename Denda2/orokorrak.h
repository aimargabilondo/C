#pragma once
#ifndef OROKORRAK_H
#define OROKORRAK_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128
#define TRUE 1
#define FALSE 0

#define ADMINA 1
#define EROSLEAK 2
#define OKERRA 0

#define POPROCK 0
#define ARTROCK 1
#define POP 2
#define ROCKPROG 3
#define FOLCROCK 4
#define ROCKALT 5
#define JAZZ 6

#define MAX_DISKA 20
#define MAX_EROSKETA 20
#define IRTEN 0

typedef struct Orokorra {
    char izenburua[MAX_STR];
    char autorea[MAX_STR];
    int data;
    int estiloa;
    char zigilua[MAX_STR];
    float dirua;
    float kalifikazioa;
}OROKORRA;

typedef enum a_aukera { IRTEN_AUKERA, SORTU, EZABATU, ALDATU, BISTARATU, ESTILO, AUTORE, ZIGILUA, DATA, AURKITU }AUKERA;
typedef enum a_erosketa { IRTEN_AUKERA_EROS, GEHITU_EROSKETA, BURUTU, EROSKETA_IKUSI }AUKERA_EROS;



void izenaGaldetu(char izena[]);
void  jarraitu();
void borratu_pantila();


#endif 
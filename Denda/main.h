#ifndef MAIN_H_
#define MAIN_H_

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

//Defines
#define MAX_STR 64

#define ADMINISTRADOR 0
#define DENDARI 1
#define EROSLE 2

//Struct
typedef struct {
    char izena[MAX_STR];
    char pasahitza[MAX_STR];
    int erabiltzaile_mota;
    char email[MAX_STR];
    int id;
}USER;

//ENUM
typedef enum e_mota { USER_MOTA = 2, ADMIN_MOTA = 0, GUEST_MOTA = 1}MOTA;
typedef enum { ASTELEHENA, ASTEARTEA, ASTEAZKENA, OSTEGUNA, OSTIRALA, LARUNBATA, IGANDEA }EGUNAK;

// Int
int login();

// Void
void agur_mezua();

#endif // !MAIN_H_

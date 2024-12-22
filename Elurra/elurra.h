#pragma once
#ifndef ELURRA_H
#define ELURRA_H

// Herria datu egitura
 typedef struct Herria {
    int id;
    char izena[50];
    float elurra; // Zentimetroetan
} HERRIA;


 void batazBeste(int herriKopurua, HERRIA* herriak);
 void idatziHerriakElurKopuruagatik(HERRIA* herriak, int batazBestekea, int herriKopurua);
#endif
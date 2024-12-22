#ifndef MENUA_H
#define MENUA_H

typedef enum e_aukera {
    IRTEN_AUKERA, SORTU, ALDATU, BISTARATU, FITX_IRA, KONTATU, ORDENATU
}AUKERA;

int menua();
int menua_exekutatu(int aukera, HERRIALDEAK herri[], int zenbat_herri, int MAX);

#endif

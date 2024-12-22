#include <stdio.h>

typedef struct {

    int id;

    char izena[10];

    double marks;

} PERTSONA;



int PERTSONA_kenduArraitik(PERTSONA p, PERTSONA* pertsonak, int kop);



int main() {

    PERTSONA p1 = { 2, "Iker", 8.7 };



    PERTSONA pertsonak[] = {

        { 1, "Jon" , 6.7},

        { 2, "Iker", 7.7 },

        { 3, "Oier", 8.7 },

        { 4, "Iratxe", 6.9 },

    };



    int kop = 4;



    kop = PERTSONA_kenduArraitik(p1, pertsonak, kop);


    printf("Pertsona kendu ondoren, pertsonen kopurua: %d\n", kop);



    return 0;

}



int PERTSONA_kenduArraitik(PERTSONA p, PERTSONA* pertsonak, int kop) {

    int i;

    int found_index = -1;

    // Pertsona aurkitzeko

    for (i = 0; i < kop; i++) {

        if (pertsonak->id == p.id) {

            found_index = i;

            break;

        }

        pertsonak++;

    }



    if (found_index != -1) {

        for (i = found_index; i < kop - 1; i++) {

            *pertsonak = *(pertsonak + 1);

            pertsonak++;

        }

        return kop - 1;

    }



    return kop;

}




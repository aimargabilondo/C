#include "orokorrak.h"
#include "users.h"


int main(void) {
    USER user1;
    char str[MAX_STR];
    int aukera = 1;
    int jarraitu = 1;
    int saiakerak = 3;
    int logeatua = 0;

	do {
		user1 = erabiltzaile_datuak_eskatu_ona();
		logeatua = konprobatu_user(user1);
        if (logeatua == ADMINA || logeatua == EROSLEAK) {
            aukera = usuarioa_aukeratuta(logeatua);
            printf("Jarraitu nahi duzu? 1 - BAI, 0 - EZ\n");
            fgets(str, MAX_STR, stdin);
            sscanf(str, "%d", &jarraitu);
        }
        else {
            printf("Usuario edo pasahitz desegokia, %d saiakera dauzkazu\n", --saiakerak);
        }
    } while ((logeatua == FALSE && saiakerak > 0) || jarraitu == TRUE);

    return EXIT_SUCCESS;
}
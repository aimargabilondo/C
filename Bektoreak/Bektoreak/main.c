#define STR_SECURE_NO_WARNINIG
#include <stdio.h>

int main(int argc, char* argv[]) {
    int i = 0, n = 0, zenbat = 0;
    int bektore[50];
    char str[128];

    fgets(str, 128, stdin);
    sscanf(str, "%d", &n);

    if (n != 0) {
        bektore[zenbat] = n;
        zenbat++;  
    }
}
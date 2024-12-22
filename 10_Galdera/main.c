#include <stdio.h>

int nire_strcat(char* destination, char* source) {

    int i = 0;

    while (*(destination + i) != '\0') {

        i++;

    }

    int j = 0;

    while (*(source + j) != '\0') {

        *(destination + i + j) = *(source + j);

        j++;

    }

    *(destination + i + j) = '\0';

    return i + j;

}

int main() {

    char str1[20] = "Hello ";

    char str2[] = "world!";

    int tamaina = nire_strcat(str1, str2);

    printf("Konektatutako esaldia: %s\n", str1);

    printf("Konektatutako esaldiaren tamaina: %d\n", tamaina);

    return 0;

}

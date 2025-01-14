#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(const char *str) {
    const char *keywords[] = {"if", "else", "while", "return", "int", "float"};
    for (int i = 0; i < 6; ++i) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void analyzeCode(const char *code) {
    char token[100];
    int i = 0, j = 0;

    while (code[i] != '\0') {
        if (isalpha(code[i])) {
            while (isalnum(code[i])) {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            j = 0;
            if (isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
        } else if (isdigit(code[i])) {
            while (isdigit(code[i]))
                token[j++] = code[i++];
            token[j] = '\0';
            j = 0;
            printf("Number: %s\n", token);
        } else if (strchr("+-*/=<>", code[i])) {
            printf("Operator: %c\n", code[i++]);
        } else {
            ++i; // Ignorar otros caracteres
        }
    }
}

int main() {
    const char *code = "int x = 10; if (x > 5) return x;";
    printf("Analyzing code: %s\n", code);
    analyzeCode(code);
    return 0;
}

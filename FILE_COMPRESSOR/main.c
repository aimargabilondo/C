#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

MinHeapNode* createNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

MinHeap* buildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void generateCodes(MinHeapNode* root, char* code, int top, char codes[256][256]) {
    if (root->left) {
        code[top] = '0';
        generateCodes(root->left, code, top + 1, codes);
    }
    if (root->right) {
        code[top] = '1';
        generateCodes(root->right, code, top + 1, codes);
    }
    if (!(root->left) && !(root->right)) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->data], code);
    }
}

void compressFile(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "wb");
    if (!input || !output) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    int freq[256] = {0};
    char c;
    while ((c = fgetc(input)) != EOF)
        freq[(unsigned char)c]++;

    char data[256];
    int nonZeroCount = 0;
    int freqData[256];
    for (int i = 0; i < 256; ++i) {
        if (freq[i]) {
            data[nonZeroCount] = (char)i;
            freqData[nonZeroCount++] = freq[i];
        }
    }

    MinHeapNode* root = buildHuffmanTree(data, freqData, nonZeroCount);

    char codes[256][256] = {0};
    char code[256];
    generateCodes(root, code, 0, codes);

    rewind(input);

    fwrite(&nonZeroCount, sizeof(int), 1, output);
    for (int i = 0; i < nonZeroCount; ++i) {
        fwrite(&data[i], sizeof(char), 1, output);
        fwrite(&freqData[i], sizeof(int), 1, output);
    }

    while ((c = fgetc(input)) != EOF) {
        fputs(codes[(unsigned char)c], output);
    }

    fclose(input);
    fclose(output);
    printf("Archivo comprimido exitosamente.\n");
}

void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "w");
    if (!input || !output) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    int nonZeroCount;
    fread(&nonZeroCount, sizeof(int), 1, input);

    char data[256];
    int freqData[256];
    for (int i = 0; i < nonZeroCount; ++i) {
        fread(&data[i], sizeof(char), 1, input);
        fread(&freqData[i], sizeof(int), 1, input);
    }

    MinHeapNode* root = buildHuffmanTree(data, freqData, nonZeroCount);

    MinHeapNode* current = root;
    char bit;
    while (fread(&bit, sizeof(char), 1, input)) {
        current = (bit == '0') ? current->left : current->right;

        if (!(current->left) && !(current->right)) {
            fputc(current->data, output);
            current = root;
        }
    }

    fclose(input);
    fclose(output);
    printf("Archivo descomprimido exitosamente.\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

MinHeapNode* createNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

MinHeap* buildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = buildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void generateCodes(MinHeapNode* root, char* code, int top, char codes[256][256]) {
    if (root->left) {
        code[top] = '0';
        generateCodes(root->left, code, top + 1, codes);
    }
    if (root->right) {
        code[top] = '1';
        generateCodes(root->right, code, top + 1, codes);
    }
    if (!(root->left) && !(root->right)) {
        code[top] = '\0';
        strcpy(codes[(unsigned char)root->data], code);
    }
}

void compressFile(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "wb");
    if (!input || !output) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    int freq[256] = {0};
    char c;
    while ((c = fgetc(input)) != EOF)
        freq[(unsigned char)c]++;

    char data[256];
    int nonZeroCount = 0;
    int freqData[256];
    for (int i = 0; i < 256; ++i) {
        if (freq[i]) {
            data[nonZeroCount] = (char)i;
            freqData[nonZeroCount++] = freq[i];
        }
    }

    MinHeapNode* root = buildHuffmanTree(data, freqData, nonZeroCount);

    char codes[256][256] = {0};
    char code[256];
    generateCodes(root, code, 0, codes);

    rewind(input);

    fwrite(&nonZeroCount, sizeof(int), 1, output);
    for (int i = 0; i < nonZeroCount; ++i) {
        fwrite(&data[i], sizeof(char), 1, output);
        fwrite(&freqData[i], sizeof(int), 1, output);
    }

    while ((c = fgetc(input)) != EOF) {
        fputs(codes[(unsigned char)c], output);
    }

    fclose(input);
    fclose(output);
    printf("Archivo comprimido exitosamente.\n");
}

void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "w");
    if (!input || !output) {
        printf("Error al abrir los archivos.\n");
        return;
    }

    int nonZeroCount;
    fread(&nonZeroCount, sizeof(int), 1, input);

    char data[256];
    int freqData[256];
    for (int i = 0; i < nonZeroCount; ++i) {
        fread(&data[i], sizeof(char), 1, input);
        fread(&freqData[i], sizeof(int), 1, input);
    }

    MinHeapNode* root = buildHuffmanTree(data, freqData, nonZeroCount);

    MinHeapNode* current = root;
    char bit;
    while (fread(&bit, sizeof(char), 1, input)) {
        current = (bit == '0') ? current->left : current->right;

        if (!(current->left) && !(current->right)) {
            fputc(current->data, output);
            current = root;
        }
    }

    fclose(input);
    fclose(output);
    printf("Archivo descomprimido exitosamente.\n");
}

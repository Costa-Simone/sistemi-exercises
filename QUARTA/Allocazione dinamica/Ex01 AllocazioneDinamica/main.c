#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int *vI; // vettore di interi
    char *vC; // vettore di char
    int *i, *len; // indice e lunghezza

    // ALLOCAZIONE DINAMINA: MALLOC
    i = (int*) malloc(sizeof(int));
    len = (int*) malloc(sizeof(int));
    *len = 10;

    printf("\nAddr puntatore: %p\nAddr in puntatore: %p\nContenuto cella puntata: %d\n", &len, len, *len);

    // ALLOCAZIONE DINAMICA ARRAY: MALLOC
    vC = (char*) malloc(sizeof(char) * (*len));

    srand(time(NULL));

    printf("\nMALLOC\n");

    // caricamento
    for(*i = 0; *i < *len; (*i)++) {
        *(vC + (*i)) = 'a' + rand() % ('a' - 'z');
    }

    // stampa vC
    for(*i = 0; *i < *len; (*i)++) {
        printf("%c ", *(vC + (*i)));
    }

    printf("\n");

    // ALLOCAZIONE DINAMICA ARRAY: CALLOC
    vI = (int*) calloc(*len, sizeof(int));

    printf("\nCALLOC\n");

    for(*i = 0; *i < *len; (*i)++) {
        *(vI + (*i)) = 1 + rand() % 10;
    }

    for(*i = 0; *i < *len; (*i)++) {
        printf("%d ", *(vI + (*i)));
    }

    printf("\n");
    // ALLOCAZIONE DINAMICA ARRAY: REALLOC
    printf("\nREALLOC\n");

    *len = 15;
    vI = realloc(vI, *len * sizeof(int));

    for(*i = 0; *i < *len; (*i)++) {
        printf("%d ", *(vI + (*i)));
    }

    printf("\n");

    // FREE --> RILASCIO RISORSE ALLOCATE IN MEMORIA
    free(vC);
    free(vI);
    free(i);
    free(len);
    printf("\nAddr puntatore: %p\nAddr in puntatore: %p\nContenuto cella puntata: %d\n", &len, len, *len);

    return 0;
}

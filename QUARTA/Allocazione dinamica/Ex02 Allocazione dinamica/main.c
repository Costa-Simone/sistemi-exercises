#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int bool;

void menu(char *sc);
void caricaVettRnd(int *v, int *len);
void stampaVett(int *v, int *len);
int copiaPari(int *v1, int *v2, int *len);

int main() {
    char *scelta;
    int *len, *len2;
    int *vI;
    int *vI2;

    len = (int*) calloc(1, sizeof(int));
    len2 = (int*) calloc(1, sizeof(int));

    srand(time(NULL));

    scelta = (char*) malloc(sizeof(char));

    do {
        menu(scelta);

        switch (*scelta) {
            case 'a':
            case 'A':
                printf("\nInserisci la lunghezza del vettore: ");
                scanf("%d", len);

                vI = (int*) calloc(*len, sizeof(int));
                vI2 = (int*) calloc(*len, sizeof(int));

                caricaVettRnd(*vI, *len);
                stampaVett(*vI, *len);
                *len2 = copiaPari(*vI, *vI2, *len);
                break;

            case 'b':
            case 'B':
                break;

            case 'c':
            case 'C':
                break;
        }
    } while (*scelta != 'q' && *scelta != 'Q');

    return 0;
}

int copiaPari(int *v1, int *v2, int *len) {
    
}
void stampaVett(int *v, int *len) {
    int *i;

    i = (int*) calloc(1, sizeof(int));

    for(*i = 0; *i < *len; (*i)++) {
        printf("%d ", *(v + (*i)));
    }

    printf("\n");
}
void caricaVettRnd(int *v, int *len) {
    int *i;

    i = (int*) calloc(1, sizeof(int));

    for(*i = 0; *i < *len; (*i)++) {
        *(v + (*i)) = 1 + rand() % 10;
    }
}
void menu(char *sc) {
    system("@cls||clear");
    printf("\nMENU");
    printf("\na. Dato un vettore vI interi casuali caricare in v2 solo i valori pari");
    printf("\nb. ");
    printf("\nc. ");
    printf("\nq. Esci");
    printf("\nScelta --> ");
    scanf("%c", sc);
    fflush(stdin);
}

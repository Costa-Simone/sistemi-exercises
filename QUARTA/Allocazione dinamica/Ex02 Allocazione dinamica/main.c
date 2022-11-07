#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int bool;
#define MAX 51

void menu(char *sc);
void caricaVettRnd(int *v, int *len);
void stampaVett(int *v, int *len);
int copiaPari(int *v1, int *v2, int *len);
void InvertiStringa(char *vC);
void ConcatenaStringa(char *s, char *s2);
void spostaCaratteriUnivoci(char *vC, char *vC2);
void splittaStringa(char *s, char *s2, int *n, char *sep);

int main() {
    char *scelta;
    int *len, *len2, *lenS;
    int *vI, *vI2;
    int *campo;
    char *vC, *vC2;
    char *separatore;

    len = (int*) calloc(1, sizeof(int));
    len2 = (int*) calloc(1, sizeof(int));
    lenS = (int*) calloc(1, sizeof(int));
    campo = (int*) calloc(1, sizeof(int));
    separatore = (char*) malloc(sizeof(char));
    *lenS = 51;
    *separatore = ';';

    srand(time(NULL));

    scelta = (char*) malloc(sizeof(char));

    do {
        menu(scelta);
        fflush(stdin);

        switch (*scelta) {
            case 'a':
            case 'A': // Dato un vettore vI interi casuali caricare in v2 solo i valori pari
                printf("\nInserisci la lunghezza del vettore: ");
                scanf("%d", len);

                vI = (int*) calloc(*len, sizeof(int));
                vI2 = (int*) calloc(*len, sizeof(int));

                caricaVettRnd(vI, len);
                stampaVett(vI, len);
                *len2 = copiaPari(vI, vI2, len);

                stampaVett(vI2, len2);
                fflush(stdin);
                getchar();
                free(vI);
                free(vI2);
                break;

            case 'b':
            case 'B': // Inverti contenuto stringa
                fflush(stdin);
                getchar();

                vC = (char*) malloc(MAX * sizeof(char));

                printf("Inserisci la stringa: ");
                gets(vC);

                InvertiStringa(vC);

                printf("\nLa stringa invertita --> %s", vC);
                free(vC);
                getchar();
                break;

            case 'c':
            case 'C': // Concatena stringa s1 ed s2
                vC = (char*) malloc(MAX * sizeof(char));
                vC2 = (char*) malloc(MAX * sizeof(char));

                printf("Inserisci la prima stringa: ");
                gets(vC);
                fflush(stdin);
                printf("Inserisci la seconda stringa: ");
                gets(vC2);
                ConcatenaStringa(vC, vC2);
                printf("Stringa concatenata --> %s", vC);
                free(vC);
                free(vC2);
                getchar();
                break;

            case 'd':
            case 'D': // Sposta in stringa s2 solo caratteri che non si ripetono in s1
                vC = (char*) malloc(MAX * sizeof(char));
                vC2 = (char*) malloc(MAX * sizeof(char));

                printf("Inserisci la stringa: ");
                gets(vC);
                fflush(stdin);
                spostaCaratteriUnivoci(vC, vC2);
                printf("\nLa stringa dei caratteri univoci: %s", vC2);
                free(vC);
                free(vC2);
                getchar();
                break;

            case 'e':
            case 'E': // Splitta stringa
                vC = (char*) malloc(MAX * sizeof(char));
                vC2 = (char*) malloc(MAX * sizeof(char));

                printf("Inserisci la stringa da splittare(con separatore avente ';'): ");
                gets(vC);
                fflush(stdin);
                printf("Inserisci il numero del campo desiderato: ");
                scanf("%d", campo);
                (*campo)--;
                splittaStringa(vC, vC2, campo, separatore);
                printf("\nIl campo desiderato e': %s", vC2);
                fflush(stdin);
                free(vC);
                free(vC2);
                getchar();
                break;
        }
    } while (*scelta != 'q' && *scelta != 'Q');

    return 0;
}

void splittaStringa(char *s, char *s2, int *n, char *sep) {
    int *cnt, *i;

    cnt = (int*) malloc(sizeof(int));
    i = (int*) malloc(sizeof(int));
    *cnt = 0;
    *i = 0;

    while (*cnt != *n) {
        while(*(s + *i) != *sep) {
            (*i)++;
        }

        (*cnt)++;
        (*i)++;
    }

    *cnt = 0;

    while (*(s + *i) != *sep && *(s + *i) != '\0') {
        *(s2 + *cnt) = *(s + *i);
        (*i)++;
        (*cnt)++;
    }

    *(s2 + *cnt) = '\0';
}
void spostaCaratteriUnivoci(char *vC, char *vC2) {
    char *p, *p2, *scor;
    int *len, *trovato;

    len = (int*) malloc(sizeof(int));
    trovato = (int*) malloc(sizeof(int));

    *len = 0;
    p = vC;
    p2 = vC2;

    for(; p < (vC + strlen(vC)); p++) {
        *trovato = 0;

        for(scor = vC; scor < (vC + strlen(vC)); scor++) {
            if(p != scor) {
                if(*p == *scor) {
                    *trovato = 1;
                }
            }
        }


        if(*trovato == 0) {
            *(p2 + *len) = *p;
            (*len)++;
        }
    }

    *(p2 + *len) = '\0';
}
void ConcatenaStringa(char *s, char *s2) {
    char *p, *p2;

    s = realloc(s, strlen(s) + strlen(s2) + 1);
    p2 = s2;
    p = s + strlen(s);
    *p = ' ';
    p++;

    for(; p2 < (s2 + strlen(s2)); p2++) {
        *p = *p2;
        p++;
    }

    *p = '\0';
}
void InvertiStringa(char *vC) {
    char *aus, *pF;

    vC = realloc(vC, sizeof(char) * strlen(vC) + 1);
    aus = (char*) malloc(sizeof(char));

    pF = vC + strlen(vC) - 1;

    while (vC < pF) {
        *aus = *vC;
        *vC = *pF;
        *pF = *aus;

        vC++;
        pF--;
    }
}
int copiaPari(int *v1, int *v2, int *len) {
    int *i, *j;

    i = (int*) malloc(sizeof(int));
    j = (int*) malloc(sizeof(int));

    *j = 0;

    for(*i = 0; *i < *len; (*i)++) {
        if(*(v1 + (*i)) % 2 == 0) {
            *(v2 + (*j)) = *(v1 + *i);
            (*j)++;
        }
    }

    return *j;
}
void stampaVett(int *v, int *len) {
    int *i;

    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *len; (*i)++) {
        printf("%d ", *(v + (*i)));
    }

    printf("\n");
}
void caricaVettRnd(int *v, int *len) {
    int *i;

    i = (int*) malloc(sizeof(int));

    for(*i = 0; *i < *len; (*i)++) {
        *(v + (*i)) = 1 + rand() % 10;
    }
}
void menu(char *sc) {
    system("@cls||clear");
    printf("\nMENU");
    printf("\na. Dato un vettore vI interi casuali caricare in v2 solo i valori pari");
    printf("\nb. Inverti contenuto stringa");
    printf("\nc. Concatena stringa s1 ed s2");
    printf("\nd. Sposta in stringa s2 solo caratteri che non si ripetono in s1");
    printf("\ne. Splitta stringa");
    printf("\nq. Esci");
    printf("\nScelta --> ");
    scanf("%c", sc);
    fflush(stdin);
}

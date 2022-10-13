#include <stdio.h>

#define MAX 51

char menu();
int esercizio01(int *v, int dim);
int esercizio02(char *s);
int esercizio03(char *s);
void esercizio04(char *s, char *s2);


int main() {
    char scelta;
    int v[MAX];
    char s[MAX], s2[MAX];
    int dim;

    do {
        system("@cls||clear");

        scelta = menu();

        if(scelta >= 'A' && scelta <= 'Z') {
            scelta += 32;
        }

        switch (scelta) {
            case 'a':
                do {
                    printf("Inserisci la dimensione del vettore, deve essere > di 2 e < di %d: ", MAX);
                    scanf("%d", &dim);
                } while(dim <= 2 || dim >= MAX);

                if(esercizio01(v, dim) == 1) {
                    printf("Il vettore contiene fibonacci");
                }
                else {
                    printf("Il vettore non contiene fibonacci");
                }

                break;

            case 'b':
                printf("Inserisci la stringa: ");
                gets(s);

                if(esercizio02(s) == 1) {
                    printf("I valori sono decrescenti");
                } else {
                    printf("I valori non sono decrescenti");
                }
                break;

            case 'c':
                printf("Inserisci la stringa: ");
                gets(s);

                if(esercizio03(s) == 1) {
                    printf("La stringa contiene doppie");
                } else {
                    printf("La stringa non contiene doppie");
                }
                break;

            case 'd':
                printf("Inserisci la prima stringa: ");
                gets(s);
                printf("Inserisci la seconda stringa: ");
                gets(s2);

                esercizio04(s, s2);
                break;
        }

        fflush(stdin);
        getchar();
    } while(scelta != 'q');

    printf("Programma terminato!");

    return 0;
}

void esercizio04(char *s, char *s2) {
    char aus[MAX] = {'\0'};
    char *p, *p2, *pos, *ausS;
    int len, trovato;

    len = 0;
    p = s;
    ausS = aus;

    for(; *p != '\0'; p++) {
        p2 = s2;

        while (*p2 != '\0' && *p2 != *p) {
            p2++;
        }

        if(*p == *p2) {
            trovato = 0;
            pos = aus;

            do {
                if(*pos == *p) {
                    trovato = 1;
                } else {
                    pos++;
                }
            } while (pos < ausS && trovato == 0);

            if(trovato == 0) {
                *ausS = *p;
                len++;
                ausS++;
            }
        }
    }

    printf("I caratteri che si ripetono sono %d [", (len));

    pos = aus;

    for(; pos != ausS; pos++) {
        printf("'%c' ", *pos);
    }

    printf("]");
}
int esercizio03(char *s) {
    int trovato;
    char *p;

    p = s + 1;
    trovato = 0;

    while(*p != '\0' && *(p - 1) != *p) {
        p++;
    }

    if(*p == *(p - 1)) {
        trovato = 1;
    }

    return trovato;
}
int esercizio02(char *s) {
    int ret;
    char *p;

    p = s + 1;

    while(*p != '\0' && *(p - 1) > *p) {
        p++;
    }

    if(*p == '\0') {
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}
int esercizio01(int *v, int dim) {
    int i, trovato;
    int *p;

    trovato = 1;
    p = v;

    for(i = 0; i < dim; i++) {
        printf("Inserisci valore: ");
        scanf("%d", (v + i));
    }

    i = 2;

    while(trovato == 1 && i < dim) {
        if((*(p + i - 2) + *(p + i - 1)) == *(p + i)) {
            i++;
        } else {
            trovato = 0;
        }
    }

    return trovato;
}
char menu() {
    char sc;
    printf("-MENU-");
    printf("a. Dato un array di interi in input [2<DIM<MAX]\n"
           "(valori caricati casualmente [0–50]) verificare se il contenuto\n"
           "rappresenta la serie di Fibonacci (0 1 1 2 3 5 8...)");
    printf("\nb. Data una stringa in input dire se il suo contenuto è ordinato DECRESCENTE");
    printf("\nc. Data in input una stringa verifica se contiene doppie");
    printf("\nd. Date due stringhe in input verificare quanti caratteri hanno in\n"
           "comune, se un carattere compare due volte in entrambe le\n"
           "stringhe lo si conti una volta sola.\n"
           "Esempio (s1 = “verifica” s2 = “4dinf” output = “i caratteri che\n"
           "si ripetono sono 2” [ ‘i’, ‘f’ ]");
    printf("\nScelta --> ");
    scanf("%c", &sc);

    fflush(stdin);
    return sc;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 51

int menu();
void modificaStringa(char *s);
void invertiStringa(char *s);
void concatenaStringhe(char *s1, char *s2);
void caricaVett(int *v, int len);
void stampaVett(int *v, int len);
void ordinaVett(int *v, int len);
void cifraturaDiCesare(char *s, char c);
void stringaMaiuscola(char *s);

int main()
{
    int scelta, len, v[MAX];
    char s1[MAX], s2[MAX], c;

    do {
        system("@cls||clear");

        scelta = menu();

        switch(scelta) {
            case 1: // Converti maiuscolo e minuscolo(e viceversa)
                getchar();
                printf("\nFrase ->");
                gets(s1);
                modificaStringa(s1);
                printf("Frase modificata: %s", s1);
                break;

            case 2: // Inverti stringa
                getchar();
                printf("\nFrase ->");
                gets(s1);
                invertiStringa(s1);
                printf("Frase modificata: %s", s1);
                break;

            case 3: // Concatena due stringhe
                getchar();
                printf("\nFrase 1 ->");
                gets(s1);
                printf("Frase 2 ->");
                gets(s2);
                concatenaStringhe(s1, s2);
                printf("\nLe stringhe concatenate sono: %s", s1);
                break;

            case 4: // Ordina vettore di interi
                getchar();
                printf("\nInserisci totale valore: ");
                scanf("%d", &len);
                caricaVett(v, len);
                printf("Contenuto vettore:\n");
                stampaVett(v, len);
                ordinaVett(v, len);
                printf("\nContenuto vettore ordinato:\n");
                stampaVett(v, len);
                getchar();
                break;

            case 5:
                getchar();
                printf("\nFrase ->");
                gets(s1);
                stringaMaiuscola(s1);
                printf("Inserisci la chiave con lettera dell'alfabeto:");
                scanf("%c", &c);

                if(c >= 'a' && c <= 'z') {
                    c -= 32;
                }

                cifraturaDiCesare(s1, c);
                printf("\nLa stringa cifrata e': %s", s1);
                break;
        }

        getchar();
    } while(scelta != 0);

    printf("Programma terminato...\n");

    return 0;
}

void stringaMaiuscola(char *s) {
    char *p;

    for(p = s; *p != '\0'; p++) {
        if(*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
    }
}
void cifraturaDiCesare(char *s, char c) {
    int key = 'A' - c;
    char *p;

    for(p = s; *p != '\0'; p++) {
        *p += key;

        if(*p > 'Z') {
            *p -= 'A';
        }
    }
}
void caricaVett(int *v, int len) {
    for(int i = 0; i < len; i++) {
        printf("\nInserisci il %d valore: ", (i + 1));
        scanf("%d", (v + i));
    }
}
void stampaVett(int *v, int len) {
    for(int i = 0; i < len; i++) {
        printf("\nIl %d valore e': %d", (i + 1), *(v + i));
    }
}
void ordinaVett(int *v, int len) {
    int posMin, aus, i, j;

    for(i = 0; i <= len - 2; i++) {
        posMin = i;

        for(j = i + 1; j <= len - 1; j++) {
            if(*(v + posMin) > *(v + j)) {
                posMin = j;
            }
        }

        if(posMin != i) {
            aus = *(v + i);
            *(v + i) = *(v + posMin);
            *(v + posMin) = aus;
        }
    }
}
void concatenaStringhe(char *s1, char *s2) {
    char *p, *p2;

    for(p = s1; *p != '\0'; p++);

    *p = ' ';
    p++;

    for(p2 = s2; *p2 != '\0'; p2++) {
        *p = *p2;
        p++;
    }

    *p = '\0';
}
void invertiStringa(char *s) {
    char *p, *p2, aus;

    p = s;

    for(p2 = s; *p2 != '\0'; p2++);

    p2--;

    while(p < p2) {
        aus = *p;
        *p = *p2;
        *p2 = aus;

        p++;
        p2--;
    }
}
void modificaStringa(char *s) {
    while(*s != '\0') {
        if(*s >= 'a' && *s <= 'z') {
            *s -= 32;
        }
        else if(*s <= 'A' && *s >= 'Z') {
            *s += 32;
        }

        s++;
    }
}
int menu() {
    int sc;

    printf("MENU\n");
    printf("1. Converti maiuscolo e minuscolo(e viceversa)\n");
    printf("2. Inverti stringa\n");
    printf("3. Concatena due stringhe\n");
    printf("4. Ordina vettore di interi\n");
    printf("5. Cifratura di Cesare\n");
    printf("0. Esci\n");

    do {
        printf("\nScelta ->");
        scanf("%d", &sc);
    } while(sc < 0 && sc > 4);

    fflush(stdin);

    return sc;
}

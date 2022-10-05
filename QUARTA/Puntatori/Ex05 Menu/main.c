
#include <stdio.h>
#include <stdlib.h>

#define MAX 51

int menu();
void modificaStringa(char *s);
void invertiStringa(char *s);
int concatenaStringhe(char *s1, char *s2);
void caricaVett(int *v, int len);
void stampaVett(int *v, int len);
void ordinaVett(int *v, int len);
void cifraturaDiCesare(char *s, char c);
void stringaMaiuscola(char *s);
void decifraturaDiCesare(char *s, char c);
void cifraturaSemplice(char *s, int n);
void decifraturaSemplice(char *s, int n);

int main()
{
    int scelta, len, v[MAX], n;
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
                if(concatenaStringhe(s1, s2) == 1) {
                    printf("\nLe stringhe concatenate sono: %s", s1);
                }
                else {
                    printf("\nImpossibile concatenare le stringhe!");
                }
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
                printf("Inserisci il valore:");
                scanf("%d", &n);
                cifraturaSemplice(s1, n);
                printf("\nLa stringa cifrata e': %s", s1);
                decifraturaSemplice(s1, n);
                printf("\nLa stringa decifrata e': %s", s1);
                break;

            case 6:
                getchar();
                printf("\nFrase ->");
                gets(s1);
                stringaMaiuscola(s1);
                printf("Inserisci la chiave con lettera dell'alfabeto:");
                scanf("%c", &c);

                if(c >= 'a' && c <= 'z') {
                    c -= 32;
                }

                printf("\nLa stringa decifrata e': %s", s1);
                cifraturaDiCesare(s1, c);
                printf("\nLa stringa cifrata e': %s", s1);
                decifraturaDiCesare(s1, c);
                printf("\nLa stringa decifrata e': %s", s1);
                getchar();
                break;
        }

        fflush(stdin);
        getchar();
    } while(scelta != 0);

    printf("Programma terminato...\n");

    return 0;
}

void cifraturaSemplice(char *s, int n) {
    for(; *s != '\0'; s++) {
        if(*s >= 'A' && *s <= 'Z') {
            *s += n;

            if(*s > 'Z') {
                *s -= 26;
            }
        }
    }
}
void decifraturaSemplice(char *s, int n) {
    for(; *s != '\0'; s++) {
        if(*s >= 'A' && *s <= 'Z') {
            *s -= n;

            if(*s < 'A') {
                *s += 26;
            }
        }
    }
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
    int key = c - 'A';

    for(; *s != '\0'; s++) {
        if(*s >= 'A' && *s <= 'Z') {
            *s += key;

            if(*s > 'Z') {
                *s -= 26;
            }
        }
    }
}
void decifraturaDiCesare(char *s, char c) {
    int key = c - 'A';

    for(; *s != '\0'; s++) {
        if(*s >= 'A' && *s <= 'Z') {
            *s -= key;

            if(*s < 'A') {
                *s += 26;
            }
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
int concatenaStringhe(char *s1, char *s2) {
    char *p, *p2;
    int controlla = 0, len1, len2;


    for(len1 = 0, p = s1; *p != '\0'; len1++, p++);
    for(len2 = 0, p2 = s2; *p2 != '\0'; len2++, p2++);

    if((len1 + len2) > MAX - 1) {
        controlla = 0;
    }
    else {
        for(p = s1; *p != '\0'; p++);

        *p = ' ';
        p++;

        for(p2 = s2; *p2 != '\0'; p2++) {
            *p = *p2;
            p++;
        }

        *p = '\0';

        controlla = 1;
    }

    return controlla;
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
    printf("5. Cifratura semplice\n");
    printf("6. Cifratura di Cesare\n");
    printf("0. Esci\n");

    do {
        printf("\nScelta ->");
        scanf("%d", &sc);
    } while(sc < 0 && sc > 4);

    fflush(stdin);

    return sc;
}

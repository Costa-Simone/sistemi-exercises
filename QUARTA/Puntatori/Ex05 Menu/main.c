
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
void visualizzaRicorrenze(char *s);
void svuotaVett(int *v);
int verificareAnagramma(char *s, char *s2);

int main()
{
    int scelta, len, v[MAX], n;
    char s1[MAX], s2[MAX], c;

    do {
        system("@cls||clear");

        scelta = menu();

        switch(scelta) {
            case 1: // Converti maiuscolo e minuscolo(e viceversa)
                printf("\nFrase ->");
                gets(s1);
                modificaStringa(s1);
                printf("Frase modificata: %s", s1);
                break;

            case 2: // Inverti stringa
                printf("\nFrase ->");
                gets(s1);
                invertiStringa(s1);
                printf("Frase modificata: %s", s1);
                break;

            case 3: // Concatena due stringhe
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
                printf("\nFrase ->");
                gets(s1);
                stringaMaiuscola(s1);

                do {
                    printf("Inserisci la chiave con lettera dell'alfabeto:");
                    scanf("%c", &c);

                    if(c >= 'a' && c <= 'z') {
                        c -= 32;
                    }
                } while(c < 'A' || c > 'Z');



                printf("\nLa stringa decifrata e': %s", s1);
                cifraturaDiCesare(s1, c);
                printf("\nLa stringa cifrata e': %s", s1);
                decifraturaDiCesare(s1, c);
                printf("\nLa stringa decifrata e': %s", s1);
                getchar();
                break;

            case  7: // Data una stringa visualizzare in output le ricorrenze
                printf("\nFrase ->");
                gets(s1);
                stringaMaiuscola(s1);
                visualizzaRicorrenze(s1);
                break;

            case  8: // Date due stringhe verificare se sono l'anagramma l'una dell'altra
                printf("\nInserisci la prima stringa: ");
                gets(s1);
                printf("\nInserisci la seconda stringa: ");
                gets(s2);
                stringaMaiuscola(s1);
                stringaMaiuscola(s2);

                if(verificareAnagramma(s1, s2) == 1) {
                    printf("\nLe due stringhe sono l'anagramma");
                }
                else {
                    printf("\nLe due stringhe non sono l'anagramma");
                }
                break;

            case  9: // Date due stringhe verificare se sono Hertzianamente compatibili
                break;
        }

        fflush(stdin);
        getchar();
    } while(scelta != 0);

    printf("Programma terminato...\n");

    return 0;
}

int verificareAnagramma(char *s, char *s2) {
    int controllo, len, len2, i, j;
    char *p, *p2;

    controllo = 0;
    len = 0;
    len2 = 0;

    for(p = s;*p != '\0'; p++) {
        if(*p >= 'A' && *p <= 'Z') {
            len++;
        }
    }

    for(p2 = s2;*p2 != '\0'; p2++) {
        if(*p2 >= 'A' && *p2 <= 'Z') {
            len2++;
        }
    }

    if(len == len2) {
        
    }

    return controllo;
}
void visualizzaRicorrenze(char *s) {
    int v[128];
    char *p;
    int *pV, i;

    svuotaVett(v);

    for(p = s, pV = v; *p != '\0'; p++) {
        *(pV + *p) += 1;
    }

    printf("\nLe ricorrenze sono:\n");

    for(i = 0, pV = v; i < 128; i++, pV++) {
        if(*pV > 0) {
            printf("\nLa lettera %c e' apparsa %d volte", i, *pV);
        }
    }
}
void svuotaVett(int *v) {
    int *p;

    for(p = v; p < v + 128; p++) {
        *p = 0;
    }
}
void cifraturaSemplice(char *s, int n) {
    for(; *s != '\0'; s++) {
        if(*s + n > 0 && *s + n < 128) {
            *s += n;
        }
    }
}
void decifraturaSemplice(char *s, int n) {
    for(; *s != '\0'; s++) {
        if(*s + n > 0 && *s + n < 128) {
            *s -= n;
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
    int aus;
    int *p, *p2;

    for(p = v; p <= v + len - 2; p++) {
        int *posMin;

        posMin = p;

        for(p2 = p + 1; p2 <= v + len - 1; p2++) {
            if(*posMin > *p2) {
                posMin = p2;
            }
        }

        if(posMin != p) {
            aus = *p;
            *p = *posMin;
            *posMin = aus;
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
        else if(*s >= 'A' && *s <= 'Z') {
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
    printf("7. Data una stringa visualizzare in output le ricorrenze\n");
    printf("8. Date due stringhe verificare se sono l'anagramma l'una dell'altra\n");
    printf("9. Date due stringhe verificare se sono Hertzianamente compatibili\n");
    printf("0. Esci\n");

    do {
        printf("\nScelta ->");
        scanf("%d", &sc);
    } while(sc < 0 && sc > 4);

    fflush(stdin);

    return sc;
}

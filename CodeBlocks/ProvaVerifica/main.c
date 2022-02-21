#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int ex01(char str[], char car);
void ex02(char str[], int aus);
void ex03(char str[]);
void ex04(char str[], char str2[]);
int ex05(char str[], char str2[]);
void menu(int *sc);
void miaLower(char str[]);

void clrcls() {
    system("@cls||clear"); //direttiva che ci permette di richiamare un prog dal prompt(clear pulisce in windows, cls linux)
}

int main()
{
    int scelta, cont, aus;
    char s[MAX], s2[MAX];
    char car;

    do{
        menu(&scelta);

        switch(scelta) {
            case 1:

                printf("\nInserisci la stringa: ");
                gets(s);

                printf("\nInserisci il carattere: ");
                scanf("%c", &car);

                puts(s);

                cont = ex01(s, car);

                printf("\nLa lettera %c appare %d volte", car, cont);

                break;

             case 2:

                printf("\nInserisci la stringa: ");
                gets(s);

                printf("\nInserisci il numero: ");
                scanf("%d", &aus);

                puts(s);

                ex02(s, aus);

                break;

             case 3:

                printf("\nInserisci la stringa: ");
                gets(s);

                ex03(s);

                break;

             case 4:

                printf("\nInserisci la prima stringa: ");
                gets(s);
                printf("\nInserisci la seconda stringa: ");
                gets(s2);

                ex04(s, s2);

                break;

             case 5:

                printf("\nInserisci la prima stringa: ");
                gets(s);
                printf("\nInserisci la seconda stringa: ");
                gets(s2);

                if(ex05(s, s2) == 0) {
                    printf("\nLa prima stringa e' contenuta");
                }
                else {
                    printf("\nLa prima stringa non e' contenuta");
                }


                break;

            case 0: /*Esci*/
                break;

            default:
                printf("Valore non corretto\n");
                break;
        }

        fflush(stdin); //pulizia del buffer per eliminare invio dato precedentemente
        printf("\n(Premi un tasto per continuare)");
        getchar(); // Attendo pressione pulsante per proseguire
        clrcls();
    }while(scelta != 0);

    printf("Programma terminato!\n");

    return 0;
}
int ex05(char str[], char str2[]) {
    int esci = 0, i = 0;

    while(esci == 0 && str2[i] != '\0') {
        int j = 0;

        while(esci == 0 && str[j] != '\0') {
            if(str2[i] != str[j]) {
                esci = 1;
            }

            j++;
        }

        i++;
    }

    return esci;
}
void ex04(char str[], char str2[]) {
    char s3[MAX];
    int i = 0, k = 0;

    while(str[i] != '\0' && str2[i] != '\0') {
        if(str[i] > str2[i]) {
            s3[k++] = str[i++];
        }
        else {
            s3[k++] = str2[i++];
        }
    }

    printf("\nLa terza stringa e': ");
    puts(s3);
}
void ex03(char str[]) {
    char aus[26], charMax;
    int i = 0, contMax;

    miaLower(str);

    for(i = 0; i < 26; i++) {
        aus[i] = 0;
    }

    i = 0;

    while(str[i] != '\0') {
        aus[str[i] - 97]++;
        i++;
    }

    for(i = 0; i < 26; i++) {
        if(aus[i] > contMax) {
            contMax = aus[i];
            charMax = (i + 97);
        }
    }

    printf("\nIl carattere apparso piu' volte e' %c, con %d volte", charMax, contMax);
}
void ex02(char str[], int aus) {
    int i = 0;

    while(str[i] != '\0') {
        str[i] = str[i] + aus;
        i++;
    }

    printf("\nLa stringa cifrata e': ");
    puts(str);
}
int ex01( char str[], char car) {
    int cont = 0, i = 0;

    while(str[i] != '\0') {
        if(str[i] == car) {
            cont++;
        }

        i++;
    }

    return cont;
}
void miaLower(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}
void menu(int *sc) {
    printf("Menu\n");
    printf("0. Esci\n");

    printf("\nScelta --> ");
    scanf("%d", sc);
    fflush(stdin);
}

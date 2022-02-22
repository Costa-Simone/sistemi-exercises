#include <stdio.h>
#include <stdlib.h>

#define MAX 101

void menu(int *sc);
void miaLower(char str[]);
int ex01(char str[], char car);
void ex02(char str[], int num);
void ex03(char str[]);
void ex04(char str[], char str2[]);

void clrcls() {
    system("@cls||clear");
}

int main()
{
    int scelta, cont, num;
    char s[MAX], s2[MAX], car;

    do {
        menu(&scelta);

        switch(scelta) {
        case 0:
            break;

        case 1:
            printf("\nInserisci la stringa: ");
            gets(s);
            printf("Inserisci il carattere da cercare: ");
            scanf("%c", &car);

            cont = ex01(s, car);

            printf("\nIl carattere %c e' apparso %d volte\n", car, cont);

            break;

        case 2:
            printf("\nInserisci la stringa: ");
            gets(s);

            do {
                printf("Inserisci il numero: ");
                scanf("%d", &num);
            }while(num < 1 || num > 10);

            ex02(s, num);

            break;

        case 3:
            printf("\nInserisci la stringa: ");
            gets(s);

            ex03(s);

            break;

        case 4:
            printf("\nInserisci la prima stringa: ");
            gets(s);
            printf("Inserisci la seconda stringa: ");
            gets(s2);

            ex04(s, s2);

            break;

        default:
            printf("\nCarattere errato!");

            break;
        }

        fflush(stdin);
        printf("\n(Premi un tasto per continuare)");
        getchar();
        clrcls();
    }while(scelta != 0);

    printf("Programma terminato!\n");

    return 0;
}
void ex04(char str[], char str2[]) {
    int i = 0, k = 0;
    char s3[MAX];

    while(str[i] != '\0' && str2[i] != '\0') {
        if(str[i] >= str2[i]) {
            s3[k++] = str[i++];
        }
        else {
            s3[k++] = str2[i++];
        }
    }

    s3[k] = '\0';

    printf("\nLa terza stringa e': ");
    puts(s3);
}
void ex03(char str[]) {
    char charMax, ausChar;
    int i = 0, j, freqMax = 0, aus;

    while(str[i] != '\0') {
        aus = 0;
        j = 0;

        while(str[j] != '\0') {
            if(str[i] == str[j]) {
                aus++;
                ausChar = str[i];
            }

            j++;
        }

        if(aus > freqMax) {
            freqMax = aus;
            charMax = ausChar;
        }

        i++;
    }

    printf("\nIl carattere apparso piu' volte e' %c con %d frequenze\n", charMax, freqMax);
}
void ex02(char str[], int num) {
    int i = 0;

    while(str[i] != '\0') {
        if(i % 2 == 0 && i != 0) {
            str[i] += num;
        }
        else if(i % 2 == 1) {
            str[i] -= num;
        }

        i++;
    }

    printf("\nLa stringa cifrata e': ");
    puts(str);
}
int ex01(char str[], char car) {
    int conta = 0, i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 65 && str[i] <= 90 && car >= 97 && car <= 122) {
            if(str[i] == (car - 32)) {
                conta++;
            }
        }
        else if(str[i] >= 97 && str[i] <= 122 && car >= 65 && car <= 90) {
            if(str[i] == (car + 32)) {
                conta++;
            }
        }
        else if(str[i] == car) {
            conta++;
        }

        i++;
    }

    return conta;
}
void miaLower(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }

        i++;
    }
}
void menu(int *sc) {
    printf("0 --> Esci");
    printf("\n1 --> Conta carattere");
    printf("\n2 --> Cifratura");
    printf("\n3 --> Carattere piu' ripetuto");
    printf("\n4 --> Confronto carattere >\n");

    printf("\nScelta --> ");
    scanf("%d", sc);
    printf("----------------------------------------------------------");
    fflush(stdin);
}

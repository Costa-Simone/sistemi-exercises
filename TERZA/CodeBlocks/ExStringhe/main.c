#include <stdio.h>
#include <stdlib.h>

#define MAX 101

void ex01(char str[]);
void ex02(int vett[]);
void ex03(char str[]);
void stampaStringa(char str[]);
void stampaVett(int vett[], int n);

/*
    1. separare in 3 stringhe diverse i caratteri alfabetici, numerici e gli altri caratteri. visualizzare le 3 strighe
    2. caricare un vettore di dimensione 10 di interi con numeri random da 0 a 10
    3. copiare in una stringa str2 i primi 10 caratteri di str per un numero di volte indicato nel corrispondente elemento nel vettore numeri. visualizzare str
*/

int main()
{
    char s[MAX], s2[MAX];
    int v[10];

    srand(time(NULL));

    printf("EX 01");
    printf("\nInserisci la stringa: ");
    gets(s);

    ex01(s);

    printf("\n\nEX 02");

    ex02(v);

    printf("\n\nEX 03");
    printf("\nInserisci la stringa: ");
    gets(s);

    ex03(s);

    return 0;
}
void ex03(char str[]) {
    int i = 0, k = 0, num[10];
    char str2[MAX];

    while(str[i] != '\0') {
        num[i++] = rand() % 10 + 1;
    }

    i = 0;

    printf("\nStampa del vettore dei numeri:\n");
    while(str[i] != '\0') {
        printf("%d ", num[i++]);
    }
    printf("\n");

    i = 0;

    while(str[i] != '\0' && i < 10) {
        for(int j = 0; j < num[i]; j++) {
            str2[k++] = str[i];
        }
        i++;
    }

    str2[k] = '\0';

    printf("\nLa str2 e':\n");
    puts(str2);
}
void ex02(int vett[]) {
    for(int i = 0; i < 10; i++) {
        vett[i] = rand() % 11;
    }

    printf("\nIl vettore randomico e':\n");
    stampaVett(vett, 10);
}
void ex01(char str[]) {
    char aus1[MAX], aus2[MAX], aus3[MAX];
    int i = 0, j1 = 0, j2 = 0, j3 = 0;

    while(str[i] != '\0') {
        if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            aus1[j1++] = str[i++];
        }
        else if(str[i] >= 48 && str[i] <= 57) {
            aus2[j2++] = str[i++];
        }
        else {
            aus3[j3++] = str[i++];
        }
    }

    aus1[j1] = '\0';
    aus2[j2] = '\0';
    aus3[j3] = '\0';

    printf("\nLa stringa di caratteri e':\n");
    stampaStringa(aus1);
    printf("\nLa stringa di numeri e':\n");
    stampaStringa(aus2);
    printf("\nLa stringa di altri caratteri e':\n");
    stampaStringa(aus3);
}
void stampaVett(int vett[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vett[i]);
    }
}
void stampaStringa(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        printf("%c ", str[i]);

        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int menu();
void azzeraVett(int cont[], int n);
void ex02(char s[], int* nCons, int* nVoca);
void ex03(char s[]);
void ex04(char s[]);
void ex05(char s[]);
void ex06(char s[], char x);
void ex07(char s[]);

int main()
{
    int scelta, nCons = 0, nVoca = 0;
    char s[MAX];
    char x;

    do
    {
        scelta = menu();
        fflush(stdin);
        system("@cls||clear");

        switch(scelta)
        {
            case 1:
                printf("Inserisci la stringa: ");
                gets(s);
                printf("\n\n");
                puts(s);
                break;

            case 2:
                ex02(s, &nCons, &nVoca);

                printf("Le vocali contenuto nella stringa sono %d, mentre le consonanti sono %d...", nVoca, nCons);
                break;

            case 3:
                ex03(s);
                break;

            case 4:
                ex04(s);

                printf("La stringa modificata e': ");
                puts(s);
                break;

            case 5:
                ex05(s);

                printf("La stringa modificata e': ");
                puts(s);
                break;

            case 6:
                printf("Inserisci il carattere da modificare: ");
                scanf("%c", &x);
                ex06(s, x);

                printf("\nLa stringa modificata e': ");
                puts(s);
                break;

            case 7:
                ex07(s);
                break;

            default:
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }
    while(scelta != 0);
    printf("Programma terminato...\n");
    return 0;
}
void ex07(char s[]) {
    for(int i = 0; i < strlen(s); i++) {
        printf("Il carattere ASCII di %c e' %d\n", s[i], s[i]);
    }
}
void ex06(char s[], char x) {
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == x) {
            s[i] = '&';
        }
    }
}
void ex05(char s[]) {
    int i = 0;

    while(i < MAX) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            for(int j = i; j < MAX; j++) {
                s[j] = s[j + 1];
            }
        }
        else {
            i++;
        }
    }
}
void ex04(char s[]) {
    int i = 0;

    while(i < MAX) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            for(int j = MAX - 1; j > (i + 1); j--) {
                s[j] = s[j - 1];
            }

            s[i + 1] = s[i];
            i++;
        }

        i++;
    }
}
void ex03(char s[]) {
    int cont[26];
    char aus[MAX];

    azzeraVett(cont, 26);
    strcpy(aus, s);

    for(int i = 0; i < strlen(s); i++) aus[i] = tolower(aus[i]);

    for(int i = 0; i < strlen(s); i++) {
        if(aus[i] >= 'a' && aus[i] <= 'z') {
            cont[aus[i] - 97]++;
        }
    }

    for(int i = 0; i < 26; i++) {
        printf("Il carattere %c e' apparso %d volte\n", (i + 97), cont[i]);
    }
}
void ex02(char s[], int* nCons, int* nVoca) {
    char aus[MAX];
    int cont = 0, cont2 = 0;

    strcpy(aus, s);

    for(int i = 0; i < strlen(s); i++) aus[i] = tolower(aus[i]);

    for(int i = 0; i < strlen(s); i++) {
        if(aus[i] >= 'a' && aus[i] <= 'z') {
            if(aus[i] == 'a' || aus[i] == 'e' || aus[i] == 'i' || aus[i] == 'o' || aus[i] == 'u') {
                cont++;
            }
            else {
                cont2++;
            }
        }
    }

    *nVoca = cont;
    *nCons = cont2;
}
void azzeraVett(int cont[], int n) {
    for(int i = 0; i < n; i++) {
        cont[i] = 0;
    }
}
int menu(){
    int sc;
    printf("---------- MENU ----------\n\n");
    printf("1. Leggere una stringa str (in questo caso non è necessario richiamare una funzione)\n");
    printf("2. Contare il numero di consonanti e di vocali presenti in str \n (str passata come parametro e numero di consonanti e vocali restituiti in variabili passate per referenza)\n");
    printf("3. Contare quante volte ogni lettera dell'alfabeto compare in str senza distinguere tra maiuscole e minuscole \n  (str deve essere passata come parametro e la visualizzazione delle volte che le lettere compaiono deve essere effettuata all’interno della funzione)\n");
    printf("4. Raddoppiare le occorrenze delle vocali in str modificando str Es.: ciao → ciiaaoo \n  (str passata come parametro deve poi essere visualizzata nel main)\n");
    printf("5. Cancellare le vocali presenti in una stringa modificando str Es.: ciao → c \n  (str passata come parametro deve poi essere visualizzata nel main)\n");
    printf("6. Sostituire in str le occorrenze di un carattere preso in input con il carattere ‘&’ Es: str: pippo carattere in input: p str: &i&&0 \n  (str passata come parametro deve poi essere visualizzata nel main)\n");
    printf("7. Visualizzare il codice ASCII di tutti i caratteri contenuti in str\n");
    printf("0. Esci\n");
    printf("\nScelta -> ");
    scanf("%d", &sc);
    return sc;
}

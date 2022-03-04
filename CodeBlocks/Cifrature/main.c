#include <stdio.h>
#include <stdlib.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

void clrcls() {
    system("@cls||clear"); //direttiva che ci permette di richiamare un prog dal prompt(clear pulisce in windows, cls linux)
}

void menu(int *sc);
void miaUpper(char str[]);
ex01(char str[], int key);
ex02(char str[], int key);
ex03(char str[]);
ex04(char str[]);
ex05(char str[]);

int main()
{
    int scelta, chiave;
    char s[MAX], s2[MAX];
    srand(time(NULL));

    do{
        menu(&scelta);

        switch(scelta) {
            case 1:
                printf("\nInserisci il messaggio da cifrare: ");
                gets(s);
                miaUpper(s);

                do {
                    printf("Inserisci il valore della chiave: ");
                    scanf("%d", &chiave);
                }while(chiave < 1 || chiave > 26);

                ex01(s, chiave);
                break;

            case 2:
                printf("\nInserisci il messaggio da decifrare: ");
                gets(s);
                miaUpper(s);

                do {
                    printf("Inserisci il valore della chiave: ");
                    scanf("%d", &chiave);
                }while(chiave < 1 || chiave > 26);

                ex02(s, chiave);
                break;

            case 3:
                printf("\nInserisci il messaggio da decifrare: ");
                gets(s);
                miaUpper(s);

                ex03(s);
                break;

            case 4:
                printf("\nInserisci il messaggio da decifrare: ");
                gets(s);
                miaUpper(s);

                ex04(s);
                break;

            case 0: /*Esci*/
                break;

            case 5:
                printf("\nInserisci il messaggio da decifrare: ");
                gets(s);
                miaUpper(s);

                ex05(s);
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
ex05(char str[]) {
    char aus[26];

    for(int i = 0; i < 26; i++) {
        int num;
        int esci = FALSE;

        do {
            int j = 0;

            num = rand() % 26 + 65;
            esci = FALSE;

            while(j < i && esci == FALSE) {
                if(num == aus[j]) {
                    esci = TRUE;
                }

                j++;
            }
        }while(esci == TRUE);

        aus[i] = num;
    }
    aus[26] = '\0';
    puts(aus);

    int i = 0;

    while(str[i] != '\0') {
        int trovato = -1, j = 0;

        while(trovato == -1 && j < 26) {
            if(str[i] == aus[j]) {
                trovato = j;
            }

            j++;
        }

        str[i] = (trovato + 65);

        i++;
    }

    printf("\nIl messaggio cifrato e': ");
    puts(str);
}
ex04(char str[]) {
    char aus[26];

    for(int i = 0; i < 26; i++) {
        int num;
        int esci = FALSE;

        do {
            int j = 0;

            num = rand() % 26 + 65;
            esci = FALSE;

            while(j < i && esci == FALSE) {
                if(num == aus[j]) {
                    esci = TRUE;
                }

                j++;
            }
        }while(esci == TRUE);

        aus[i] = num;
    }
    aus[25] = '\0';
    puts(aus);

    int i = 0;

    while(str[i] != '\0') {
        str[i] = aus[(str[i] - 65)];

        i++;
    }

    printf("\nIl messaggio cifrato e': ");
    puts(str);
}
ex03(char str[]) {
    printf("\nI possibili casi sono:\n");
    char aus[MAX];

    for(int i = 0; i < 26; i++) {
        int j = 0;

        while(str[j] != '\0') {
            aus[j] = str[j];

            j++;
        }

        aus[j] = '\0';
        j = 0;


        while(aus[j] != '\0') {
            aus[j] -= i;

            if(aus[j] < 'A') {
                aus[j] += 26;
            }

            j++;
        }

        puts(aus);
    }
}
ex02(char str[], int key) {
    int i = 0;

    while(str[i] != '\0') {
        str[i] -= key;

        if(str[i] < 'A') {
            str[i] += 26;
        }

        i++;
    }

    printf("\nIl messaggio cifrato e': ");
    puts(str);
}
ex01(char str[], int key) {
    int i = 0;

    while(str[i] != '\0') {
        str[i] += key;

        if(str[i] > 'Z') {
            str[i] -= 26;
        }

        i++;
    }

    printf("\nIl messaggio cifrato e': ");
    puts(str);
}
void menu(int *sc) {
    printf("Menu\n");
    printf("0. Esci\n");
    printf("1. Cifratura di Cesare\n");
    printf("2. Decifratura di Cesare\n");
    printf("3. Decifratura di Cesare senza chiave\n");
    printf("4. Cifratura per sostituzione\n");
    printf("5. Decifratura per sostituzione\n");

    printf("\nScelta --> ");
    scanf("%d", sc);
    fflush(stdin);
}
void miaUpper(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= ('a'-'A'); //in alternativa di sottrarre 32
        i++;
    }
}

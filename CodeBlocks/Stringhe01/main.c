#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 + 1
#define TRUE 1
#define FALSE 0

void menu(int *sc);
void sostituisciPunto(char frase[]);
int palindroma(char str[]);
int anagramma(char str[], char str2[]);
void azzeraVet(int str[], int len);
int miaLen(char str[]);
void miaUpper(char str[]);
void miaLower(char str[]);

void clrcls() {
    system("@cls||clear"); //direttiva che ci consente richiamare un prog da prompt(clear pulisce in windows, cls linux)
}

int main()
{
    int scelta;
    char s[MAX], s2[MAX];

    do{
        menu(&scelta);

        switch(scelta) {
            case 1: /*Sostituisci punto con carattere a capo*/
                printf("\nInserisci frase: ");
                gets(s); //viene messo /0 al termine della frase (in binario tutti 0)

                sostituisciPunto(s);
                break;

            case 2: /*Conta vocali e consonanti di una frase*/
                break;

            case 3: /*Verifica se parola palindroma*/
                printf("\nInserisci parola: ");
                gets(s);

                if(palindroma(s) == 1) {
                    printf("\nPalindroma\n");
                }
                else {
                    printf("\nNon palindroma\n");
                }

                break;

            case 4: /*Anagramma*/
                printf("\nInserisci prima parola: ");
                gets(s);
                printf("\nInserisci seconda parola: ");
                gets(s2);

                if(anagramma(s, s2) == TRUE) {
                    printf("\n%s e' l'anagramma di %s\n", s, s2);
                }
                else {
                    printf("\n%s non e' l'anagramma di %s\n", s, s2);
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
int miaLen(char str[]) {
    int i = 1;

    while(str[i] != '\0' && i < MAX) {
        i++;
    }

    return i;
}
void miaUpper(char str[]) {
    int i = 0, c = str[i];

    while(i < miaLen(str)) {
        if(c >= 97 && c <= 122) {
            str[i] -= 32;
        }

        i++;
    }
}
void miaLower(char str[]) {
    int i = 0;

    while(i < miaLen(str)) {
        int c = str[i];
        if(c >= 65 && c <= 90) {
            str[i] += 32;
        }

        i++;
    }
}
void azzeraVet(int str[], int len) {
    for(int i = 0; i < len; i++) {
        str[i] = 0;
    }
}
void menu(int *sc) {
    printf("Menu\n");
    printf("0. Esci\n");
    printf("1. Sostituisci punto con carattere a capo\n");
    printf("2. Conta vocali e consonanti di una frase\n");
    printf("3. Verifica se parola palindroma\n");
    printf("4. Anagramma\n");
    printf("5. \n");

    printf("\nScelta --> ");
    scanf("%d", sc);
    fflush(stdin);
}
void sostituisciPunto(char frase[]) {
    // s=> buongiorno.3B INF.Sveglia!!!
    /*
        frasemodificata => buongiorno
                           3B INF
                           Sveglia!!!
    */
    int len_stringa, i;
    char fraseModificata[MAX];

    printf("\nLa frase inserita e': ");
    // printf("La frase inserita e': %s\n", frase);
    puts(frase);

    len_stringa = miaLen(frase); //passata stringa e restituisce lunghezza senza tappo
    printf("La frase contiene %d caratteri (inclusi gli spazi)\n", len_stringa);

    for(i = 0; i < len_stringa; i++) {
        if(frase[i] == '.') {
            fraseModificata[i] = '\n';
        }
        else {
            fraseModificata[i] = frase[i];
        }
    }
    fraseModificata[len_stringa] = '\0';

    printf("La frase modificata e':\n");
    puts(fraseModificata);
}
int palindroma(char str[]) {
    int len, ris, i, j; //lunghezza stringa

    len = miaLen(str);

    printf("\nLa parola contiene %d caratteti", len);

    miaLower(str);

    printf("\nLa parola inserita: ");
    puts(str);
    //controllo se str e' palindroma
    i = 0;
    j = len - 1;

    while(i < j && str[i] == str[j]) {
        i++;
        j--;
    }

    if(i >= j) {
        ris = TRUE;
    }
    else {
        ris = FALSE;
    }

    return ris;
}
int anagramma(char str[], char str2[]) {
    int len, len2, aus = TRUE, num1[26], num2[26];

    len = miaLen(str);
    len2 = miaLen(str2);

    azzeraVet(num1, len);
    azzeraVet(num2, len2);

    miaUpper(str);
    miaUpper(str2);

    if(len == len2) {
        int i = 0;

        while(str[i] != '\0') {
            num1[str[i] - 65]++;
            num2[str2[i] - 65]++;
            i++;
        }

        i = 0;

        while(i < 26 && aus == TRUE) {
            if(num1[i] != num2[i]) {
                aus = FALSE;
            }

            i++;
        }
    }
    else {
        aus = FALSE;
    }

    return aus;
}

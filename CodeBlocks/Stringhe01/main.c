#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 + 1

void menu(int *sc);
void sostituisciPunto(char frase[]);

void clrcls() {
    system("@cls||clear");
}
int main()
{
    int scelta;
    char s[MAX];

    do{
        menu(&scelta);

        switch(scelta) {
            case 1: /*Sostituisci punto con carattere a capo*/
                printf("\nInserisci frase: ");
                gets(s);
                sostituisciPunto(s);
                break;

            case 2: /*Conta vocali e consonanti di una frase*/
                break;

            case 3: /*Verifica se parola palindroma*/
                break;

            case 4: /*Anagramma*/
                break;

            case 0: /*Esci*/
                break;

            default:
                printf("Valore non corretto\n");
                break;
        }

        fflush(stdin);
        printf("\n(Premi un tasto per continuare)");
        getchar(); // Attendo pressione pulsante per proseguire
        clrcls();
    }while(scelta != 0);

    printf("Programma terminato!\n");

    return 0;
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

    len_stringa = strlen(frase);
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

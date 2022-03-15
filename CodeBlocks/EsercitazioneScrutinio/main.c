#include "scrutinio.h"

int menu();

int main()
{
    int scelta, totStudenti = 0;
    char studenti[MAX_STUDENTI] [LEN_STUDENTE];
    float valutazioni [MAX_STUDENTI] [TOT_MATERIE];

    do {
        scelta = menu();
        fflush(stdin);

        switch(scelta) {
        case 1: //Aggiungi Studente
            if(nuovoStudente(studenti, valutazioni, totStudenti) == TRUE) {
                totStudenti++;
                printf("\nStudente caricato...\n");
            }
            else {
                printf("Numero MASSIMO di studenti caricato, impossibile procedere!\n");
            }
            break;

        case 2: //Stampa Elenco Studenti
            if(totStudenti > 0) {
                stampaValutazioni(studenti, valutazioni, totStudenti);
            }
            else {
                printf("Nessuno studente caricato\n");
            }
            break;

        case 3: //Calcola e Visualizza scrutinio

            break;

        case 4: //Genere nuove valutazioni

            break;

        case 0: //Esci
            break;

        default:
            break;
        }

        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta != 0);

    printf("Programma terminato!");

    return 0;
}
int menu() {
    int sc;

    printf("MENU\n");
    printf("1. Aggiungi Studente\n");
    printf("2. Stampa Elenco Studenti\n");
    printf("3. Calcola e Visualizza scrutinio\n");
    printf("4. Genere nuove valutazioni\n");
    printf("0. Esci\n");

    printf("\nSCELTA --> ");
    scanf("%d", &sc);

    return sc;
}

#include "scrutinio.h"

int menu();

int main()
{
    int scelta, totStudenti = 0;
    char studenti[MAX_STUDENTI][LEN_STUDENTE], esito[MAX_STUDENTI];
    float valutazioni [MAX_STUDENTI] [TOT_MATERIE], medie[MAX_STUDENTI];

    do {
        scelta = menu();
        fflush(stdin);

        switch(scelta) {
        case 1: //Aggiungi Studente
            if(nuovoStudente(studenti, valutazioni, totStudenti, medie, esito) == TRUE) {
                totStudenti++;
                printf("\nStudente caricato...\n");
            }
            else {
                printf("Numero MASSIMO di studenti caricato, impossibile procedere!\n");
            }
            break;

        case 2: //Stampa Elenco Studenti
            if(totStudenti > 0) {
                stampaValutazioni(studenti, valutazioni, totStudenti, medie, esito);
            }
            else {
                printf("Nessuno studente caricato\n");
            }
            break;

        case 3: //Calcola e Visualizza scrutinio
            scrutinio(studenti, valutazioni, totStudenti, esito);
            break;

        case 4: //Genere nuove valutazioni
            nuoveValutazioni(valutazioni, medie, esito, totStudenti);
            printf("\nNuove valutazioni caricate!");
            break;

        case 5: //Ordina studente
            ordinaStudenti(studenti, valutazioni, totStudenti, medie, esito);
            stampaValutazioni(studenti, valutazioni, totStudenti, medie, esito);
            break;

        case 6: //Stampa dati su FILE
            stampaScrutinio("scrutinio.txt", studenti, valutazioni, totStudenti, medie, esito);
            printf("\nStampa terminata!");
            break;

        case 7:
            leggiFile("studenti.txt");
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
    printf("5. Ordina studenti\n");
    printf("6. Stampa su FILE\n");
    printf("7. Leggi da FILE\n");
    printf("0. Esci\n");

    printf("\nSCELTA --> ");
    scanf("%d", &sc);

    return sc;
}

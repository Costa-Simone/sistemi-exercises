#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Utility.h"
#include "Scuderie.h"
#include "Piloti.h"
#include "Gran Premi.h"

#define MAX_DATI 50

int menu();

int main(){
    int scelta;
    char stampa;
    Piloti pil[MAX_DATI];
    Scuderie scud[MAX_DATI];
    Granpremi gp[MAX_DATI];
    int len_pil = 0, len_scud = 0, len_gp = 0;

    len_pil = caricaPilotiDaFile("File/piloti.csv", pil);
    len_scud = caricaScuderieDaFile("File/scuderie.csv", scud);
    len_gp = caricaGranPremiDaFile("File/granpremi.csv", gp);

    do
    {
        scelta = menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta)
        {
        case 1: /** Elenco Piloti **/
            printf("---------- STAMPA ELENCO PILOTI ----------\n\n");
            elencoPiloti(pil, len_pil, scud, len_scud);
            break;
        case 2: /** Elenco Scuderie **/
            printf("---------- STAMPA ELENCO SCUDERIE ----------\n\n");
            elencoScuderie(scud, len_scud);
            break;
        case 3: /** Elenco GP **/
            printf("---------- STAMPA ELENCO GRAN PREMI ----------\n\n");
            elencoGP(gp, len_gp);
            break;
        case 4: /** Avvia GP Singolo **/
            generaGPSingolo(pil, len_pil, scud, len_scud, gp, len_gp);
            break;
        case 5: /** Avvia tutti i Gran Premi (+ Richiesta stampa su File) **/
            generaTuttiGP(pil, len_pil, scud, len_scud, gp, len_gp);
            break;
        case 6: /** Mostra Classifica Piloti (+ Richiesta stampa su File) **/
            fflush(stdin);
            printf("---------- STAMPA CLASSIFICA PILOTI ----------\n\n");
            mostraClassificaPiloti(pil, len_pil, scud, len_scud);
            printf("\nVuoi la stampa su File? [y/n]: ");
            scanf("%c", &stampa);
            if(stampa == 'y')
                stampaSuFilePiloti(pil, len_pil);
            break;
        case 7: /** Mostra Classifica Scuderie (+ Richiesta stampa su File) **/
            mostraClassificaScuderie(scud, len_scud);
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

int menu(){
    int sc;
    printf("---------- MENU ----------\n\n");
    printf("1. Elenco Piloti\n");
    printf("2. Elenco Scuderie\n");
    printf("3. Elenco GP\n");
    printf("4. Avvia GP Singolo\n");
    printf("5. Avvia tutti i Gran Premi (+ Richiesta stampa su File)\n");
    printf("6. Mostra Classifica Piloti (+ Richiesta stampa su File)\n");
    printf("7. Mostra Classifica Scuderie (+ Richiesta stampa su File)\n");
    printf("8. Resetta Punteggi Piloti & Scuderie\n");
    printf("0. Esci\n");
    printf("\nScelta -> ");
    scanf("%d", &sc);
    return sc;
}

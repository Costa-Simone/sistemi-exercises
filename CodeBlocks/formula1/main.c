#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Piloti.h"
#include "Scuderie.h"
#include "Gran Premi.h"

#define MAX_DATI 50

int menu();

int main(){
    int scelta;
    Piloti pil[MAX_DATI];
    Scuderie scud[MAX_DATI];
    Granpremi gp[MAX_DATI];
    int len_pil = 0, len_scud = 0, len_gp = 0;

    printf("\n---------- TABELLA PILOTI ----------\n\n");
    len_pil = caricaPilotiDaFile("File/piloti.csv", pil);
    printf("\n---------- TABELLA SCUDERIE ----------\n\n");
    len_scud = caricaScuderieDaFile("File/scuderie.csv", scud);
    printf("\n---------- TABELLA GRAN PREMI ----------\n\n");
    len_gp = caricaGranPremiDaFile("File/granpremi.csv", gp);

    do
    {
        scelta = menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta)
        {

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
    printf("\n---------- MENU ----------\n\n");
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

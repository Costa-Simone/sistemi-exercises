#include <stdio.h>
#include <stdlib.h>
#inclede <string.h>
#include "piloti.h"
#include "scuderie.h"
#include "granpremi.h"

#define MAX_DATI 50

int menu();
int main()
{
    int scelta;
    Piloti pil[MAX_DATI];
    Scuderie scud[MAX_DATI];
    Granpremi gp[MAX_DATI];
    int len_pil=0,len_scud=0, len_gp=0;

    len_pil=caricaPilotiDaFile("file/piloti.csv", pil);

    do{
        scelta=menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta){

        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }while(scelta != 0);
    printf("Programmma terminato \n");
    return 0;
}

int menu(){
    int sc;

    printf("1. Elenco piloti\n");
    printf("2. Elenco scuderie\n");
    printf("3. Elenco GranPremi\n");
    printf("4. Avvia GP singolo\n");
    printf("5. Avvia tutti i GP (+ Richiesta stampa su file)\n");
    printf("6. Mostra classifica piloti (+ Richiesta stampa su file)\n");
    printf("7. Mostra classifica scuderie (+ Richiesta stampa su file)\n");
    printf("8. Resetta Punteggi piloti & scuderie \n");
    printf("0. Esci\n");

    printf("Scelta --> ");
    scanf("%i",&sc);
    return sc;
}

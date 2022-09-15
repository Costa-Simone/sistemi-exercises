
    // Stampa in forma tabellare il calendario di un mese
// dell'anno 2022
//
//       GEN 2022
// LU MA ME GI VE SA DO
//                 1  2
//  3  4

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inpMese,totGiorni,i,gSett,day;
    int gMese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char mesi[12][4] = {"GEN","FEB","MAR","APR","MAG","GIU","LUG","AGO","SET","OTT","NOV","DIC"};
    char settimana[7][3] = {"LU","MA","ME","GI","VE","SA","DO"};
  // input del mese
    do {
    printf("Mese (1 GEN, 2 FEB ...): ");
    scanf("%d",&inpMese);

    if((inpMese<1)||(inpMese>12))
    {
        printf("Il mese deve essere compreso tra 1 e 12\n");
    }

    }while((inpMese<1)||(inpMese>12));
    inpMese--; // inpMese diventa l'indice del vettore mesi

    // giorni settimana: 0-LU 1-MA 2-ME ...
    totGiorni = 5;  // il 1o gennaio 2022 è sabato
    // calcolo dei giorni passati dall'inizio dell'anno
    for(i=0;i<inpMese;i++)
    {
        totGiorni += gMese[i];
    }

    gSett = totGiorni%7;// giorno della settimana del primo del mese

    printf("Il primo di %s cade di %s\n\n", mesi[inpMese], settimana[gSett]);

    // visualizzazione tabellare
    printf("      %s 2022\n", mesi[inpMese]);

    for(i=0;i<7;i++)
    {
        printf("%s ",settimana[i]);
    }

    printf("\n");
    // posizionamento nella prima riga
    for(i=0;i<gSett;i++)
    {
        printf("   ");
    }
    // ciclo visualizzazione giorni del mese
    for(day = 1; day <= gMese[inpMese]; day++)
    {
        if(gSett % 7 == 0)
        {
            printf("\n");
        }

        printf("%2d ", day);

        gSett++;
    }

    //---------------------------Calendario intero----------------------------------------------------

    /*printf("\n\nStampa intero calendario:\n\n");

    for(int k = 0; k <12; k++) {

        printf("      %s 2022\n", mesi[k]);

        totGiorni = 5;

        for(i=0;i<k;i++)
        {
            totGiorni += gMese[i];
        }

        gSett = totGiorni%7;

        for(i=0;i<7;i++)
        {
            printf("%s ",settimana[i]);
        }
        printf("\n");

        for(i=0;i<gSett;i++)
        {
            printf("   ");
        }
        for(day = 1; day <= gMese[k]; day++)
        {
            if(gSett % 7 == 0)
            {
                printf("\n");
            }

            printf("%2d ", day);

            gSett++;
        }
        printf("\n\n");

    }*/

    //---------------------------Giorno settimana e numero settimana----------------------------------------------------

    int inpGiorno;

    do{
            do {
        printf("\n\nGiorno ");
        scanf("%d",&inpGiorno);

        if((inpGiorno<1)||(inpGiorno>31))
        {
            printf("Il giorno deve essere compreso tra 1 e 31\n");
        }

        }while((inpGiorno<1)||(inpGiorno>31));

        do {
            printf("Mese ");
            scanf("%d",&inpMese);

            if((inpMese<1)||(inpMese>12))
            {
                printf("Il mese deve essere compreso tra 1 e 12\n");
            }

        }while((inpMese<1)||(inpMese>12));
        inpMese--;
    }while(inpGiorno > gMese[inpMese]);



    totGiorni = 5;

    for(i=0;i<inpMese;i++)
    {
        totGiorni += gMese[i];
    }

    totGiorni += inpGiorno - 1;

    printf("\nSettimana %d", totGiorni / 7);

    gSett = totGiorni%7;

    printf("\nGiorno %s", settimana[gSett]);

    printf("\n");

  return 0;
}

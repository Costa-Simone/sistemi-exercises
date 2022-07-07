#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int menu();
void ex01(int inpMese, int inpAnno, int bise, int totGiorni, int gMese[], char mesi[12][4], char settimana[7][3]);
void ex02(int inpAnno, int bise, int totGiorni,  int gMese[], char mesi[12][4], char settimana[7][3]);

int main()
{
    int scelta;
    int inpMese, inpAnno, bise, totGiorni;
    int gMese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char mesi[12][4] = {"GEN","FEB","MAR","APR","MAG","GIU","LUG","AGO","SET","OTT","NOV","DIC"};
    char settimana[7][3] = {"LU","MA","ME","GI","VE","SA","DO"};

    do
    {
        scelta = menu();
        totGiorni = 0;

        fflush(stdin);
        system("@cls||clear");

        switch(scelta)
        {
            case 1: //Visualizza il calendario di un mese
                do {
                    printf("Inserisci il numero del mese: ");
                    scanf("%d", &inpMese);
                } while(inpMese < 1 || inpMese > 12);

                inpMese--;

                do {
                    printf("Inserisci l'anno compreso tra il 1900 e il 2022: ");
                    scanf("%d", &inpAnno);
                } while(inpAnno < 1900 || inpAnno > 2022);

                if(inpAnno % 4 != 0) {
                    bise = FALSE;
                    gMese[1] = 28;
                }
                else if(inpAnno % 4 == 0 && inpAnno % 100 == 0 && inpAnno % 400 != 0) {
                    bise = FALSE;
                    gMese[1] = 28;
                }
                else {
                    bise = TRUE;
                    gMese[1] = 29;
                }

                if(inpAnno != 1900) {
                    for(int i = 0; i <= (inpAnno - 1901); i++) {
                        if((i + 1901) % 4 != 0) {
                            totGiorni++;
                        }
                        else if((i + 1901) % 4 == 0 && (i + 1901) % 100 == 0 && (i + 1901) % 400 != 0) {
                            totGiorni++;
                        }
                        else {
                            totGiorni += 2;
                        }

                        if(totGiorni == 7) {
                            totGiorni -= 7;
                        }
                    }
                }

                ex01(inpMese, inpAnno, bise, totGiorni, gMese, mesi, settimana);
                break;

            case 2: //Visualizza il calendario di un anno
                do {
                    printf("Inserisci l'anno compreso tra il 1900 e il 2022: ");
                    scanf("%d", &inpAnno);
                } while(inpAnno < 1900 || inpAnno > 2022);

                if(inpAnno % 4 != 0) {
                    bise = FALSE;
                    gMese[1] = 28;
                }
                else if(inpAnno % 4 == 0 && inpAnno % 100 == 0 && inpAnno % 400 != 0) {
                    bise = FALSE;
                    gMese[1] = 28;
                }
                else {
                    bise = TRUE;
                    gMese[1] = 29;
                }

                if(inpAnno != 1900) {
                    for(int i = 0; i <= (inpAnno - 1901); i++) {
                        if((i + 1901) % 4 != 0) {
                            totGiorni++;
                        }
                        else if((i + 1901) % 4 == 0 && (i + 1901) % 100 == 0 && (i + 1901) % 400 != 0) {
                            totGiorni++;
                        }
                        else {
                            totGiorni += 2;
                        }

                        if(totGiorni == 7) {
                            totGiorni -= 7;
                        }
                    }
                }

                ex02(inpAnno, bise, totGiorni, gMese, mesi, settimana);
                break;

            case 3: //Visualizza il giorno della settimana di una data
                break;

            case 4: //Visualizza la differenza in giorni tra due date
                break;

            default:
                break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    } while(scelta != 0);

    printf("Programma terminato...\n");
    return 0;
}
void ex02(int inpAnno, int bise, int totGiorni,  int gMese[], char mesi[12][4], char settimana[7][3]) {
    printf("\n");

    for(int k = 0; k < 12; k++) {
        int gSett;

        if(k != 0) {
            totGiorni += gMese[k];
        }

        gSett = totGiorni % 7;

        printf("%s %d\n", mesi[k], inpAnno);

        for(int i = 0; i < 7; i++) {
            printf("%s ", settimana[i]);
        }

        printf("\n");
        for(int i = 0; i < gSett; i++) {
            printf("   ");
        }

        for(int day = 1; day <= gMese[k]; day++) {
            if(gSett % 7 == 0) {
                printf("\n");
            }

            printf("%2d ", day);

            gSett++;
        }

        printf("\n\n");
    }
}
void ex01(int inpMese, int inpAnno, int bise, int totGiorni, int gMese[], char mesi[12][4], char settimana[7][3]) {
    int gSett;

    printf("\n");

    for(int i = 0; i < inpMese; i++) {
        totGiorni += gMese[i];
    }

    gSett = totGiorni % 7;

    printf("%s %d\n", mesi[inpMese], inpAnno);

    for(int i = 0; i < 7; i++) {
        printf("%s ", settimana[i]);
    }

    printf("\n");
    for(int i = 0; i < gSett; i++) {
        printf("   ");
    }

    for(int day = 1; day <= gMese[inpMese]; day++) {
        if(gSett % 7 == 0) {
            printf("\n");
        }

        printf("%2d ", day);

        gSett++;
    }
}
int menu(){
    int sc;
    printf("---------- MENU ----------\n\n");
    printf("1. Visualizza il calendario di un mese\n");
    printf("2. Visualizza il calendario di un anno\n");
    printf("3. Visualizza il giorno della settimana di una data\n");
    printf("4. Visualizza la differenza in giorni tra due date\n");
    printf("0. Uscita\n");

    scanf("%d", &sc);
    return sc;
}

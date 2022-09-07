#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define DATA 11

int menu();
void ex01(int inpMese, int inpAnno, int bise, int totGiorni, int gMese[], char mesi[12][4], char settimana[7][3]);
void ex02(int inpAnno, int bise, int totGiorni,  int gMese[], char mesi[12][4], char settimana[7][3]);
void splittaString(char row[], char spl[], int pos, char separatore);
void controlloAnno(int inpAnno, int* bise, int gMese[]);
void primoGiornoAnno(int inpAnno, int* totGiorni);
void ex03(int d, int m, int a, int bise, int totGiorni,  int gMese[], char mesi[12][4], char settimana[7][3]);
void ex04(a, a2, m, m2, a, a2, bise, bise2, totGiorni, totGiorni2, gMese, gMese2, mesi);
int distanzaPrimoGennaio1900(int d, int a, int m, int gMese[]);

int main()
{
    int scelta;
    int inpMese, inpAnno, bise, bise2, totGiorni, totGiorni2;
    int gMese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int gMese2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char mesi[12][4] = {"GEN","FEB","MAR","APR","MAG","GIU","LUG","AGO","SET","OTT","NOV","DIC"};
    char settimana[7][3] = {"LU","MA","ME","GI","VE","SA","DO"};
    char input[DATA], aus[5];
    int d, m, a, d2, m2, a2, diff;

    do
    {
        scelta = menu();
        totGiorni = 0;
        totGiorni2 = 0;

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

                controlloAnno(inpAnno, &bise, gMese);
                primoGiornoAnno(inpAnno, &totGiorni);

                ex01(inpMese, inpAnno, bise, totGiorni, gMese, mesi, settimana);
                break;

            case 2: //Visualizza il calendario di un anno
                do {
                    printf("Inserisci l'anno compreso tra il 1900 e il 2022: ");
                    scanf("%d", &inpAnno);
                } while(inpAnno < 1900 || inpAnno > 2022);

                controlloAnno(inpAnno, &bise, gMese);
                primoGiornoAnno(inpAnno, &totGiorni);

                ex02(inpAnno, bise, totGiorni, gMese, mesi, settimana);
                break;

            case 3: //Visualizza il giorno della settimana di una data
                do {
                    printf("Inserisci la prima data(deve essere compresa tra il 1/1/1900 e il 31/12/2022, e scritta in formato DD/MM/AA): ");
                    gets(input);
                    splittaString(input, aus, 0, '/');

                    d = atoi(aus);

                    splittaString(input, aus, 1, '/');

                    m = atoi(aus);
                    m--;

                    splittaString(input, aus, 2, '/');

                    a = atoi(aus);

                    controlloAnno(inpAnno, &bise, gMese);
                } while((m < 0 || m > 11) || (d < 0 || d > gMese[m]) || (a < 1900 || a > 2022));

                primoGiornoAnno(a, &totGiorni);
                ex03(d, m, a, bise, totGiorni, gMese, mesi, settimana);
                break;

            case 4: //Visualizza la differenza in giorni tra due date
                do {
                    printf("Inserisci la prima data(deve essere compresa tra il 1/1/1900 e il 31/12/2022, e scritta in formato DD/MM/AA): ");
                    gets(input);
                    splittaString(input, aus, 0, '/');

                    d = atoi(aus);

                    splittaString(input, aus, 1, '/');

                    m = atoi(aus);
                    m--;

                    splittaString(input, aus, 2, '/');

                    a = atoi(aus);

                    controlloAnno(inpAnno, &bise, gMese);
                } while((m < 0 || m > 11) || (d < 0 || d > gMese[m]) || (a < 1900 || a > 2022));

                controlloAnno(a, &bise, gMese);
                primoGiornoAnno(a, &totGiorni);

                do {
                    printf("Inserisci la seconda data(deve essere compresa tra il 1/1/1900 e il 31/12/2022, e scritta in formato DD/MM/AA): ");
                    gets(input);
                    splittaString(input, aus, 0, '/');

                    d2 = atoi(aus);

                    splittaString(input, aus, 1, '/');

                    m2 = atoi(aus);
                    m2--;

                    splittaString(input, aus, 2, '/');

                    a2 = atoi(aus);

                    controlloAnno(inpAnno, &bise, gMese);
                } while((m2 < 0 || m2 > 11) || (d2 < 0 || d2 > gMese[m]) || (a2 < 1900 || a2 > 2022));

                controlloAnno(a2, &bise2, gMese2);
                primoGiornoAnno(a2, &totGiorni2);

                totGiorni = distanzaPrimoGennaio1900(d, a, m, gMese);
                totGiorni2 = distanzaPrimoGennaio1900(d2, a2, m2, gMese2);

                diff = abs(totGiorni - totGiorni2);

                printf("\nLa differenza in giorni tra le due date e' %d giorni", diff);
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
int distanzaPrimoGennaio1900(int d, int a, int m, int gMese[]) {
    int cont = 0;

    for(int i = 1900; i < a; i++) {
        if(i % 4 != 0) {
            cont += 365;
        }
        else if(i % 4 == 0 && i % 100 == 0 && i % 400 != 0) {
            cont += 365;
        }
        else {
            cont += 366;
        }
    }

    for(int i = 0; i < m; i ++) {
        cont += gMese[i];
    }

    cont += d;

    return cont;
}
void ex03(int d, int m, int a, int bise, int totGiorni,  int gMese[], char mesi[12][4], char settimana[7][3]) {
    int gSett, day = 1, aus = d;

    printf("\n");

    for(int i = 0; i < m; i++) {
        totGiorni += gMese[i];
    }

    gSett = totGiorni % 7;

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
void splittaString(char row[], char spl[], int pos, char separatore){
    int cnt = 0;
    int i = 0;

    while(cnt != pos)
    {
        while(row[i] != separatore)
            i++;
        cnt++;
        i++;
    }
    cnt = 0;
    while(row[i] != separatore && row[i] != '\0'){
        spl[cnt] = row[i];
        i++;
        cnt++;
    }
    spl[cnt] = '\0';
}
void controlloAnno(int inpAnno, int* bise, int gMese[]) {
    if(inpAnno % 4 != 0) {
        *bise = FALSE;
        gMese[1] = 28;
    }
    else if(inpAnno % 4 == 0 && inpAnno % 100 == 0 && inpAnno % 400 != 0) {
        *bise = FALSE;
        gMese[1] = 28;
    }
    else {
        *bise = TRUE;
        gMese[1] = 29;
    }
}
void primoGiornoAnno(int inpAnno, int* totGiorni) {
    int aus = *totGiorni;

    if(inpAnno != 1900) {
        for(int i = 0; i <= (inpAnno - 1901); i++) {
            if((i + 1901) % 4 != 0) {
                aus++;
            }
            else if((i + 1901) % 4 == 0 && (i + 1901) % 100 == 0 && (i + 1901) % 400 != 0) {
                aus++;
            }
            else {
                aus += 2;
            }

            if(aus >= 7) {
                aus -= 7;
            }
        }
    }

    *totGiorni = aus;
}

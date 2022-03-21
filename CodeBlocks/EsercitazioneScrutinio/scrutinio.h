#ifndef SCRUTINIO_H_INCLUDED
#define SCRUTINIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STUDENTI 20
#define LEN_STUDENTE 30 + 1
#define TOT_MATERIE 5
#define TRUE 1
#define FALSE 0

float float_rand(float min, float max){
    float val;
    //srand(time(NULL));
    val = rand() / (float) RAND_MAX;  // [0, 1.0]
    return min + (val * (max - min));
}
int nuovoStudente(char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], int pos) {
    int i, caricato = FALSE;
    float v;

    if(pos < MAX_STUDENTI){
        printf("Inserisci nome: ");
        gets(studenti[pos]);

        for(i=0; i<TOT_MATERIE; i++){
            v = float_rand(2, 10);
            valutazioni[pos][i] = v;
        }
        caricato = TRUE;
    }

    return caricato;
}
void stampaValutazioni(char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], int pos) {
    int i;
    printf("INFO\tTPSIT\tSIS\tITA\tMAT\tALUNNO/A\n");
    for(i=0; i<pos; i++){
        printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
               valutazioni[i][0], valutazioni[i][1], valutazioni[i][2],
               valutazioni[i][3], valutazioni[i][4], studenti[i]);
    }
}
void ordinaStudenti(char studenti[MAX_STUDENTI][LEN_STUDENTE], float valutazioni[MAX_STUDENTI][TOT_MATERIE], int pos) {
    int posMin;
    float aus;
    char ausStr[LEN_STUDENTE];

    for(int i = 0; i <= pos - 2; i++) {
        posMin = i;

        for(int j = i + 1; j <= pos - 1; j++) {
            int k = 0, esci = FALSE;

            while(esci == FALSE && studenti[posMin][k] != '\0' && studenti[j][k] != '\0') {
                if(studenti[posMin][k] > studenti[j][k]) {
                    posMin = j;
                    esci = TRUE;
                }
                k++;
            }

            if(posMin != i) {
                strcpy(ausStr, studenti[i]);
                strcpy(studenti[i], studenti[posMin]);
                strcpy(studenti[posMin], ausStr);

                for(int k = 0; k < TOT_MATERIE; k++) {
                    aus = valutazioni[i][k];
                    valutazioni[i][k] = valutazioni[posMin][k];
                    valutazioni[posMin][k] = aus;
                }
            }
        }
    }
}

#endif // SCRUTINIO_H_INCLUDED

#ifndef SCRUTINIO_H_INCLUDED
#define SCRUTINIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTI 20
#define LEN_STUDENTE 31
#define TOT_MATERIE 5
#define TRUE 1
#define FALSE 0

float float_rand(float min, float max) {
    float val;

    srand(time(NULL));
    val = rand() / (float) RAND_MAX; // [0, 1.0]

    return min + (val * (max - min));
}
int nuovoStudente(char studenti [MAX_STUDENTI][LEN_STUDENTE], int valutazioni [MAX_STUDENTI][TOT_MATERIE], int pos) {
    int caricato = FALSE;
    char nome[LEN_STUDENTE];
    float v;

    if(pos < MAX_STUDENTI) {
        caricato = TRUE;

        printf("\nInserisci nome: ");
        gets(studenti[pos]); //riga della matrice caricata col nome

        for(int i = 0; i < TOT_MATERIE; i++) {
            v = float_rand(2, 10);
            valutazioni[pos][i] = v;
        }
    }

    return caricato;
}
void stampaValutazioni(char studenti [MAX_STUDENTI][LEN_STUDENTE], int valutazioni [MAX_STUDENTI][TOT_MATERIE], int pos) {
    printf("INFO\tTPSIT\tSIS\tITA\tMAT\tALUNNO/A\n");

    for(int i = 0; i < pos; i++) {
        printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n", valutazioni[i][0], valutazioni[i][1], valutazioni[i][2], valutazioni[i][3],
               valutazioni[i][4], studenti[i]);
    }
}

#endif // SCRUTINIO_H_INCLUDED

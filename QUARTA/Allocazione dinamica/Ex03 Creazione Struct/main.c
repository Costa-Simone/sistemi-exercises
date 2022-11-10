#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 30

typedef struct studente {
    int matr;
    char nome[MAX];
    float inf, sis, tpsit;
} Studenti;

Studenti* creaNodo();
void stampaNodo(Studenti *pStu);

int main() {
    Studenti vS[20];
    Studenti *nodo;

    nodo = creaNodo();

    stampaNodo(nodo);
    return 0;
}

void stampaNodo(Studenti *pStu) {
    printf("\nSTAMPA STUDENTE\n");
    printf("%d\t%s\t%.2f\t%.2f\t%.2f\n", pStu->matr, pStu->nome, pStu->inf, pStu->sis, pStu->tpsit);
}
Studenti* creaNodo() {
    Studenti *pStu;
    int matricola;
    char nominativo[MAX];
    float info, sist, tpsi;

    printf("Matricola --> ");
    scanf("%d", &matricola);
    fflush(stdin);
    printf("Nome --> ");
    gets(nominativo);
    fflush(stdin);
    printf("Informatica --> ");
    scanf("%f", &info);
    fflush(stdin);
    printf("Sistemi --> ");
    scanf("%f", &sist);
    fflush(stdin);
    printf("Tpsit --> ");
    scanf("%f", &tpsi);
    fflush(stdin);

    pStu = (Studenti*) malloc(sizeof(Studenti));
    pStu->matr = matricola;
    pStu->inf = info;
    pStu->sis = sist;
    pStu->tpsit = tpsi;

    strcpy(pStu->nome, nominativo);

    return pStu;
}

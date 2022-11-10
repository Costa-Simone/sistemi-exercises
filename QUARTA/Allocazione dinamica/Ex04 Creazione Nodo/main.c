#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 30

typedef struct dipendente {
    char matricola[5];
    char cognome[MAX];
    int eta;
    struct dipendente *next;
} Dipendenti;

Dipendenti* nuovoDipendente();
Dipendenti* addOnHead(Dipendenti *testa);

int main() {
    Dipendenti *testa = NULL;

    srand(time(NULL));

    testa = addOnHead(testa);

    return 0;
}

Dipendenti* addOnHead(Dipendenti *testa) {
    Dipendenti *nodo;

    nodo = nuovoDipendente();

    if(testa == NULL) {
        testa = nodo;
    }
    else {
        nodo->next = testa;
        testa = nodo;
    }

    return testa;
}
Dipendenti* nuovoDipendente() {
    Dipendenti *pDip;
    char matr[4];
    char cogn[MAX];
    int eta, i;

    // AA00 [A-Z] [0-9]
    for (i = 0; i < 2; i++) {
        matr[i] = 'A' + rand() % ('A' - 'Z');
    }
    for (i = 2; i < 4; i++) {
        matr[i] = '0' + rand() % ('0' - '9');
    }

    // INSIMENTO COGNOME
    printf("Cognome --> ");
    gets(cogn);
    fflush(stdin);
    // INSERIMENTO ETA
    printf("Eta --> ");
    scanf("%d", &eta);

    pDip = (Dipendenti*) malloc(sizeof(Dipendenti));

    strcpy(pDip->matricola, matr);
    strcpy(pDip->cognome, cogn);

    pDip->eta = eta;
    pDip->next = NULL;

    return pDip;
}

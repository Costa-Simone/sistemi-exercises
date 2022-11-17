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
Dipendenti* addOnTail(Dipendenti *testa);
int contaNodi(Dipendenti *testa);
void showList(Dipendenti *testa);
Dipendenti* addByPos(Dipendenti *testa, int pos);

int main() {
    Dipendenti *testa;
    int pos;

    srand(time(NULL));

    testa = NULL;
    testa = addOnHead(testa);
    testa = addOnHead(testa);
    testa = addOnTail(testa);

    printf("\nIl numero di nodi e': %d", contaNodi(testa));
    showList(testa);
    printf("\nInserisci la posizione in cui aggiungere il nodo: ");
    scanf("%d", &pos);
    fflush(stdin);

    pos--;
    testa = addByPos(testa, pos);

    showList(testa);

    return 0;
}

Dipendenti* addByPos(Dipendenti *testa, int pos) {
    Dipendenti *nuovoNodo, *pLista, *pNodoSucc;
    int i;

    nuovoNodo = nuovoDipendente();
    i = 0;
    pLista = testa;

    if(pos == 0) {
        nuovoNodo->next = testa;
        testa = nuovoNodo;
    }
    else {
        while(pLista->next != NULL && i < pos - 1) {
            pLista = pLista->next;
            i++;
        }

        pNodoSucc = pLista->next;
        pLista->next = nuovoNodo;
        nuovoNodo->next = pNodoSucc;
    }

    return testa;
}
void showList(Dipendenti *testa) {
    Dipendenti *pLista;

    pLista = testa;

    printf("\n\nMatricola\tCognome\tEta");

    do {
        printf("\n%s\t\t%s\t%d", pLista->matricola, pLista->cognome, pLista->eta);

        pLista = pLista->next;
    } while(pLista != NULL);
}
int contaNodi(Dipendenti *testa) {
    Dipendenti *pLista;
    int cont;

    cont = 0;

    if(testa != NULL) {
        pLista = testa;

        do {
            cont++;
            pLista = pLista->next;
        } while(pLista != NULL);
    }

    return cont;
}
Dipendenti* addOnTail(Dipendenti *testa) {
    Dipendenti *nuovoNodo, *pLista;

    nuovoNodo = nuovoDipendente();

    if(testa == NULL) {
        testa = nuovoNodo;
    }
    else {
        pLista = testa;

        while(pLista->next != NULL) {
            pLista = pLista->next;
        }

        pLista->next = nuovoNodo;
    }

    return testa;
}
Dipendenti* addOnHead(Dipendenti *testa) {
    Dipendenti *nodo;

    nodo = nuovoDipendente();

    if(testa == NULL) { // nessun nodo nella lista
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
    char matr[5];
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
    printf("\nCognome --> ");
    gets(cogn);
    fflush(stdin);
    // INSERIMENTO ETA
    printf("Eta --> ");
    scanf("%d", &eta);
    fflush(stdin);

    pDip = (Dipendenti*) malloc(sizeof(Dipendenti));

    strcpy(pDip->matricola, matr);
    strcpy(pDip->cognome, cogn);

    pDip->eta = eta;
    pDip->next = NULL;

    return pDip;
}

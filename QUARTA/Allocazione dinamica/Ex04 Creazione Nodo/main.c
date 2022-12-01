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
Dipendenti* delByPos(Dipendenti *testa, int pos);

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
    printf("\n\nInserisci la posizione in cui aggiungere il nodo: ");
    scanf("%d", &pos);
    fflush(stdin);

    testa = addByPos(testa, pos);

    showList(testa);

    printf("\n\nInserisci la posizione in cui rimuovere il nodo: ");
    scanf("%d", &pos);
    fflush(stdin);

    testa = delByPos(testa, pos);

    showList(testa);

    return 0;
}

Dipendenti* delByPos(Dipendenti *testa, int pos) {
    Dipendenti *pLista, *nextNodo;
    int i;

    if(testa == NULL) {
        printf("La lista e' vuota");
    }
    else {
        if(pos == 1) {
            nextNodo = testa;
            testa = testa->next;

            free(nextNodo);
        }
        else {
            pLista = testa->next;
            nextNodo = testa;
            i = 1;

            while(i < (pos - 1) && pLista->next != NULL) {
                nextNodo = pLista;
                pLista = pLista->next;
                i++;
            }

            nextNodo->next = pLista->next;

            free(pLista);
        }
    }

    return testa;
}
Dipendenti* addByPos(Dipendenti *testa, int pos) {
    Dipendenti *nuovoNodo, *pLista;
    int i;

    if(pos <= 1) {
        testa = addOnHead(testa);
    }
    else {
        if(pos > contaNodi(testa)) {
            testa = addOnTail(testa);
        }
        else {
            nuovoNodo = nuovoDipendente();
            pLista = testa;

            for(i = 1; i < (pos - 1); i++) {
                pLista = pLista->next;
            }

            nuovoNodo->next = pLista->next;
            pLista->next = nuovoNodo;
        }
    }

    return testa;
}
void showList(Dipendenti *testa) {
    Dipendenti *pLista;

    pLista = testa;

    if (pLista == NULL) {
        printf("\n\nLista vuota");
    }
    else {
        printf("\n\nMatricola\tCognome\tEta");

        do {
            printf("\n%s\t\t%s\t%d", pLista->matricola, pLista->cognome, pLista->eta);

            pLista = pLista->next;
        } while(pLista != NULL);
    }


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

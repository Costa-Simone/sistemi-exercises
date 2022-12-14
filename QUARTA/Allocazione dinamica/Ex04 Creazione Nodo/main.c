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
Dipendenti* addOrdinato(Dipendenti *testa);
Dipendenti* sortListByCogn(Dipendenti *testa);
void sortListByCognWithNode(Dipendenti *testa);
Dipendenti* mergeDueListe(Dipendenti *t1, Dipendenti *t2, Dipendenti *t3);

int main() {
    Dipendenti *testa, *testa2, *testa3;
    int pos, i;

    srand(time(NULL));
    printf("Prima lista:\n");

    testa = NULL;
    testa = addOnHead(testa);
    testa = addOnTail(testa);
    testa = addOnTail(testa);

    printf("\nIl numero di nodi nella prima lista e': %d", contaNodi(testa));
    showList(testa);

    printf("\nSeconda lista:\n");

    testa2 = NULL;
    testa2 = addOnHead(testa2);
    testa2 = addOnTail(testa2);
    testa2 = addOnTail(testa2);

    printf("\nIl numero di nodi nella seconda lista e': %d", contaNodi(testa2));
    showList(testa2);
    //printf("\n\nInserisci la posizione in cui aggiungere il nodo: ");
    //scanf("%d", &pos);
    //fflush(stdin);

    //testa = addByPos(testa, pos);

    //showList(testa);

    //printf("\n\nInserisci la posizione in cui rimuovere il nodo: ");
    //scanf("%d", &pos);
    //fflush(stdin);

    //testa = delByPos(testa, pos);

    //showList(testa);

    /*
    for(i = 0; i < 5; i++) {
        testa = addOrdinato(testa);
    }*/

    // void sortListByCognWithNode(Dipendenti *testa);
    //testa = sortListByCogn(testa);
    //printf("\n\nLista ordinata:");
    //showList(testa);

    testa = mergeDueListe(testa, testa2, testa3);
    printf("\nLista della merge:\n");
    showList(testa);

    return 0;
}

Dipendenti* mergeDueListe(Dipendenti *t1, Dipendenti *t2, Dipendenti *t3) {
    Dipendenti *pLista1, *pLista2, *pLista3;

    pLista1 = t1;
    pLista2 = t2;
    pLista3 = t1;
    t3 = pLista3;

    while (pLista1->next != NULL) {
        pLista3->next = pLista1->next;
        pLista1 = pLista1->next;
        pLista3 = pLista3->next;
    }

    pLista3->next = pLista2;
    pLista3 = pLista3->next;

    while (pLista2->next != NULL) {
        pLista3->next = pLista2->next;
        pLista2 = pLista2->next;
        pLista3 = pLista3->next;
    }

    sortListByCogn(t1);

    return t1;
}
void sortListByCognWithNode(Dipendenti *testa) {
    Dipendenti *l1, *l2, *prec1, *prec2, *next1, *next2;
    int rifare = 1;
    char aus[MAX];
    int ausEta;

    while (rifare == 1) {
        rifare = 0;

        for(l1 = testa->next; l1->next != NULL; l1 = l1->next) {
            prec1 = testa;

            for(l2 = l1->next; l2 != NULL; l2 = l2->next) {
                prec2 = l1;

                if(strcmp(l1->cognome, l2->cognome) > 0) {
                    strcpy(aus, l1->matricola);
                    strcpy(l1->matricola, l2->matricola);
                    strcpy(l2->matricola, aus);
                    strcpy(aus, l1->cognome);
                    strcpy(l1->cognome, l2->cognome);
                    strcpy(l2->cognome, aus);

                    ausEta = l1->eta;
                    l1->eta = l2->eta;
                    l2->eta = ausEta;
                    rifare = 1;
                }
            }
        }
    }
}
Dipendenti* sortListByCogn(Dipendenti *testa) {
    Dipendenti *l1, *l2, *prec, *prec2, *aus;
    int rifare = 1;

    prec = NULL;
    l1 = NULL;
    l2 = NULL;
    aus = NULL;

    while (rifare == 1) {
        rifare = 0;

        for(l1 = testa; l1->next != NULL; l1 = l1->next) {
            prec2 =NULL;

            for(l2 = l1->next; l2 != NULL; l2 = l2->next) {
                if(strcmp(l1->cognome, l2->cognome) > 0) {
                    if(prec == NULL && prec2 == NULL) {
                        aus = l2->next;
                        l2->next = l1;
                        l1->next = aus;
                        testa->next = aus;
                        aus = l2;
                        l2 = l1;
                        l1 = aus;
                        testa = aus;
                    } else if(prec == NULL && prec2 != NULL) {
                        aus = l2->next;
                        prec2->next = aus;
                        l2->next = l1;
                        l1 = l2;
                        testa = l2;
                        l2 = prec2;
                    } else if(prec != NULL && prec2 == NULL) {
                        aus = l2->next;
                        l1->next = aus;
                        prec->next = l2;
                        l2->next = l1;
                        aus = l2;
                        l1 = l2;
                        l2 = aus;
                    } else if(prec != NULL && prec2 != NULL) {
                        aus = l2->next;
                        prec->next = l2;
                        l2->next = l1;
                        prec2->next = aus;
                        aus = l2;
                        l2 = prec2;
                        l1 = aus;
                    }

                    rifare = 1;
                }

                prec2 = l2;
            }

            prec = l1;
        }
    }

    return testa;
}
Dipendenti* addOrdinato(Dipendenti *testa) {
    Dipendenti *nodo, *pLista, *pPrec;

    nodo = nuovoDipendente();

    if(testa == NULL) {
        testa = nodo;
    } else {
        if(strcmp(testa->cognome, nodo->cognome) > 0) {
            nodo->next = testa;
            testa = nodo;
        } else {
            pPrec = testa;
            pLista = pPrec->next;

            while (pLista != NULL && strcmp(nodo->cognome, pLista->cognome) > 0) {
                pPrec = pLista;
                pLista = pLista->next;
            }

            nodo->next = pLista;
            pPrec->next = nodo;
        }
    }

    return testa;
}
Dipendenti* delByPos(Dipendenti *testa, int pos) {
    Dipendenti *pLista, *precNodo;
    int i;

    if(testa == NULL) {
        printf("La lista e' vuota");
    } else {
        if(pos == 1) {
            precNodo = testa;
            testa = testa->next;

            free(precNodo);
        } else {
            pLista = testa->next;
            precNodo = testa;
            i = 1;

            while(i < (pos - 1) && pLista->next != NULL) {
                precNodo = pLista;
                pLista = pLista->next;
                i++;
            }

            precNodo->next = pLista->next;

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

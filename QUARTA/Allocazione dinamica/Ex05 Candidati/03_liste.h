#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct candidato
{
    char matricola[6];
    char cognome[15];
    char regione[15];
    int punti1, punti2, punti3;
    float media;
    struct candidato *next;
} Candidati;

Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi);
Candidati* addOnHead(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in testa alla lista
Candidati* addOnTail(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in coda alla lista
Candidati* nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3);
Candidati* ManualCandidate(Candidati *head);
Candidati* SorteMedie(Candidati* head)
Candidati* BestCandidateForRegion(Candidati *head);
Candidati* Best3Candidates(Candidati *head);
Candidati* FindAndDeleteNode(Candidati *head);
void SaveBackUp(char* file_backup, Candidati *head);
int contaNodi(Candidati *head);
void showList(Candidati *head);

void SaveBackUp(char* file_backup, Candidati *head) {
    FILE *fpB;
    Candidati *pLista;

    pLista = head;
    fpB = fopen(file_backup, "w");

    while(pLista != NULL) {
        fprintf(fpB ,"%s %s %s %d %d %d %.2f\n",
                pLista->matricola, pLista->cognome, pLista->regione, pLista->punti1, pLista->punti2, pLista->punti3, pLista->media);

        pLista = pLista->next;
    }

    fclose(fpB);
}
Candidati* FindAndDeleteNode(Candidati *head) {
    char matr[10];
    bool find = FALSE;
    Candidati *pLista, *pPrec, *aus;

    pLista = head;
    pPrec = NULL;

    printf("Inserisci la matricola da cercare ed eliminare: ");
    gets(matr);
    fflush(stdin);

    while(pLista != NULL && find == FALSE) {
        if(strcmp(pLista->matricola, matr) == 0) {
            if(pPrec == NULL) {
                find = TRUE;
                aus = head;
                head = head->next;
                free(aus);
            }
            else {
                find = TRUE;
                aus = pLista;
                pPrec->next = pLista->next;
                free(aus);
            }
        }

        pPrec = pLista;
        pLista = pLista->next;
    }

    if(find == TRUE) {
        printf("\nCandidato eliminato correttamente!");
    }
    else {
        printf("\nCandidato non trovato!");
    }

    return head;
}
Candidati* Best3Candidates(Candidati *head) {
    Candidati *pLista;

    head = SorteMedie(head);
}
Candidati* SorteMediep(Candidati* head){
    int scambio=0;
    Candidati *aus, *l1;

    do {
        scambio=0;

        if(head->media < head->next->media) {//primi 2 elementi
            scambio = 1;
            aus = head->next;
            head->next = aus->next;
            aus->next = head;
            head = aus;
        }

        for(l1=head; l1->next->next != NULL; l1 = l1->next) {
            if(l1->next->media < l1->next->next->media) {
                scambio = 1;
                aus = l1->next->next;
                l1->next->next = aus->next;
                aus->next = l1->next;
                l1->next = aus;
            }
        }
    }while(scambio==1);

    return head;
}
Candidati* ManualCandidate(Candidati *head) {
    Candidati* nodo;
    char matr[6], cogn[20], reg[20];
    int p1, p2, p3, i;

    for(i = 0; i < 2; i++) {
        matr[i]= 'A' + rand()%('Z'-'A');
    }

    for(i = 2; i < 5; i++) {
        matr[i] = '0' + rand()%('0'-'9');
    }

    matr[5] = '\0';

    printf("Inserisci il cognome del candidato: ");
    gets(cogn);
    fflush(stdin);

    i = 0;

    while(cogn[i] != '\0'){
        cogn[i] = toupper(cogn[i]);
        i++;
    }

    printf("Inserisci la regione del candidato: ");
    gets(reg);
    fflush(stdin);

    i=0;

    while(reg[i] != '\0'){
        reg[i]=toupper(reg[i]);

        i++;
    }

    printf("Inserisci i primi punti del candidato: ");
    scanf("%d", &p1);
    fflush(stdin);

    printf("Inserisci i secondi punti del candidato: ");
    scanf("%d", &p2);
    fflush(stdin);

    printf("Inserisci i terzi punti del candidato: ");
    scanf("%d", &p3);
    fflush(stdin);

    if(head == NULL) {
        head = addOnHead(head, matr, cogn, reg, p1, p2, p3);
    }
    else {
        head = addOnTail(head, matr, cogn, reg, p1, p2, p3);
    }

    return head;
}
Candidati * nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3) {
    Candidati *nodo;

    // CARICAMENTO DATI IN NUOVO NODO
    nodo = (Candidati*) malloc(sizeof(Candidati));

    strcpy(nodo->matricola, matr);
    strcpy(nodo->cognome, cogn);
    strcpy(nodo->regione, reg);
    nodo->punti1 = p1;
    nodo->punti2 = p2;
    nodo->punti3 = p3;
    /* TODO: CALCOLO DELLA MEDIA */
    nodo->media = (float)((p1 + p2 + p3) / 3);

    nodo->next = NULL;
    return nodo;
}
Candidati * addOnHead(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3) {
    Candidati *nodo;

    nodo = nuovoCandidato(matr, cogn, reg, p1, p2, p3);

    if (testa == NULL)
        testa = nodo;
    else
    {
        nodo->next = testa;
        testa = nodo;
    }
    return testa;
}
Candidati * addOnTail(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3) {
    Candidati *nodo, *pLista;

    nodo = nuovoCandidato(matr, cogn, reg, p1, p2, p3);

    if(testa == NULL)
        testa = addOnHead(testa, matr, cogn, reg, p1, p2, p3);
    else
    {
        pLista = testa;
        while(pLista->next != NULL)
            pLista = pLista->next;
        pLista->next = nodo;
    }
    return testa;
}
Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi) {
    FILE *fpC, *fpP;
    bool trovato;
    char row_file[20+1];
    int p1, p2, p3;
    char matr[6], cogn[20], reg[20];
    char matrP[10];
    char sp1[5], sp2[5], sp3[5];
    int i=0, j=0;
    fpC = fopen(file_name_candidati, "r"); // Apertura file in modalità read

    if (fpC == NULL && fpP == NULL)
        printf("Apertura files non riuscita\n");
    else{
        while(!feof(fpC)){ // Scorro il file, riga per riga, fino a quando non raggiungo EOF
            fscanf(fpC, "%s %s %s", matr, cogn, reg);
            //printf("LETTO: %s %s %s\n", matr, cogn, reg);
            trovato = FALSE;
            fpP = fopen(file_name_punteggi, "r"); // Apertura file in modalità read
            while((!feof(fpP)) && trovato==FALSE){
                fscanf(fpP, "%s %s %s %s", matrP, sp1, sp2, sp3);
                if (strcmp(matr, matrP) == 0)
                    trovato = TRUE;
            }
            fclose(fpP); // Chiusura del file

            if (trovato == TRUE){
                p1 = atoi(sp1);
                p2 = atoi(sp2);
                p3 = atoi(sp3);
                head = addOnTail(head, matr, cogn, reg, p1, p2, p3);
            }
        }
    }
    fclose(fpC); // Chiusura del file
    return head;
}
int contaNodi(Candidati *head) {
    int tot = 0;
    Candidati *pDip;
    pDip = head;

    while(pDip != NULL)
    {
        tot++;
        pDip = pDip->next;
    }
    return tot;
}
void showList(Candidati *head){
    Candidati *pLista;

    if (head == NULL)
        printf("Lista Vuota\n");
    else{
        pLista = head;
        printf("Lista Canditati\n");
        printf("Matr.\tPunti1\tPunti2\tPunti3\tMedia\tCognome (Regione)\t\t\n");
        do{
            /* TODO: MODIFICARE PER LA CORRETTA VISUALIZZAZIONE DELLE MEDIE */
            printf("%s\t%d\t%d\t%d\t%.2f\t%s (%s)\n",
                    pLista->matricola, pLista->punti1, pLista->punti2, pLista->punti3, pLista->media ,pLista->cognome, pLista->regione);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}

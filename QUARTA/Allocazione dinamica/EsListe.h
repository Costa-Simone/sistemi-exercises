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
}Candidati;

Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi);
Candidati* addOnHead(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in testa alla lista
Candidati* addOnTail(Candidati *head, char matr[], char cogn[], char reg[], int p1, int p2, int p3); // Add nodo in coda alla lista
Candidati* nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3);
int contaNodi(Candidati *head);
void showList(Candidati *head);
int caricaCandidato(Candidati *head, char matr[], char cognome[], char regione[], int p1, int p2, int p3);
void eseguiBackup(Candidati* head, char* file_name);
Candidati * ordinaSelezioneRegione(Candidati *head);
void stampaMiglioriRegione(Candidati *head);
Candidati * ordinaSelezioneMedia(Candidati *head);
int cercaNodo(Candidati *head, char *matr); 
Candidati * eliminaNodo(Candidati *head, int pos);
/**********************/
Candidati * nuovoCandidato(char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
    Candidati *nodo; 
   
    // CARICAMENTO DATI IN NUOVO NODO 
    nodo = (Candidati*) malloc(sizeof(Candidati));

    strcpy(nodo->matricola, matr); 
    strcpy(nodo->cognome, cogn); 
    strcpy(nodo->regione, reg); 
    nodo->punti1 = p1; 
    nodo->punti2 = p2; 
    nodo->punti3 = p3; 
    nodo->media = (float) (p1+p2+p3)/3; 
    nodo->next = NULL;
    return nodo; 
}
Candidati * addOnHead(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
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
Candidati * addOnTail(Candidati *testa, char matr[], char cogn[], char reg[], int p1, int p2, int p3)
{
    Candidati *nodo, *pLista; 

    if(testa == NULL)
        testa = addOnHead(testa, matr, cogn, reg, p1, p2, p3); 
    else
    {
        nodo = nuovoCandidato(matr, cogn, reg, p1, p2, p3); 
        pLista = testa; 
        while(pLista->next != NULL)
            pLista = pLista->next;
        pLista->next = nodo;
    }
    return testa; 
} 
Candidati* loadFromFile(Candidati *head, char* file_name_candidati, char* file_name_punteggi)
{
    FILE *fpC, *fpP;
    bool trovato;
    char row_file[20+1];
    int p1, p2, p3; 
    char matr[10], cogn[20], reg[20]; 
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
int caricaCandidato(Candidati *head, char matr[], char cognome[], char regione[], int p1, int p2, int p3)
{
    Candidati *nodo;
    printf("%s %s %s %d %d %d", matr, cognome, regione, p1, p2, p3); 
    /*nodo = nuovoCandidato(matr, cognome, regione, p1, p2, p3); */
    head = addOnTail(head, matr, cognome, regione, p1, p2, p3); 
    if (head != NULL)
        return TRUE; 
    return FALSE; 
}
int contaNodi(Candidati *head)
{
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
            printf("%s\t%d\t%d\t%d\t%.2f\t%s (%s)\n", 
                    pLista->matricola, pLista->punti1, pLista->punti2, pLista->punti3, pLista->media, pLista->cognome, pLista->regione);
            pLista = pLista->next;
        }
        while(pLista != NULL);
    }
}
void swapNodes(Candidati** head_ref, Candidati *x, Candidati *y)
{ /* NON OTTIMIZZATO: ANDREBBE TENUTA IN CONSIDERAZIONE LA POSSIBILITA' CHE I NODI SIANO <= 2 */
    Candidati *prevX = NULL, *currX = *head_ref;
    Candidati *prevY = NULL, *currY = *head_ref;
    Candidati *aus; // PER SCAMBIO NODI 

    /* POSIZIONAMENTO NODO PRECEDENTE X */
    while (currX && currX != x) {
        prevX = currX;
        currX = currX->next;
    }
    /* POSIZIONAMENTO NODO PRECEDENTE Y */
    while (currY && currY != y) {
        prevY = currY;
        currY = currY->next;
    }

    /* CONTROLLO SE NODO X PRECEDENTE E' NULLO O MENO (CASO NODO DI TESTA) */
    if (prevX != NULL)
        prevX->next = currY;
    else 
        *head_ref = currY;
 
    
    if (prevY != NULL) /* NON SI VERIFICA A MENO CHE LA LISTA NON SIA VUOTA */
        prevY->next = currX;
    else 
        *head_ref = currX;
 
    aus = currY->next;
    currY->next = currX->next;
    currX->next = aus;
}
Candidati * posizionaNodo(Candidati *head, int pos)
{
    int i; 
    Candidati *posizione = head; 
    for(i=0; i<pos; i++)
        posizione = posizione->next; 
    return posizione; 
}
Candidati * ordinaSelezioneRegione(Candidati *head)
{
    //ordinamento per selezione CRESCENTE
    int n = contaNodi(head);
    int aus;
    Candidati *n1, *n2; 
    Candidati *posmin; 
    for (int i = 0; i <= n - 2; i++) 
    {
        posmin = posizionaNodo(head, i);
        n1 = posizionaNodo(head, i); 
        for (int j = i + 1; j <= n - 1; j++) 
        {
            n2 = posizionaNodo(head, j); 
            if (strcmp(posmin->regione, n2->regione) > 0)
            {
                posmin = n2;  
            }
                
        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&head, n1, posmin);
    }
    return head; 
}
void stampaMiglioriRegione(Candidati *head)
{
    int n = contaNodi(head); 
    int i; 
    Candidati *l1 = head; 
    Candidati *l2 = l1->next; 
    int max = l1->media; 
    char migliore[15]; 

    strcpy(migliore, l1->cognome); 

    for(; l2->next != NULL; l2 = l2->next) 
    {
        if(strcmp(l1->regione, l2->regione) == 0)
        {
            if (l2->media > max) 
            {
                max = l2->media;    
                strcpy(migliore, l2->cognome); 
            }
        }   
        else
        { // REGIONE CAMBIATA 
            printf("Migliore regione %s: %s con %d punti\n", l1->regione, migliore, max);
            max = l2->media; 
        }
        l1 = l1->next; 
    }
    // SENZA L'UTILIZZO DI UN "TAPPO" SONO COSTRETTO A TENERE IN CONSIDERAZIONE ANCHE L'ULTIMA REGIONE FUORI DAL CICLO
    printf("Migliore regione %s: %s con %d punti\n", l1->regione, l2->cognome, max);
}
Candidati * ordinaSelezioneMedia(Candidati *head)
{
    //ordinamento per selezione DECRESCENTE
    int n = contaNodi(head);
    int aus;
    Candidati *n1, *n2; 
    Candidati *posmin; 
    for (int i = 0; i <= n - 2; i++) 
    {
        posmin = posizionaNodo(head, i);
        n1 = posizionaNodo(head, i); 
        for (int j = i + 1; j <= n - 1; j++) 
        {
            n2 = posizionaNodo(head, j); 
            if (posmin->media < n2->media)
                posmin = n2;  
                
        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&head, n1, posmin);
    }
    return head; 
}
int cercaNodo(Candidati *head, char *matr)
{
    Candidati *pLista = head; 
    int pos = 0; 
    while(pLista != NULL && strcmp(pLista->matricola, matr) != 0)
    {
        pos++; 
        pLista = pLista->next;
    }
    if(pLista == NULL)
        return -1; 
    return pos; 
}
Candidati * eliminaNodo(Candidati *head, int pos)
{
    Candidati *pDip = head; 
    Candidati *pDel;

    if (pos == 0)
    {
        head = pDip->next;
        free(pDip); 
    }
    else
    {
        for(int i=1; i<pos; i++)
            pDip = pDip->next;
        pDel = pDip->next;
        pDip->next = pDel->next;
        free(pDel);
    }
    return head;
}
void eseguiBackup(Candidati* head, char* file_name)
{
    FILE *fp; 
    Candidati* pLista = head; 

    fp = fopen(file_name, "w"); 
    while(pLista->next != NULL)
    {
        fprintf(fp, "%s;%s;%s;%d;%d;%f\n", pLista->matricola, pLista->cognome, pLista->regione,
                pLista->punti1, pLista->punti2, pLista->punti3, pLista->media); 
        pLista = pLista->next;
    }
    fclose(fp); 
}
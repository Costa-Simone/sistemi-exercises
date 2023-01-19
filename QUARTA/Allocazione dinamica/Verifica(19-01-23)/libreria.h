#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Libro
{
    int cod;
    char isbn[14];
    char titolo[100];
    char autore[50];
    char editore[50];
    int nPag;
    struct Libro *next;
}Libri;

Libri* loadFromFile(Libri *head, char *filename);
void splittaString(char row[], char ret[], int pos, char separatore);
Libri* inserisciNodo(Libri *head, int _cod, char *_isbn, char *_titolo, char *_autore, char *_editore, int _nPag);
int contaNodi(Libri *head);
void stampaLista(Libri *head);
Libri* FindAndDeleteNode(Libri* head);
Libri * LibriWithMoreThanXPage(Libri *head);
Libri* SorteForPagine(Libri *head);
Libri* posizionaNodo(Libri *head, int pos);
void swapNodes(Libri** head_ref, Libri *x, Libri *y);
Libri* LoadOnSecondListLibriOfAnEditor(Libri *head);
Libri* SorteForEditor(Libri *head);
/* ----------------------------------------------------------------------------------------------------- */
Libri* LoadOnSecondListLibriOfAnEditor(Libri *head) {
    char editor[50];
    Libri *pLista, *pLista2;
    Libri *head2 = NULL;

    printf("Inserisci editore da cercare: ");
    gets(editor);
    fflush(stdin);

    head = SorteForEditor(head);
    pLista = head;
    pLista2 = head2;

    while(pLista != NULL && strcmp(pLista->editore, editor) <= 0) {
        if(strcmp(pLista->editore, editor) == 0) {
            head2 = inserisciNodo(head2, pLista->cod, pLista->isbn, pLista->titolo, pLista->autore, pLista->editore, pLista->nPag);
        }

        pLista = pLista->next;
    }

    if(head2 == NULL) {
        printf("\nNessun editore trovato!");
    }
    else {
        stampaLista(head2);
    }

    return head;
}
Libri* SorteForEditor(Libri *head) {
    int n = contaNodi(head);
    int aus;
    Libri *n1, *n2;
    Libri *posmin;

    for (int i = 0; i <= n - 2; i++)
    {
        posmin = posizionaNodo(head, i);
        n1 = posizionaNodo(head, i);

        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(head, j);

            if (strcmp(posmin->editore, n2->editore) > 0)
            {
                posmin = n2;
            }

        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&head, n1, posmin);
    }
    return head;
}
Libri * LibriWithMoreThanXPage(Libri *head) {
    int xPag;
    Libri *pLista;

    printf("Inserisci il numero di pagine minime da visualizzare: ");
    scanf("%d", &xPag);
    fflush(stdin);

    pLista = SorteForPagine(head);

    while(pLista != NULL && pLista->nPag >= xPag) {
        printf("%15s%30s%100s[%d]\n", pLista->isbn, pLista->autore, pLista->titolo, pLista->nPag);

        pLista = pLista->next;
    }

    return head;
}
Libri* SorteForPagine(Libri *head) {
    int n = contaNodi(head);
    int aus;
    Libri *n1, *n2;
    Libri *posmin;

    for (int i = 0; i <= n - 2; i++)
    {
        posmin = posizionaNodo(head, i);
        n1 = posizionaNodo(head, i);

        for (int j = i + 1; j <= n - 1; j++)
        {
            n2 = posizionaNodo(head, j);

            if (posmin->nPag < n2->nPag)
            {
                posmin = n2;
            }

        }
        if (n1 != posmin)  //serve a sapere se devo fare o no lo scambio
            swapNodes(&head, n1, posmin);
    }
    return head;
}
void swapNodes(Libri** head_ref, Libri *x, Libri *y) { /* NON OTTIMIZZATO: ANDREBBE TENUTA IN CONSIDERAZIONE LA POSSIBILITA' CHE I NODI SIANO <= 2 */
    Libri *prevX = NULL, *currX = *head_ref;
    Libri *prevY = NULL, *currY = *head_ref;
    Libri *aus; // PER SCAMBIO NODI

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
Libri* posizionaNodo(Libri *head, int pos) {
    int i;
    Libri *posizione = head;

    for(i=0; i<pos; i++)
        posizione = posizione->next;

    return posizione;
}
Libri* FindAndDeleteNode(Libri* head) {
    Libri *pLista, *pPrec;
    char vetISIN[14];

    printf("Inserisci ISIN da cercare ed evntualmente eliminare: ");
    gets(vetISIN);
    fflush(stdin);

    pLista = head;
    pPrec = NULL;

    while(pLista->next != NULL && strcmp(vetISIN, pLista->isbn) != 0) {
        pPrec = pLista;
        pLista = pLista->next;
    }

    if(strcmp(vetISIN, pLista->isbn) == 0) {
        if(pPrec == NULL) {
            pPrec = pLista;
            head = pLista->next;

            free(pPrec);
        }
        else {
            pPrec->next = pLista->next;

            free(pLista);
        }

        printf("\nLibro trovato ed eliminato correttamente!");
    }
    else {
        printf("\nLibro non trovato!");
    }

    return head;
}
int contaNodi(Libri *head){
    int cnt = 0;
    for(; head != NULL; head = head->next)
        cnt++;
    return cnt;
}
void splittaString(char row[], char ret[], int pos, char separatore){
    int cnt = 0;
    int i = 0;

    while(cnt != pos){
        while(row[i] != separatore)
            i++;
        cnt++;
        i++;
    }
    cnt = 0;
    while(row[i] != separatore && row[i] != '\0'){
        ret[cnt] = row[i];
        i++;
        cnt++;
    }
    ret[cnt] = '\0';
}
Libri *loadFromFile(Libri *head, char *filename){
    FILE *fp;
    char *token; // Split
    int i;
    char v[100];

    char line[200];
    int _cod;
    char _isbn[14];
    char _titolo[100];
    char _autore[50];
    char _editore[50];
    int _nPag;

    fp = fopen(filename, "r");

    while(!feof(fp))
    {
        fgets(line, 200, fp);
        splittaString(line, v, 0, ';'); _cod = atoi(v);
        splittaString(line, _isbn, 1, ';');
        splittaString(line, _titolo, 2, ';');
        splittaString(line, _autore, 3, ';');
        splittaString(line, _editore, 4, ';');
        splittaString(line, v, 5, ';');  _nPag = atoi(v);
        head = inserisciNodo(head, _cod, _isbn, _titolo, _autore, _editore, _nPag);
    }
    fclose(fp);
    return head;
}
Libri * inserisciNodo(Libri *head, int _cod, char *_isbn, char *_titolo, char *_autore, char *_editore, int _nPag){
    Libri *new, *aus;

    new = (Libri*) malloc(sizeof(Libri));

    new->cod = _cod;
    new->nPag = _nPag;
    strcpy(new->isbn, _isbn);
    strcpy(new->titolo, _titolo);
    strcpy(new->autore, _autore);
    strcpy(new->editore, _editore);
    new->next = NULL;

    if (head == NULL)
        head = new;
    else
    {
        aus = head;
        while(aus->next != NULL)
            aus = aus->next;
        aus->next = new;
    }
    return head;
}
void stampaLista(Libri *head) {
   for(; head != NULL; head = head->next)
        printf("%15s%30s%100s[%d]\n",
            head->isbn, head->autore, head->titolo, head->nPag);
}

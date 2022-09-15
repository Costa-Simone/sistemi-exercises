#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 101
#define TRUE 1
#define FALSE 0

int menu();
void ex01(int n, int a[]);
void ex02(int n, int a[], char str[]);
void ex03(int a[], int n, int* somma, int* media);
void ex04(int a[], int n, int* min, int* max);
int ex05(int a[], int n, int* sommaPos, int* sommaNeg);
void ex06(int a[], int n, int pari[], int dispari[], int* nPari, int* nDispari);
int ex07(int v[]);
void ex08(int a[], int n);
int ex09(int a[], int n, int x);
int ex10(int a[], int n);

int main()
{
    int scelta;
    int a[MAX], pari[MAX], dispari[MAX], v[10];
    int n, nPari = 0, nDispari = 0, somma = 0, media, min = 100, max = -21, sommaPos = 0, sommaNeg = 0, x;

    do
    {
        scelta = menu();
        fflush(stdin);
        system("@cls||clear");
        switch(scelta)
        {
        case 1:
            printf("Inserisci quanti elementi vuoi inserire nel vettore A: ");
            scanf("%d", &n);

            ex01(n, a);
            break;

        case 2:
            ex02(n, a, "Vettore a:\n");

            printf("\n\nStampa terminata...");
            break;

        case 3:
            ex03(a, n, &somma, &media);

            printf("La somma dei valori del vettore e' %d, mentre la media e' %d", somma, media);
            break;

        case 4:
            ex04(a, n, &min, &max);

            printf("Il valore massimo e' %d, mentre quello minimo e' %d", max, min);
            break;

        case 5:
            if(ex05(a, n, &sommaPos, &sommaNeg) == TRUE) {
                printf("La somma dei numeri positivi e' maggiore...");
            }
            else {
                printf("La somma dei numeri negativi e' maggiore...");
            }
            break;

        case 6:
            ex06(a, n, pari, dispari, &nPari, &nDispari);
            ex02(nPari, pari, "Vettore numeri pari:\n");
            ex02(nDispari, dispari, "\nVettore numeri dispari:\n");
            break;

        case 7:
            if(ex07(v) == FALSE) {
                printf("\nIl vettore e' speculare...");
            }
            else {
                printf("\nIl vettore non e' speculare...");
            }
            break;

        case 8:
            ex08(a, n);
            ex02(n, a, "Il vettore ordinato e':\n");
            break;

        case 9:
            printf("Inserisci il valore da cercare: ");
            scanf("%d", &x);

            printf("\n\nIl valore %d e' apparso %d volte...", x, ex09(a, n, x));
            break;

        case 10:
            printf("Nel vettore sono contenuti %d numeri primi...", ex10(a, n));
            break;

        default:
            break;
        }
        fflush(stdin);
        getchar();
        system("@cls||clear");
    }
    while(scelta != 0);
    printf("Programma terminato...\n");
    return 0;
}
int ex10(int a[], int n) {
    int cont = 0;

    for(int i = 0; i < n; i++) {
        if(abs(a[i]) % 2 != 0 && abs(a[i]) % 3 != 0) {
            cont++;
        }
    }

    return cont;
}
int ex09(int a[], int n, int x) {
    int cont = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            cont++;
        }
    }

    return cont;
}
void ex08(int a[], int n) {
    int PosMin, aus;

    for (int i = 0; i <= n - 2; i++)
    {
        PosMin = i;

        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[PosMin] > a[j])
            {
                PosMin = j;
            }
        }

        if (PosMin != i)
        {
            aus = a[i];
            a[i] = a[PosMin];
            a[PosMin] = aus;
        }
    }
}
int ex07(int v[]) {
    int j = 0, esci = FALSE;

    for(int i = 0; i < 10; i++) {
        printf("\nInserisci il %d valore del vettore: ", (i + 1));
        scanf("%d", &v[i]);
    }

    while(esci == FALSE && j <= 5) {
        if(v[j] != v[9 - j]) {
            esci = TRUE;
        }
        else {
            j++;
        }
    }

    if(esci == FALSE) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}
void ex06(int a[], int n, int pari[], int dispari[], int* nPari, int* nDispari) {
    int j = 0, k = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            pari[j++] = a[i];
        }
        else {
            dispari[k++] = a[i];
        }
    }

    *nPari = j;
    *nDispari = k;
}
int ex05(int a[], int n, int* sommaPos, int* sommaNeg) {
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            *sommaPos += a[i];
        }
        else {
            *sommaNeg += a[i];
        }
    }

    *sommaNeg = abs(*sommaNeg);

    if(*sommaPos >= *sommaNeg) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}
void ex04(int a[], int n, int* min, int* max) {
    for(int i = 0; i < n; i++) {
        if(a[i] > *max) {
            *max = a[i];
        }
        if(a[i] < *min) {
            *min = a[i];
        }
    }
}
void ex03(int a[], int n, int* somma, int* media) {
    for(int i = 0; i < n; i++) {
        *somma += a[i];
    }

    *media = *somma / n;
}
void ex02(int n, int a[], char str[]) {
    puts(str);

    for(int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}
void ex01(int n, int a[]) {
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        int s = rand() % 2;
        int v = rand() % 21;

        if(s == 0) {
            a[i] = v;
        }
        else {
            a[i] = -v;
        }
    }

    printf("\nCaricamento effettuato con successo...");
}
int menu(){
    int sc;
    printf("---------- MENU ----------\n\n");
    printf("1. Caricamento di un vettore A con valori casuali da -20 a 20, dopo aver chiesto quanti elementi si vogliono inserire\n");
    printf("2. Visualizzazione del vettore A (la funzione deve visualizzare qualunque vettore)\n");
    printf("3. Calcolo della somma e della media degli elementi del vettore A \n        (la funzione deve effettuare i calcoli su un vettore qualsiasi e restituirli in variabili passate per referenza)\n");
    printf("4. Ricerca del valore minimo e del valore massimo degli elementi contenuti nel vettore A \n     (la funzione ricerca i valori su un vettore qualsiasi e li restituisce in variabili passate per referenza)\n");
    printf("5. Calcolo della somma degli elementi positivi e della somma degli elementi negativi del vettore A");
    printf("restituendo quale somma è maggiore in valore assoluto \n        (la funzione restituisce al main 1 se è maggiore la somma dei valori positivi e 0 se maggiore la somma in valore assoluto dei");
    printf("valori negativi. \n     Può essere richiamata su un vettore qualsiasi e restituisce le due somme in variabili passate per referenza)\n");
    printf("6. Creare i vettori PARI e DISPARI formati rispettivamente dagli elementi pari e dispari presenti in A \n       (i tre vettori devono essere passati come parametro e visualizzati nel main)\n");
    printf("7. Verificare se un vettore di 10 numeri interi, preso in input all’interno della funzione, è speculare");
    printf("\n      (per es. è formato dagli elementi 1,2,3,2,1. Nel main deve essere visualizzato “Speculare” oppure “Non speculare”.\n");
    printf("8. Cercare nel vettore A un numero preso in input nel main e passato come parametro \n      (visualizzare nel main quante volte è contenuto nel vettore)\n");
    printf("9. Ordinare il vettore A passato come parametro e visualizzarlo nel main.\n");
    printf("10. Contare quanti valori del vettore A, presi in valore assoluto, sono primi");
    printf("\n      (La funzione deve eseguire il conteggio su un vettore qualsiasi e restituisce quanti numeri primi sono contenuti)\n");
    printf("0. Esci\n");
    printf("\nScelta -> ");
    scanf("%d", &sc);
    return sc;
}

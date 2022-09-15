#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 101

void azzeraVett(int v[]);
void generaCart(int cart1[], int cart2[], int cart3[], int cart4[], int v[]);
void stampaCart(int cart[], char p[]);
int controllaNumero(int cart[], int numero);
void controlloVincita(int cart[], int* controllo, char p[], int cont[], char output[], int* vincitore);

int main()
{
    srand(time(NULL));

    int v[90], cart1[15], cart2[15], cart3[15], cart4[15];
    int vincitore = 0, numero, controllo = 2;
    char p1[MAX], p2[MAX], p3[MAX], p4[MAX];
    char output[MAX], intro[MAX], risultato[MAX];
    int cont1[3], cont2[3], cont3[3], cont4[3];

    azzeraVett(v);
    printf("Nome del primo giocatore: ");
    gets(p1);
    printf("Nome del secondo giocatore: ");
    gets(p2);
    printf("Nome del terzo giocatore: ");
    gets(p3);
    printf("Nome del quarto giocatore: ");
    gets(p4);
    generaCart(cart1, cart2, cart3, cart4, v);
    printf("========\n");
    printf("CARTELLE\n");
    printf("========\n");
    stampaCart(cart1, p1);
    stampaCart(cart2, p2);
    stampaCart(cart3, p3);
    stampaCart(cart4, p4);
    azzeraVett(v);
    azzeraVett(cont1);
    azzeraVett(cont2);
    azzeraVett(cont3);
    azzeraVett(cont4);

    do {
        printf("== Premi un tasto per continuare ==\n");
        getchar();

        do {
            numero = rand() % 90 + 1;
        } while(v[numero - 1] == TRUE);

        v[numero - 1] = TRUE;

        printf("NUMERO ESTRATTO: %2d\n", numero);
        printf("===================\n\n");

        if(controllaNumero(cart1, numero) == FALSE) {
            if(controllaNumero(cart2, numero) == FALSE) {
                if(controllaNumero(cart3, numero) == FALSE) {
                    int scarto = controllaNumero(cart4, numero);
                }
            }
        }

        if(controllo == 2) {
            strcpy(intro, "Ambo: ");
        }
        else if(controllo == 3) {
            strcpy(intro, "Terni: ");
        }
        else if(controllo == 4) {
            strcpy(intro, "Quaterne: ");
        }
        else if(controllo == 5) {
            strcpy(intro, "Cinquine: ");
        }
        else if(controllo == 6) {
            strcpy(intro, "Tombola: ");
        }

        strcpy(output, "");
        strcpy(risultato, "");

        stampaCart(cart1, p1);
        stampaCart(cart2, p2);
        stampaCart(cart3, p3);
        stampaCart(cart4, p4);
        controlloVincita(cart1, &controllo, p1, cont1, output, &vincitore);
        controlloVincita(cart2, &controllo, p2, cont2, output, &vincitore);
        controlloVincita(cart3, &controllo, p3, cont3, output, &vincitore);
        controlloVincita(cart4, &controllo, p4, cont4, output, &vincitore);

        if(strcmp(output, "") != 0) {
            controllo++;
        }

        strcat(risultato, intro);
        strcat(risultato, output);

        printf("%s\n", risultato);
    } while(vincitore == FALSE);

    printf("\n\nGIOCO TERMINATO!\n\n");

    return 0;
}
void controlloVincita(int cart[], int* controllo, char p[], int cont[], char output[], int* vincitore) {
    int j = 0, aus = 0, k = 0, win = 0;

    for(int i = 0; i < 15; i++) {
        if(i % 5 == 0) {
            cont[j] = aus;
            j++;
            aus = 0;
        }
        if(cart[i] == 0) {
            aus++;
            win++;
        }
    }

    cont[j] = aus;

    while(cont[k] != *controllo && k < 3) {
        k++;
    }

    if(*controllo == 6 && win == 15) {
        *vincitore = TRUE;

        strcat(output, p);
        strcat(output, " ");
    }
    if(cont[k] == *controllo) {
        strcat(output, p);
        strcat(output, " ");
    }
}
int controllaNumero(int cart[], int numero) {
    int i = 0;

    while(cart[i] != numero && i < 15) {
        i++;
    }

    if(cart[i] == numero) {
        cart[i] = 0;

        return TRUE;
    }
    else {
        return FALSE;
    }
}
void stampaCart(int cart[], char p[]) {
    printf("Cartella di %s\n", p);

    for(int i = 0; i < 15; i++) {
        if(i % 5 == 0) {
            printf("\n");
        }

        printf("%2d  ", cart[i]);
    }

    printf("\n\n");
}
void generaCart(int cart1[], int cart2[], int cart3[], int cart4[], int v[]) {
    int aus;

    srand(time(NULL));

    for(int i = 0; i < 15; i++) {
        do {
            aus = rand() % 90 + 1;
        } while(v[aus - 1] == TRUE);

        v[aus - 1] = TRUE;
        cart1[i] = aus;
    }

    azzeraVett(v);

    for(int i = 0; i < 15; i++) {
        do {
            aus = rand() % 90 + 1;
        } while(v[aus - 1] == TRUE);

        v[aus - 1] = TRUE;
        cart2[i] = aus;
    }

    azzeraVett(v);

    for(int i = 0; i < 15; i++) {
        do {
            aus = rand() % 90 + 1;
        } while(v[aus - 1] == TRUE);

        v[aus - 1] = TRUE;
        cart3[i] = aus;
    }

    azzeraVett(v);

    for(int i = 0; i < 15; i++) {
        do {
            aus = rand() % 90 + 1;
        } while(v[aus - 1] == TRUE);

        v[aus - 1] = TRUE;
        cart4[i] = aus;
    }

    azzeraVett(v);
}
void azzeraVett(int v[]) {
    for(int i = 0; i < 90; i++) {
        v[i] = FALSE;
    }
}

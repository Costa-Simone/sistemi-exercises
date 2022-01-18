#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(void)
{
    int s, c = 0, i1, i2, l;

    printf("Inserisci il numero di bit: ");
    scanf("%d", &l);

    for(int i = 0; i <= l; i++)
    {
        do{
            printf("Inserisci il %d valore del primo numero: ", i + 1);
            scanf("%d", &i1);
        }while(i1 < 0 && i1 > 1);

        do{
            printf("\nInserisci il %d valore del secondo numero: ", i + 1);
            scanf("%d", &i2);
        }while(i2 < 0 && i2 > 1);

        s = i1 + i2 + c;

        if(s == 3)
        {
            s = 1;
            c = 1;
        }
        else if(s == 2)
        {
            s = 0;
            c = 1;
        }

        printf("\nIl primo valore del numero binario sommato e' %d\n", s);
    }

    return 0;
}

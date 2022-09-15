#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, aus = 1, cont = 1;

    do{
        printf("Inserire il valore di n: ");
        scanf("%d", &n);

        if(n < 1)
        {
            printf("\nErrore: il numero deve essere compreso tra 1 e 10\n\n");
        }
    }while(n < 1 || n > 10);

    /*printf("\n\nTabellina del %d:\n", n);

    for(int i = 1; i <= 10; i++)
    {
        printf("\n%d * %d\t =\t %d", n, i, n*i);
    }

    printf("\n");

    printf("\nTabellina completa:\n\n");

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            printf("%d\t", j*i);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            printf("%d\t", aus);
            aus++;
        }

        printf("\n");
    }*/

    cont = n - 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= cont; j++)
        {
            printf("\t");
        }
        cont--;
        for(int j = 1; j <= i; j++)
        {
            printf("%d\t\t", aus);
            aus++;
        }
        printf("\n");
    }

    return 0;
}

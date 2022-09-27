#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, posMin, aus;
    int *p, *p2;

    printf("Inserisci dimensione del vettore: ");
    scanf("%d", &n);
    srand(time(NULL));

    int v[n];

    p = v;

    for(int i = 0; i < n; i++) {
        *p = rand() % 100 + 1;

        printf("\nIl %d valore e': %d", i, *p);

        p++;
    }

    for(int i = 0; i <= n - 2; i++) {
        posMin = i;
        p = v + posMin;

        for(int j = i + 1; j <= n - 1; j++) {
            p2 = v + j;

            if(*p > *p2) {
                posMin = j;
                p = v + posMin;
            }

            p2++;
        }

        if(posMin != i) {
            p = v + i;
            aus = *p;
            p2 = v + posMin;
            *p = *p2;
            *p2 = aus;
        }
    }

    printf("\n\nIl vettore ordinato e':\n");
    p = v;

    for(int i = 0; i < n; i++) {
        printf("\nIl %d valore e': %d", i, *p);

        p++;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int n, v, freq[6];
    float perc;

    for(int i = 0; i < 6; i++)
    {
        freq[i] = 0;
    }

    printf("Inserire numero di lanci: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        v = (rand()%6);
        freq[v]++;
    }

    printf("\nNumero lanci: %d\n", n);
    printf("Faccia\tFreq\tPercentuale\n");
    printf("------\t----\t-----------\n");

    for(int i = 0; i < 6; i++)
    {
        perc = ((float)freq[i] / n) * 100;
        printf("%d\t%d\t%.4f%%\n", i + 1, freq[i], perc);
    }

    return 0;
}

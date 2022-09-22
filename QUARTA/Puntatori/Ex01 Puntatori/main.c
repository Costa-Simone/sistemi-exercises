#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 8;
    int *p;

    printf("Size(int): %d\nSize(float): %d\nSize(char): %d\n", sizeof(int), sizeof(float), sizeof(char));
    printf("\nSize(int*): %d\nSize(float*): %d\nSize(char*): %d\n", sizeof(int*), sizeof(float*), sizeof(char*));

    // Leggo indirizzo n
    printf("\nContenuto n: %d - Indirizzo n: %p\n", n, &n);
    // Leggo indirizzo p
    printf("\nContenuto p: %d - Indirizzo p: %p\n", p, &p);

    p = &n;

    printf("\nIndirizzo p dopo assegnazione a n: %p\n", p);
    // Stampo contenuto n
    printf("\nContenuto di n: (Classico) %d - (Puntatore) %d\n", n, *p);

    *p = 5; // n = 5

    printf("\nContenuto di n: (Classico) %d - (Puntatore) %d\n", n, *p);

    return 0;
}

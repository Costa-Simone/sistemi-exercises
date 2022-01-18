#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void caricaVett(int a[], float b[], int n);
void stampaVettInt(int v[], int n, char nome);
void stampaVettFloat(float v[], int n, char nome);

int main()
{
    int a[MAX];
    float b[MAX];
    int n;

    printf("Inserisci valori vuoi inserire (MAX 10): ");
    scanf("%d", &n);
    printf("\n");

    caricaVett(a, b, n);
    stampaVettInt(a, n, 'a');
    printf("\n");
    stampaVettFloat(b, n, 'b');

    return 0;
}

void caricaVett(int a[], float b[], int n) {
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        a[i] = (rand()%100) + 1;
        b[i] = sqrt(a[i]);
    }
}

void stampaVettInt(int v[], int n, char nome) {
    for(int i = 0; i < n; i++) {
        printf("%c[%d]: %d\n", nome, i, v[i]);
    }
}

void stampaVettFloat(float v[], int n, char nome) {
        for(int i = 0; i < n; i++) {
        printf("%c[%d]: %.2f\n", nome, i, v[i]);
    }
}

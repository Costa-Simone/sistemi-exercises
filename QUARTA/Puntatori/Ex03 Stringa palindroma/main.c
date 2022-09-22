#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int main()
{
    char s[MAX];
    int len;
    char *sI, *sF;

    printf("Inserisci nome: ");
    scanf("%s", s);

    len = strlen(s) - 1;

    sI = s;
    sF = s + len;

    while(sI < sF && *sI == *sF) {
        sI++;
        sF--;
    }

    if(sI >= sF) {
        printf("\nLa stringa e' palindroma");
    }
    else {
        printf("\nLa stringa non e' palindroma");
    }

    return 0;
}

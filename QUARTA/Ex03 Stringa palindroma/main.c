#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    char s[MAX];
    int len;

    printf("Inserisci la stringa: ");
    gets(s);

    len = strlen(s);

    return 0;
}

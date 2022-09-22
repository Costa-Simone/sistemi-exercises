#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[50], s2[50];
    char *p1, *p2;

    printf("Inserisci la stringa: ");
    gets(s1);

    p1 = s1;
    p2 = s2;

    while(*p1 != '\0') {
        *p2 = *p1;
        p1++;
        p2++;
    }

    *p2 = '\0';

    printf("\nLa stringa copiata e': %s\n", s2);

    return 0;
}

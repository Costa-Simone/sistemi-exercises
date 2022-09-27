#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[50], s2[50], output[100];
    int len1, len2, i = 0;
    char *p1, *p2;

    printf("Inserisci la prima stringa: ");
    gets(s1);
    printf("Inserisci la seconda stringa: ");
    gets(s2);
    strcpy(output, s1);

    len1 = strlen(output);
    len2 = strlen(s2);
    p1 = output + len1;
    p2 = s2;
    *p1 = ' ';
    p1++;

    while(i < len2) {
        *p1 = *p2;
        p1++;
        p2++;
        i++;
    }

    *p1 = '\0';

    printf("\nLe stringhe concatenate sono: %s\n", output);

    return 0;
}

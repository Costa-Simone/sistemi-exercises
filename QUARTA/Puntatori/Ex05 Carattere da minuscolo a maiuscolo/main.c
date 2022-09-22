#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50];
    char *p;

    printf("Inserisci la stringa: ");
    gets(s);

    p = s;

    while(*p != '\0') {
        if(*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
        else if(*p >= 'A' && *p <= 'Z') {
            *p += 32;
        }

        p++;
    }

    printf("\nLa stringa e': %s\n", s);

    return 0;
}

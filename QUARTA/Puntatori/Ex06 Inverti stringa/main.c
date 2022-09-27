#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[50];
    int len, i = 0;
    char *p1, *p2;

    printf("Inserisci la stringa: ");
    gets(s);

    len = strlen(s);
    p1 = s;
    p2 = s + len - 1;

    while(i < len / 2) {
        int aus = *p1;

        *p1 = *p2;
        *p2 = aus;

        p1++;
        p2--;
        i++;
    }

    printf("\nLa stringa invertita e': %s\n", s);

    return 0;
}

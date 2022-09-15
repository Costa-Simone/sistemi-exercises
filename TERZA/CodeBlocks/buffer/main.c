#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    char carattere1, carattere2;

    printf("Inserisci numero: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("\n%d\n", num1 + num2);
    fflush(stdin);

    printf("Inserisci carattere: ");
    scanf("%c", &carattere1);
    scanf("%c", &carattere2);

    printf("\n%c_%c_", carattere1, carattere2);

    return 0;
}

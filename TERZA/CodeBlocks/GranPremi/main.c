#include <stdio.h>
#include <stdlib.h>

#define MAX 101

void splitRiga(char r[MAX], char campo[4][MAX], char sep);

int main()
{
    FILE* fp;
    char riga[MAX], aus[MAX];
    char campi[4][MAX];

    fp = fopen("granpremi.csv", "r");

    printf("N.\t\t\tGran Premio\t\tMetri\tLaps\n");
    printf("-------------------------------------------------------------\n");

    do {
        fgets(riga, MAX, fp);
        splitRiga(riga, campi, ';');

        for(int i = 0; i < 4; i++) {
            printf("%s    ", campi[i]);
        }
    } while(!feof(fp));

    return 0;
}

void splitRiga(char r[MAX], char campo[4][MAX], char sep) {
    int i = 0, j = 0, k;

    do {
        k = 0;

        do {
            campo[j][k++] = r[i++];
        } while((r[i] != sep) && (r[i] != '\0'));

        campo[j][k] = '\0';

        if(r[i] != '\0') {
            i++;
            j++;
        }
    } while(r[i] != '\0');
}

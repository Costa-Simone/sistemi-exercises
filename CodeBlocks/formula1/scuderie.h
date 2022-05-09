#ifndef SCUDERIE_H_INCLUDED
#define SCUDERIE_H_INCLUDED

#include "piloti.h"

#define LEN_SCUDERIA 30
#define LEN_MONOPOSTO 20
#define LEN_NOME 20

void azzeraDatoScuderia(char dato[]);

typedef struct scuderia{
    int idScuderia;
    char nome[LEN_SCUDERIA];
    char monoposto[LEN_MONOPOSTO];
    float rating;
    int totPunti;
} Scuderie;

int caricaScuderieDaFile(char file_name[], Scuderie s[]){
    FILE* fp;
    char row_file[BUFFER], spl[BUFFER];
    int cnt = 0;
    int i = 0; // Variabile per lo split
    int j = 0;
    char dato[LEN_NOME]; // Array char per lo split

    fp = fopen(file_name, "r");

    if (fp != NULL) {
        while(!feof(fp)) {
            //fscanf(fp, "%s", row_file);
            fgets(row_file, BUFFER, fp);
            printf("%s\n", row_file);
            /* row_file => 1;Mercedes AMG Petronas;W13;96.5;0 */
            // idScuderia
            splittaString(row_file, spl, 0, ';');
            s[cnt].idScuderia = atoi(spl);
            // nome
            splittaString(row_file, spl, 1, ';');
            strcpy(s[cnt].nome, spl);
            // monoposto
            splittaString(row_file, spl, 2, ';');
            strcpy(s[cnt].monoposto, spl);
            //rating
            splittaString(row_file, spl, 3, ';');
            s[cnt].rating = atoi(spl);
            // totPunti
            splittaString(row_file, spl, 4, ';');
            s[cnt].totPunti = atof(spl);

            cnt++;
        }
    }
    else printf("Impossibile aprire il file...\n");

    fclose(fp);

    return cnt;
 }
void elencoScuderie(Scuderie s[], int len) {
    printf("STAMPA ELENCO SCUDERIE\n");
    printf("ID\tRATING\t\tTOTPUNTI\tMONOPOSTO\tNOME\n");

    for(int i = 0; i < len; i++) printf("%d\t%f\t%d\t\t%s\t\t%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
}

#endif // SCUDERIE_H_INCLUDED

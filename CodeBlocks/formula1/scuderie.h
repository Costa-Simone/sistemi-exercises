#ifndef SCUDERIE_H_INCLUDED
#define SCUDERIE_H_INCLUDED

#define LEN_SCUDERIA 30
#define LEN_MONOPOSTO 20

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
            strcpy(spl, splittaString(row_file, 0, ';'));
            s[cnt].idScuderia = atoi(spl);
            // nome
            strcpy(spl, splittaString(row_file, 1, ';'));
            strcpy(s[cnt].nome, spl);
            // monoposto
            strcpy(spl, splittaString(row_file, 2, ';'));
            strcpy(s[cnt].monoposto, spl);
            //rating
            strcpy(spl, splittaString(row_file, 3, ';'));
            s[cnt].rating = atoi(spl);
            // totPunti
            strcpy(spl, splittaString(row_file, 4, ';'));
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
    printf("ID\tRATING\tTOTPUNTI\tMONOPOSTO\tNOME\n");

    for(int i = 0; i < len; i++) printf("%d\t%f\t%d\t%s\t%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
}

#endif // SCUDERIE_H_INCLUDED

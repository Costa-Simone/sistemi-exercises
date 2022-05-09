#ifndef GRANPREMI_H_INCLUDED
#define GRANPREMI_H_INCLUDED

#define LEN_GP 30

void azzeraDatoGranPremio(char dato[]);

typedef struct granpremio{
    int idGP;
    char nome[LEN_GP];
    int lung;
    int nGiri;
} Granpremi;

int punteggi[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int caricaGranPremiDaFile(char file_name[], Granpremi gp[]){
    FILE* fp;
    char row_file[BUFFER], spl[BUFFER];
    int cnt = 0;
    int i = 0; // Variabile per lo split
    int j = 0;
    char dato[LEN_NOME]; // Array char per lo split

    fp = fopen(file_name, "r");

    if (fp != NULL)
    {
        while(!feof(fp))
        {
            //fscanf(fp, "%s", row_file);
            fgets(row_file, BUFFER, fp);

            /* row_file => 1;Gran Premio di Bahrain;5412;57 */

            // idGP
            splittaString(row_file, spl, 0, ';');
            gp[cnt].idGP = atoi(spl);
            // nome
            splittaString(row_file, spl, 1, ';');
            strcpy(gp[cnt].nome, spl);
            // lung
            splittaString(row_file, spl, 2, ';');
            gp[cnt].lung = atoi(spl);
            // nGiri
            splittaString(row_file, spl, 3, ';');
            gp[cnt].nGiri = atoi(spl);

            cnt++;
        }
    }
    else printf("Impossibile aprire il file...\n");

    fclose(fp);

    return cnt;
}
void elencoGP(Granpremi gp[], int len) {
    printf("STAMPA ELENCO GRAN PREMI\n");
    printf("ID\tLUNG\tGIRI\tNOME\n");

    for(int i = 0; i < len; i++) printf("%d\t%d\t%d\t%s\n", gp[i].idGP, gp[i].lung, gp[i].nGiri, gp[i].nome);
}

#endif // GRANPREMI_H_INCLUDED

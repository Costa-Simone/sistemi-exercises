#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED

#define LEN_NOME 20
#define BUFFER 100

#define TRUE 1
#define FALSE 0

void azzeraDatoPilota(char dato[]);

typedef int bool;

typedef struct pilota{
    int idPilota;
    char nome[LEN_NOME];
    int codScuderia;
    int totGare;
    int punti;
} Piloti; //per dichiarare variabili

 int caricaPilotiDaFile(char file_name[], Piloti p[]) {
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
            /* row_file => 1;Hammilton L.;1;0;0 */
            // idPilota
            strcpy(spl, splittaString(row_file, 0, ';'));
            p[cnt].idPilota = atoi(spl);
            //NOME
            strcpy(spl, splittaString(row_file, 1, ';'));
            strcpy(p[cnt].nome, spl);
            //CODICE SCUDERIA
            strcpy(spl, splittaString(row_file, 2, ';'));
            p[cnt].codScuderia = atoi(spl);
            //TOTALE GARE
            strcpy(spl, splittaString(row_file, 3, ';'));
            p[cnt].totGare = atoi(spl);
            //PUNTI
            strcpy(spl, splittaString(row_file, 4, ';'));
            p[cnt].punti = atoi(spl);

            cnt++;
        }
    }
    else printf("Impossibile aprire il file...\n");

    fclose(fp);

    return cnt;
 }
void elencoPiloti(Piloti pil[], int  len_pil, int len_scud) {

}

#endif // PILOTI_H_INCLUDED

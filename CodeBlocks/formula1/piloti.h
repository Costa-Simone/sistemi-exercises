#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED

#define LEN_NOME 20
#define BUFFER 100

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct pilota{
    int idPilota;
    char nome[LEN_NOME];
    int codScuderia;
    int totGare;
    int punti;
} Piloti;

int caricaPilotiDaFile(char file_name[], Piloti p[]){
    FILE* fp;
    char row_file[BUFFER];
    char spl[BUFFER];
    int cnt = 0;

    fp = fopen(file_name, "r");
    if (fp != NULL)
    {
        while(!feof(fp))
        {
            fgets(row_file, BUFFER, fp);

            /** row_file => 1;Hammilton L.;1;0;0 **/

            ///ID PILOTA
            splittaString(row_file, spl, 0, ';');
            p[cnt].idPilota = atoi(spl);

            ///NOME
            splittaString(row_file, spl, 1, ';');
            strcpy(p[cnt].nome, spl);

            ///CODICE SCUDERIA
            splittaString(row_file, spl, 2, ';');
            p[cnt].codScuderia = atoi(spl);

            ///TOTALE GARE
            splittaString(row_file, spl, 3, ';');
            p[cnt].totGare = atoi(spl);

            ///PUNTI
            splittaString(row_file, spl, 4, '\0');
            p[cnt].punti = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
    return cnt;
 }

void elencoPiloti(Piloti p[], int len_pil, Scuderie s[], int len_scud){
     int i;
     char scud[BUFFER];

     printf("ID\tGARE\tPUNTI\tNOME\t\t\tSCUDERIA\n");
     for(i = 0; i < len_pil; i++)
     {
         getNomeScudByID(s, len_scud, p[i].codScuderia, scud);
         printf("%d\t%d\t%d\t%s\t\t\t%s\n", p[i].idPilota, p[i].totGare, p[i].punti, p[i].nome, scud);
     }
}

void mostraClassificaPiloti(Piloti p[], int len_pil, Scuderie s[], int len_scud){
     ordinaPilotiPunti(p, len_pil);
     elencoPiloti(p, len_pil, s, len_scud);
}

void ordinaPilotiPunti(Piloti p[], int len_pil){
     int posmin;
     Piloti aus;

     for(int i = 0; i <= len_pil - 2; i++)
     {
         posmin = i;
         for(int j = i + 1; j <= len_pil - 1; j++)
         {
             if(p[posmin].punti < p[j].punti)
                posmin = j;
         }
         if(posmin != i)
         {
             aus = p[i];
             p[i] = p[posmin];
             p[posmin] = aus;
         }
     }
}

void stampaSuFilePiloti(Piloti p[], int len_pil){
    FILE* fp;

    fp = fopen("File/Classifica Piloti.csv", "w");
    if (fp != NULL)
    {
        fprintf(fp, "CLASSIFICA PILOTI\n");
        for(int i = 0; i < len_pil; i++)
        {
            fprintf(fp, "%d;%d;%d;%s\n", p[i].idPilota, p[i].totGare, p[i].punti, p[i].nome);
        }
        printf("\nStampa completata");
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
}

#endif /// PILOTI_H_INCLUDED

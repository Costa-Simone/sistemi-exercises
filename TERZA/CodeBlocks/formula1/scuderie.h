#ifndef SCUDERIE_H_INCLUDED
#define SCUDERIE_H_INCLUDED

#define LEN_SCUDERIA 30
#define LEN_MONOPOSTO 20
#define LEN_NOME 20
#define BUFFER 100
#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct scuderia{
    int idScuderia;
    char nome[LEN_SCUDERIA];
    char monoposto[LEN_MONOPOSTO];
    float rating;
    int totPunti;
} Scuderie;

int caricaScuderieDaFile(char file_name[], Scuderie s[]){
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

            /** row_file => 1;Mercedes AMG Petronas;W13;96.5;0 **/

            ///ID SCUDERIA
            splittaString(row_file, spl, 0, ';');
            s[cnt].idScuderia = atoi(spl);

            ///NOME
            splittaString(row_file, spl, 1, ';');
            strcpy(s[cnt].nome, spl);

            ///MONOPOSTO
            splittaString(row_file, spl, 2, ';');
            strcpy(s[cnt].monoposto, spl);

            ///RATING
            splittaString(row_file, spl, 3, ';');
            s[cnt].rating = atof(spl);

            ///TOTALE PUNTI
            splittaString(row_file, spl, 4, '\0');
            s[cnt].totPunti = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
    return cnt;
 }

void elencoScuderie(Scuderie s[], int len){
     int i;

     printf("ID\tRATING\tPUNTI\tMONOPOSTO\tNOME\n");
     for(i = 0; i < len; i++)
     {
         printf("%d\t%.1f\t%d\t%s\t\t%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
     }
}

void getNomeScudByID(Scuderie s[], int len_scud, int codScud, char ret[]){
    int i = 0;

    while(i < len_scud && s[i].idScuderia != codScud)
        i++;
    if(i < len_scud)
        strcpy(ret, s[i].nome);
    else
        strcpy(ret, "Non trovato");
}

int getPosScudByID(int codScud, Scuderie s[], int len_scud){
    int i = 0;

    while(s[i].idScuderia != codScud)
        i++;
    return i;
}

void mostraClassificaScuderie(Scuderie s[], int len_scud){
     char risposta = "";

     ordinaScuderiePunti(s, len_scud);
     printf("---------- STAMPA CLASSIFICA SCUDERIE ----------\n\n");
     printf("ID\tRATING\tPUNTI\tMONOPOSTO\tNOME\n");
     for(int i = 0; i < len_scud; i++)
     {
         printf("%d\t%.1f\t%d\t%s\t\t%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
     }
     printf("\nDesideri stampa su File?:[y/n] ");
     scanf("%c", &risposta);
     if(risposta == 'y')
        stampaSuFileScuderie(s, len_scud);
}

void ordinaScuderiePunti(Scuderie s[], int len_scud){
     int posmin;
     Scuderie aus;

     for(int i = 0; i <= len_scud - 2; i++)
     {
         posmin = i;
         for(int j = i + 1; j <= len_scud - 1; j++)
         {
             if(s[posmin].totPunti < s[j].totPunti)
                posmin = j;
         }
         if(posmin != i)
         {
             aus = s[i];
             s[i] = s[posmin];
             s[posmin] = aus;
         }
     }
}

void stampaSuFileScuderie(Scuderie s[], int len_scud){
    FILE* fp;

    fp = fopen("File/Classifica Scuderie.csv", "w");
    if (fp != NULL)
    {
        for(int i = 0; i < len_scud; i++)
        {
            fprintf(fp,"%d;%.1f;%d;%s;%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
        }
        printf("\nStampa completata");
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
}

#endif /// SCUDERIE_H_INCLUDED

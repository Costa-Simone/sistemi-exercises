#ifndef GRANPREMI_H_INCLUDED
#define GRANPREMI_H_INCLUDED

#define LEN_GP 30
#define LEN_NOME 20
#define BUFFER 100
#define MAX_PIL_GARA 15
#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct granpremio{
    int idGP;
    char nome[LEN_GP];
    int lung;
    int nGiri;
} Granpremi;

int punteggi[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int caricaGranPremiDaFile(char file_name[], Granpremi gp[]){
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

            /** row_file => 1;Gran Premio di Bahrain;5412;57 **/

            ///ID GRAN PREMIO
            splittaString(row_file, spl, 0, ';');
            gp[cnt].idGP = atoi(spl);

            ///NOME
            splittaString(row_file, spl, 1, ';');
            strcpy(gp[cnt].nome, spl);

            ///LUNGHEZZA
            splittaString(row_file, spl, 2, ';');
            gp[cnt].lung = atoi(spl);

            ///NUMERO GIRI
            splittaString(row_file, spl, 3, '\0');
            gp[cnt].nGiri = atoi(spl);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
    return cnt;
 }

void elencoGP(Granpremi gp[], int len){
     int i;

     printf("ID\tLUNG\tGIRI\tNOME\n");
     for(i = 0; i < len; i++)
     {
         printf("%d\t%d\t%d\t%s\n", gp[i].idGP, gp[i].lung, gp[i].nGiri, gp[i].nome);
     }
}

void generaGPSingolo(Piloti p[], int len_pil, Scuderie s[], int len_scud, Granpremi gp[], int len_gp){
    int idGP, idPil;
    int vPil[MAX_PIL_GARA] = {0};   ///Azzero array
    int i, j;
    bool trovato;
    srand(time(NULL));

    printf("---------- GENERA GRAN PREMIO SINGOLO ----------\n\n");

    ///1. RICERCA E STAMPA GRAN PREMIO
    idGP = rand() % len_gp;
    printf("VIA AL: %s\n\n", gp[idGP].nome);

    ///2. SOLO MAX_PIL_GARA POSSONO PARTECIPARE
    for(i = 0; i < MAX_PIL_GARA; i++)
    {
        do
        {
            idPil = rand() % len_pil;
            trovato = FALSE;
            j = 0;
            ///Inizio ricerca idPil in vPil
            while(j < MAX_PIL_GARA && vPil[j] != idPil)
                j++;
            if(j < MAX_PIL_GARA)
                trovato = TRUE;
            else
            {
                ///Pilota non trovato
                vPil[i] = idPil;
                p[idPil].totGare ++;
                if(i < 10)
                {
                    p[idPil].punti += punteggi[i];
                    s[getPosScudByID(p[idPil].codScuderia, s, len_scud)].totPunti += punteggi[i];
                }
                printf("%d - %s - %d\n", (i + 1), p[idPil].nome, p[idPil].punti);
            }
        }
        while(trovato == TRUE);
    }
}

void generaTuttiGP(Piloti p[], int len_pil, Scuderie s[], int len_scud, Granpremi gp[], int len_gp){
    int idPil;
    int vPil[MAX_PIL_GARA] = {0};   ///Azzero array
    int i, j, k;
    bool trovato;
    srand(time(NULL));

    printf("---------- GENERA TUTTI I GRAN PREMI ----------\n\n");

    for(k = 0; k < len_gp; k++)
    {
        printf("VIA AL: %s\n\n", gp[k].nome);
        for(i = 0; i < MAX_PIL_GARA; i++)
        {
            do
            {
                idPil = rand() % len_pil;
                trovato = FALSE;
                j = 0;
                ///Inizio ricerca idPil in vPil
                while(j < MAX_PIL_GARA && vPil[j] != idPil)
                    j++;
                if(j < MAX_PIL_GARA)
                    trovato = TRUE;
                else
                {
                    ///Pilota non trovato
                    vPil[i] = idPil;
                    p[idPil].totGare ++;
                    if(i < 10)
                    {
                        p[idPil].punti += punteggi[i];
                        s[getPosScudByID(p[idPil].codScuderia, s, len_scud)].totPunti += punteggi[i];
                    }
                    printf("%d - %s - %d\n", (i + 1), p[idPil].nome, p[idPil].punti);
                }
            }
            while(trovato == TRUE);
        }
        printf("\n\n");
        for(i = 0; i < MAX_PIL_GARA; i++)
            vPil[i] = 0;
        //stampaSuFileGP(p, len_pil, gp[k].nome);
    }
}
/*
void stampaSuFileGP(Piloti p[], int len_pil, Scuderie s[], int len_scud, Granpremi gp[], int len_gp){
    FILE* fp;

    fp = fopen("File/" + nomeGP + ".csv", "w");
    if (fp != NULL)
    {
        for(int i = 0; i < len_gp; i++)
        {
            fprintf(fp,"%d;%.1f;%d;%s;%s\n", s[i].idScuderia, s[i].rating, s[i].totPunti, s[i].monoposto, s[i].nome);
        }
        printf("\nStampa completata");
    }
    else
        printf("Impossibile aprire il file...\n");
    fclose(fp);
}
*/
#endif /// GRANPREMI_H_INCLUDED

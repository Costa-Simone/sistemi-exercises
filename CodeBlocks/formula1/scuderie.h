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
    char row_file[BUFFER];
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

            /* row_file => 1;Mercedes AMG Petronas;W13;96.5;0 */

            //ID SCUDERIA
            i = 0;
            while(row_file[i] != ';')
            {
                dato[i] = row_file[i];
                i++;
            }
            j = i + 1;
            dato[i] = '\0';
            s[cnt].idScuderia = atoi(dato);   //Converte da CHAR a INT
            printf("%d  ", s[cnt].idScuderia);

            //NOME
            azzeraDatoScuderia(dato);
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            strcpy(s[cnt].nome, dato);
            printf("%s  ", s[cnt].nome);

            //MONOPOSTO
            azzeraDatoScuderia(dato);
            j++;
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            strcpy(s[cnt].monoposto, dato);
            printf("%s  ", s[cnt].monoposto);

            //RATING
            azzeraDatoScuderia(dato);
            j++;
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            s[cnt].rating = atof(dato);
            printf("%.1f  ", s[cnt].rating);

            //TOTALE PUNTI
            azzeraDatoScuderia(dato);
            j++;
            i = 0;
            while(row_file[j] != '\0')
            {
                dato[i++] = row_file[j++];
            }
            s[cnt].totPunti = atoi(dato);
            printf("%d\n", s[cnt].totPunti);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");

    fclose(fp);
    return cnt;
 }

 void azzeraDatoScuderia(char dato[]){
     int i = 0;
     while(dato[i] != '\0')
     {
         dato[i++] = 0;
     }
 }

#endif // SCUDERIE_H_INCLUDED

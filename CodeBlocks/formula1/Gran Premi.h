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

            /* row_file => 1;Gran Premio di Bahrain;5412;57 */

            //ID GRAN PREMIO
            i = 0;
            while(row_file[i] != ';')
            {
                dato[i] = row_file[i];
                i++;
            }
            j = i + 1;
            dato[i] = '\0';
            gp[cnt].idGP = atoi(dato);
            printf("%d  ", gp[cnt].idGP);

            //NOME
            azzeraDatoGranPremio(dato);
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            strcpy(gp[cnt].nome, dato);
            printf("%s  ", gp[cnt].nome);

            //LUNGHEZZA
            azzeraDatoGranPremio(dato);
            j++;
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            gp[cnt].lung = atoi(dato);
            printf("%d  ", gp[cnt].lung);

            //NUMERO GIRI
            azzeraDatoGranPremio(dato);
            j++;
            i = 0;
            while(row_file[j] != '\0')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            gp[cnt].nGiri = atoi(dato);
            printf("%d\n", gp[cnt].nGiri);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");

    fclose(fp);
    return cnt;
 }

 void azzeraDatoGranPremio(char dato[]){
     int i = 0;
     while(dato[i] != '\0')
     {
         dato[i++] = 0;
     }
 }

#endif // GRANPREMI_H_INCLUDED

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
} Piloti;

 int caricaPilotiDaFile(char file_name[], Piloti p[]){
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

            /* row_file => 1;Hammilton L.;1;0;0 */

            //ID PILOTA
            i = 0;
            while(row_file[i] != ';')
            {
                dato[i] = row_file[i];
                i++;
            }
            j = i + 1;
            dato[i] = '\0';
            p[cnt].idPilota = atoi(dato);   //Converte da CHAR a INT
            printf("%d  ", p[cnt].idPilota);

            //NOME
            azzeraDatoPilota(dato);
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            strcpy(p[cnt].nome, dato);
            printf("%s  ", p[cnt].nome);

            //CODICE SCUDERIA
            azzeraDatoPilota(dato);
            j++;
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            p[cnt].codScuderia = atoi(dato);
            printf("%d  ", p[cnt].codScuderia);

            //TOTALE GARE
            azzeraDatoPilota(dato);
            j++;
            i = 0;
            while(row_file[j] != ';')
            {
                dato[i++] = row_file[j++];
            }
            dato[i] = '\0';
            p[cnt].totGare = atoi(dato);
            printf("%d  ", p[cnt].totGare);

            //PUNTI
            azzeraDatoPilota(dato);
            j++;
            i = 0;
            while(row_file[j] != '\0')
            {
                dato[i++] = row_file[j++];
            }
            p[cnt].punti = atoi(dato);
            printf("%d\n", p[cnt].punti);

            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file...\n");

    fclose(fp);
    return cnt;
 }

 void azzeraDatoPilota(char dato[]){
     int i = 0;
     while(dato[i] != '\0')
     {
         dato[i++] = 0;
     }
 }

#endif // PILOTI_H_INCLUDED

#ifndef PILOTI_H_INCLUDED
#define PILOTI_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define LEN_NOME 20
#define BUFFER 100

typedef int bool;

typedef struct pilota{
    int idPilota;
    char nome[LEN_NOME];
    int codScuderia;
    int totGare;
    int punti;
} Piloti;

int caricaPilotiDaFile(char file_name[], Piloti p[]){
    FILE *fp;
    char row_file[BUFFER];
    int cnt=0;
    int i=0; //indice per lo split
    char dato[LEN_NOME]; //Array char per lo split

    fp=fopen(file_name, "r");
    if(fp!= NULL){
        while(!feof(fp))
        {
            //fscanf(fp, "%s", row_file);
            fgets(row_file, BUFFER, fp);
            printf("%s\n",row_file);
            /////////////////////////
            while(row_file[i] != ';'){
                dato[i]=row_file[i];
                i++;
            }
            dato[i]='\0';
            p[cnt].idPilota=atoi(dato); //convert to int della stringa
            printf("%d\n",p[cnt].idPilota);
            cnt++;
        }
    }
    else
        printf("Impossibile aprire il file....\n");

    fclose(fp);
    return cnt;
}


#endif // PILOTI_H_INCLUDED

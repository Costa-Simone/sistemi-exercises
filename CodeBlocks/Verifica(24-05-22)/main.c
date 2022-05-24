#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100

typedef struct pilota {
    int idPil;
    char nome[BUFFER];
    char nazionalita[3];
    int punti;
    int idTeam;
} Piloti;

typedef struct team {
    int idTeam;
    char nome[BUFFER];
    char motore[BUFFER];
} Team;

int menu();
int CaricaPilDaFile(char nf[], Piloti pil[]);
int CaricaTemDaFile(char nf[], Team tem[]);
void splittaString(char row[], char spl[], int pos, char separatore);
void stampaElencoPiloti(Piloti pil[], Team tem[], int nPiloti, int nTeam);
void elencoPilotiNazInput(char naz[], Piloti pil[], int nPiloti, Team tem[], int nTeam);
void ordinaPilNaz(Piloti pil[], int nPiloti);
void cercaTeam(char squ[], int id, Team tem[], int nTeam);
void ex03(char nf[], int input, Piloti pil[], int nPiloti, Team tem[], int nTeam);
void ordinaPiloti(Piloti pil[], int nPiloti);
void cercaMigliorPilota(char nf[], Piloti pil[], int nPiloti, Team tem[], int nTeam);

int main()
{
    int scelta;
    Piloti pil[BUFFER];
    Team tem[BUFFER];
    int nPiloti, nTeam;
    char naz[3];
    int input;

    nPiloti = CaricaPilDaFile("piloti.csv", pil);
    nTeam = CaricaTemDaFile("team.csv", tem);

    do {
        scelta = menu();

        fflush(stdin);
        system("@cls||clear");

        switch(scelta) {
        case 1: // Elenco piloti
            stampaElencoPiloti(pil, tem, nPiloti, nTeam);
            break;
        case 2: // Piloti nazione in input
            printf("Inserisci la nazionalita' dei piloti: ");
            gets(naz);

            elencoPilotiNazInput(naz, pil, nPiloti, tem, nTeam);
            break;
        case 3: // Visualizzare piloti piu punti di quelli in input
            printf("Inserisci i punti: ");
            scanf("%d", &input);

            ex03("esercizio_3.txt", input, pil, nPiloti, tem, nTeam);
            break;
        case 4: // Cercare miglior pilota e metterlo in file
            cercaMigliorPilota("migliore.txt", pil, nPiloti, tem, nTeam);
            break;
        default:
            break;
        }

        fflush(stdin);
        getchar();
        system("@cls||clear");
    } while(scelta != 0);

    printf("Programma terminato");

    return 0;
}

void cercaMigliorPilota(char nf[], Piloti pil[], int nPiloti, Team tem[], int nTeam) {
    ordinaPiloti(pil, nPiloti);
    FILE* fp;
    char squ[BUFFER];

    fp = fopen(nf, "w");

    cercaTeam(squ, pil[0].idTeam, tem, nTeam);

    fprintf(fp, "%d, %s, %s, %s, %d", pil[0].idPil, pil[0].nome, squ, pil[0].nazionalita, pil[0].punti);
    printf("Stampa effettuata");

    fclose(fp);
}
void ex03(char nf[], int input, Piloti pil[], int nPiloti, Team tem[], int nTeam) {
    ordinaPiloti(pil, nPiloti);
    FILE* fp;
    int i = 0;

    fp = fopen(nf, "w");

    while(pil[i].punti >= input) {
        if(pil[i].punti >= input) {
            char squ[BUFFER];

            cercaTeam(squ, pil[i].idTeam, tem, nTeam);

            printf("%d, %s, %s, %s, %d\n", pil[i].idPil, pil[i].nome, squ, pil[i].nazionalita, pil[i].punti);
            fprintf(fp, "%d, %s, %s, %s, %d\n", pil[i].idPil, pil[i].nome, squ, pil[i].nazionalita, pil[i].punti);
        }

        i++;
    }

    fclose(fp);
}
void ordinaPiloti(Piloti pil[], int nPiloti) {
    int posmin;

    for(int i = 0; i <= nPiloti - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nPiloti - 1; j++) {
            if(pil[posmin].punti < pil[j].punti) {
                posmin = j;
            }
        }
        if(posmin != i) {
            Piloti aus = pil[i];
            pil[i] = pil[posmin];
            pil[posmin] = aus;
        }
    }
}
void cercaTeam(char squ[], int id, Team tem[], int nTeam) {
    int j = 0;

    while(id != tem[j].idTeam && j < nTeam) {
        j++;
    }

    strcpy(squ, tem[j].nome);
}
void elencoPilotiNazInput(char naz[], Piloti pil[], int nPiloti, Team tem[], int nTeam) {
    int i = 0;

    ordinaPilNaz(pil, nPiloti);

    while(strcmp(pil[i].nazionalita, naz) <= 0 && i < nPiloti) {
        if(strcmp(pil[i].nazionalita, naz) == 0) {
            char squ[BUFFER];

            cercaTeam(squ, pil[i].idTeam, tem, nTeam);

            printf("%d, %s, %s, %d, %s\n", pil[i].idPil, pil[i].nome, pil[i].nazionalita, pil[i].punti, squ);
        }

        i++;
    }
}
void stampaElencoPiloti(Piloti pil[], Team tem[], int nPiloti, int nTeam) {
    for(int i = 0; i < nPiloti; i++) {
        char squ[BUFFER];
        cercaTeam(squ, pil[i].idTeam, tem, nTeam);

        printf("%d, %s, %s, %d, %s\n", pil[i].idPil, pil[i].nome, pil[i].nazionalita, pil[i].punti, squ);
    }
}
int CaricaTemDaFile(char nf[], Team tem[]) {
    char spl[BUFFER];
    char row[BUFFER];
    FILE* fp;
    int cont = 0;

    fp = fopen(nf, "r");

    if(fp != NULL) {
        while(!feof(fp)) {
            fgets(row, BUFFER, fp);

            splittaString(row, spl, 0, ';');
            tem[cont].idTeam = atoi(spl);

            splittaString(row, spl, 1, ';');
            strcpy(tem[cont].nome, spl);

            splittaString(row, spl, 2, ';');
            strcpy(tem[cont].motore, spl);

            cont++;
        }
    }
    else {
        printf("File non trovato!");
    }

    fclose(fp);

    return cont;
}
int CaricaPilDaFile(char nf[], Piloti pil[]) {
    char spl[BUFFER];
    char row[BUFFER];
    FILE* fp;
    int cont = 0;

    fp = fopen(nf, "r");

    if(fp != NULL) {
        while(!feof(fp)) {
            fgets(row, BUFFER, fp);

            splittaString(row, spl, 0, ';');
            pil[cont].idPil = atoi(spl);

            splittaString(row, spl, 1, ';');
            strcpy(pil[cont].nome, spl);

            splittaString(row, spl, 2, ';');
            strcpy(pil[cont].nazionalita, spl);

            splittaString(row, spl, 3, ';');
            pil[cont].punti = atoi(spl);

            splittaString(row, spl, 4, ';');
            pil[cont].idTeam = atoi(spl);

            cont++;
        }
    }
    else {
        printf("File non trovato!");
    }

    fclose(fp);

    return cont;
}
int menu() {
    printf("1. Elenco piloti\n");
    printf("2. Piloti nazione in input\n");
    printf("3. Visualizzare piloti piu punti di quelli in input\n");
    printf("4. Cercare miglior pilota e metterlo in file\n");

    int sc;

    printf("--> ");
    scanf("%d", &sc);

    return sc;
}
void splittaString(char row[], char spl[], int pos, char separatore){
    int cnt = 0;
    int i = 0;

    while(cnt != pos)
    {
        while(row[i] != separatore)
            i++;
        cnt++;
        i++;
    }
    cnt = 0;
    while(row[i] != separatore && row[i] != '\0'){
        spl[cnt] = row[i];
        i++;
        cnt++;
    }
    spl[cnt] = '\0';
}
void ordinaPilNaz(Piloti pil[], int nPiloti) {
    int posmin;

    for(int i = 0; i <= nPiloti - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nPiloti - 1; j++) {
            if(strcmp(pil[posmin].nazionalita, pil[j].nazionalita) > 0) {
                posmin = j;
            }
        }
        if(posmin != i) {
            Piloti aus = pil[i];
            pil[i] = pil[posmin];
            pil[posmin] = aus;
        }
    }
}


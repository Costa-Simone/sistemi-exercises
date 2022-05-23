#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100
#define MAX_DATI 50

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
int caricaPilotiDaFile(char nf[], Piloti pil[]);
void stampaPiloti(Piloti pil[], Team tem[], int nPiloti);
int caricaTeamDaFIle(char nf[], Team tem[]);
void elencoPilotiNaz(Piloti pil[], Team tem[], char naz[], int nPiloti);
void ordinaPilotiNaz(Piloti pil[], int nPiloti);
void ordinaPilotiId(Piloti pil[], int nPiloti);
void creaFileTeam(Piloti pil[], Team tem[], int nTeam, int nPiloti);
void ordinaTeamNome(Team tem[], int nTeam);
void ordinaPilotiTeam(Piloti pil[], int nPiloti);
void splittaString(char row[], char spl[], int pos, char separatore);
void elencoPeggioriPiloti(Piloti pil[], Team tem[], int nPiloti, int nTeam);
void ordinaPilotiMenoPunti(Piloti pil[], int nPiloti);

int main()
{
    int scelta;
    Piloti pil[MAX_DATI];
    Team tem[MAX_DATI];
    int nPiloti, nTeam;
    char naz[BUFFER];

    nPiloti = caricaPilotiDaFile("piloti.txt", pil);
    nTeam = caricaTeamDaFIle("team.txt", tem);

    do {
        scelta = menu();

        fflush(stdin);
        system("@cls||clear");

        switch(scelta) {
        case 1: // Elenco Piloti
            stampaPiloti(pil, tem, nPiloti);
            break;

        case 2: // Elenco piloti nazione in input

            printf("Inserisci la nazione: ");
            gets(naz);

            elencoPilotiNaz(pil, tem, naz, nPiloti);
            break;

        case 3: // Elenco peggiori piloti
            elencoPeggioriPiloti(pil, tem, nPiloti, nTeam);
            break;

        case 4: // Crea file team
            creaFileTeam(pil, tem, nTeam, nPiloti);
            break;

        default:
            break;
        }

        fflush(stdin);
        getchar();
        system("@cls||clear");
    } while(scelta != 0);

    printf("Programma terminato...\n");
    return 0;
}

void elencoPeggioriPiloti(Piloti pil[], Team tem[], int nPiloti, int nTeam) {
    ordinaPilotiMenoPunti(pil, nPiloti);

    FILE* fp;

    fp = fopen("peggiori.txt", "w");

    for(int i = 0; i < 3; i++) {
        int j = 0;

        while(tem[j].idTeam != pil[i].idTeam) {
            j++;
        }

        fprintf(fp, "%s;%s;%s;%d\n", pil[i].nome, tem[j].nome, pil[i].nazionalita, pil[i].punti);
    }

    fclose(fp);
}
void ordinaPilotiMenoPunti(Piloti pil[], int nPiloti) {
    int posmin;

    for(int i = 0; i <= nPiloti - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nPiloti - 1; j++) {
            if(pil[posmin].punti > pil[j].punti) {
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
void creaFileTeam(Piloti pil[], Team tem[], int nTeam, int nPiloti) {
    char ausNome[BUFFER][BUFFER];
    char ausNaz[BUFFER][3];
    int ausPunti[BUFFER];
    char nf[BUFFER];
    FILE* fp;
    int pos = 0;
    char txt[5] = {'.', 't', 'x', 't' , '\0'};

    ordinaTeamNome(tem, nTeam);
    ordinaPilotiTeam(pil, nPiloti);

    for(int i = 0; i < nTeam; i++) {
        int j = 0;

        pos = 0;

        while(pil[j].idTeam <= tem[i].idTeam && j < nPiloti) {
            if(pil[j].idTeam == tem[i].idTeam) {
                strcpy(ausNome[pos], pil[j].nome);
                strcpy(ausNaz[pos], pil[j].nazionalita);
                ausPunti[pos] = pil[j].punti;

                pos++;
            }

            j++;
        }

        strcpy(nf, tem[i].nome);
        strcat(nf, txt);

        fp = fopen(nf, "w");

        for(int k = 0; k < pos; k++) {
            fprintf(fp, "%s - %s - %d\n", ausNome[k], ausNaz[k], ausPunti[k]);
        }

        fclose(fp);
    }
}
void ordinaPilotiTeam(Piloti pil[], int nPiloti) {
    int posmin;

    for(int i = 0; i <= nPiloti - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nPiloti - 1; j++) {
            if(pil[posmin].idTeam > pil[j].idTeam) {
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
void ordinaTeamNome(Team tem[], int nTeam) {
    int posmin;

    for(int i = 0; i <= nTeam - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nTeam - 1; j++) {
            if(strcmp(tem[posmin].nome, tem[j].nome) > 0) {
                posmin = j;
            }
        }
        if(posmin != i) {
            Team aus = tem[i];
            tem[i] = tem[posmin];
            tem[posmin] = aus;
        }
    }
}
void elencoPilotiNaz(Piloti pil[], Team tem[], char naz[], int nPiloti) {
    int i = 0;

    ordinaPilotiNaz(pil, nPiloti);

    while(strcmp(pil[i].nazionalita, naz) <= 0) {
        int j = 0;

        while(tem[j].idTeam != pil[i].idTeam) {
            j++;
        }

        if(strcmp(pil[i].nazionalita, naz) == 0) {
            printf("\n%d\t%s\t\t\t%s\t%d\t\t%s", pil[i].idPil, pil[i].nome, pil[i].nazionalita, pil[i].punti, tem[j].nome);
        }

        i++;
    }
}
void ordinaPilotiNaz(Piloti pil[], int nPiloti) {
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
void ordinaPilotiId(Piloti pil[], int nPiloti) {
    int posmin;

    for(int i = 0; i <= nPiloti - 2; i++) {
        posmin = i;
        for(int j = i + 1; j <= nPiloti - 1; j++) {
            if(pil[posmin].idPil > pil[j].idPil) {
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
void stampaPiloti(Piloti pil[], Team tem[], int nPiloti) {
    printf("idPil\tNome\t\t\t\tNaz\tPunti\t\tTeam");

    ordinaPilotiId(pil, nPiloti);

    for(int i = 0; i < nPiloti; i++) {
        int j = 0;

        while(tem[j].idTeam != pil[i].idTeam) {
            j++;
        }

        printf("\n%d\t%s\t\t\t%s\t%d\t\t%s", pil[i].idPil, pil[i].nome, pil[i].nazionalita, pil[i].punti, tem[j].nome);
    }
}
int caricaTeamDaFIle(char nf[], Team tem[]) {
    int cont = 0;
    FILE* fp;
    char spl[BUFFER];
    char row[BUFFER];

    fp = fopen(nf, "r");

    if(fp != NULL) {
        while(!feof(fp)) {
            fgets(row, BUFFER, fp);
            // idTeam
            splittaString(row, spl, 0, ';');
            tem[cont].idTeam = atoi(spl);
            // nome
            splittaString(row, spl, 1, ';');
            strcpy(tem[cont].nome, spl);
            // motore
            splittaString(row, spl, 2, ';');
            strcpy(tem[cont].motore, spl);

            cont++;
        }
    }
    else {
        printf("Impossibile aprire il file");
    }

    fclose(fp);

    return cont;
}
int caricaPilotiDaFile(char nf[], Piloti pil[]) {
    int cont = 0;
    FILE* fp;
    char spl[BUFFER];
    char row[BUFFER];

    fp = fopen(nf, "r");

    if(fp != NULL) {
        while(!feof(fp)) {
            fgets(row, BUFFER, fp);
            // idPil
            splittaString(row, spl, 0, ';');
            pil[cont].idPil = atoi(spl);
            // nome
            splittaString(row, spl, 1, ';');
            strcpy(pil[cont].nome, spl);
            // nazionalita
            splittaString(row, spl, 2, ';');
            strcpy(pil[cont].nazionalita, spl);
            // punti
            splittaString(row, spl, 3, ';');
            pil[cont].punti = atoi(spl);
            // codTeam
            splittaString(row, spl, 4, ';');
            pil[cont].idTeam = atoi(spl);

            cont++;
        }
    }
    else {
        printf("Impossibile aprire il file");
    }

    fclose(fp);

    return cont;
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
int menu(){
    int sc;
    printf("---------- MENU ----------\n\n");
    printf("1. Elenco Piloti\n");
    printf("2. Elenco piloti nazione in input\n");
    printf("3. Elenco peggiori piloti\n");
    printf("4. Crea file team\n");
    printf("0. Esci\n");
    printf("\nScelta -> ");
    scanf("%d", &sc);
    return sc;
}

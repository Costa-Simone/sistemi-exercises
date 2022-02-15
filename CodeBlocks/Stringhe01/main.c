#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 + 1
#define TRUE 1
#define FALSE 0

void menu(int *sc);
void sostituisciPunto(char frase[]);
int palindroma(char str[]);
int anagramma(char str[], char str2[]);
void azzeraVet(int str[], int len);
int miaLen(char str[]);
void miaUpper(char str[]);
void miaLower(char str[]);
void contaVocaliConsonanti(char str[]);
void invertiStringa(char str[]);
int miaConcat(char str[], char str2[]);
int compareString(char str[], char str2[]);

void clrcls() {
    system("@cls||clear"); //direttiva che ci permette di richiamare un prog dal prompt(clear pulisce in windows, cls linux)
}

int main()
{
    int scelta;
    char s[MAX], s2[MAX];

    do{
        menu(&scelta);

        switch(scelta) {
            case 1: /*Sostituisci punto con carattere a capo*/
                printf("\nInserisci frase: ");
                gets(s); //viene messo /0 al termine della frase (in binario tutti 0)

                sostituisciPunto(s);
                break;

            case 2: /*Conta vocali e consonanti di una frase*/
                printf("Inserisci la frase: ");
                gets(s);
                contaVocaliConsonanti(s);
                break;

            case 3: /*Verifica se parola palindroma*/
                printf("\nInserisci la parola: ");
                gets(s);

                if(palindroma(s) == 1) {
                    printf("\nLa parola e' palindroma\n");
                }
                else {
                    printf("\nLa parola non e' palindroma\n");
                }

                break;

            case 4: /*Anagramma*/
                printf("\nInserisci la prima parola: ");
                gets(s);
                printf("\nInserisci la seconda parola: ");
                gets(s2);

                if(anagramma(s, s2) == TRUE) {
                    printf("\n%s e' l'anagramma di %s\n", s, s2);
                }
                else {
                    printf("\n%s non e' l'anagramma di %s\n", s, s2);
                }

                break;

             case 5: //inverti stringa
                printf("\nInserisci la parola: ");
                gets(s);
                invertiStringa(s);
                printf("La stringa invertita e' %s", s);

                break;

             case 6: //concatena stringhe
                printf("\nInserisci prima parola: ");
                gets(s);
                printf("\nInserisci seconda parola: ");
                gets(s2);

                if(miaConcat(s,s2) == TRUE) {
                    printf("\nStringhe contatenate: %s", s);
                }
                else {
                    printf("\nImpossibile concatenare. Dimensione massima superata\n");
                }

                break;

            case 7: //compare
                printf("\nInserisci prima parola: ");
                gets(s);
                printf("\nInserisci seconda parola: ");
                gets(s2);

                int resCompare = compareString(s,s2);

                if(resCompare == 0) {
                    printf("s1 == s2");
                }
                else {
                    if(resCompare == -1) {
                        printf("s2 < s1");
                    }
                    else {
                        printf("s2 > s1");
                    }
                }

                break;

            case 0: /*Esci*/
                break;

            default:
                printf("Valore non corretto\n");
                break;
        }

        fflush(stdin); //pulizia del buffer per eliminare invio dato precedentemente
        printf("\n(Premi un tasto per continuare)");
        getchar(); // Attendo pressione pulsante per proseguire
        clrcls();
    }while(scelta != 0);

    printf("Programma terminato!\n");

    return 0;
}
int miaLen(char str[]) {
    int i = 0;

    while(str[i] != '\0')
        i++;
    return i;
}
void miaUpper(char str[]) {
    int i = 0;

    while(i < miaLen(str)) {
        if(str[i] >= 97 && str[i] <= 122)
            str[i] -= ('a'-'A'); //in alternativa di sottrarre 32
        i++;
    }
}
void miaLower(char str[]) {
    int i = 0;

    while(i < miaLen(str)) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}
void azzeraVet(int str[], int len) {
    for(int i = 0; i < len; i++)
        str[i] = 0;
}
void menu(int *sc) {
    printf("Menu\n");
    printf("0. Esci\n");
    printf("1. Sostituisci punto con carattere a capo\n");
    printf("2. Conta vocali e consonanti di una frase\n");
    printf("3. Verifica se una parola e' palindroma\n");
    printf("4. Anagramma\n");
    printf("5. Inverti stringa\n");
    printf("6. Concatena due stringhe\n");
    printf("7. Compara stringhe\n");

    printf("\nScelta --> ");
    scanf("%d", sc);
    fflush(stdin);
}
void invertiStringa(char str[]){

    int i,aus;
    int j;
    int len;

    len = strlen(str);
    j = len - 1;
    for(i = 0; i < len / 2; i++)
    {
        aus = str[i];
        str[i] = str[j];
        str[j] = aus;
        j--;
    }
}
void sostituisciPunto(char frase[]) {
    // es. buongiorno.3B INF!!!
    /*
        frasemodificata => buongiorno
                           3B INF!!!
    */
    int len_stringa, i;
    char fraseModificata[MAX];

    printf("\nLa frase inserita e': ");
    // printf("La frase inserita e': %s\n", frase);
    puts(frase);

    len_stringa = miaLen(frase); //passata stringa e restituisce lunghezza senza tappo
    printf("La frase contiene %d caratteri (inclusi gli spazi)\n", len_stringa);

    for(i = 0; i < len_stringa; i++) {
        if(frase[i] == '.')
            fraseModificata[i] = '\n';
        else
            fraseModificata[i] = frase[i];
    }
    fraseModificata[len_stringa] = '\0';

    printf("La frase modificata e':\n");
    puts(fraseModificata);
}
int palindroma(char str[]){

    int len, ris, i, j; //lunghezza stringa

    len = miaLen(str);
    printf("\nLa parola e' composta %d caratteti", len);
    miaLower(str);
    printf("\nLa parola inserita: ");
    puts(str);
    //controllo se str e' palindroma
    i = 0;
    j = len - 1;
    while(i < j && str[i] == str[j]) {
        i++;
        j--;
    }
    if(i >= j)
        ris = TRUE;
    else
        ris = FALSE;

    return ris;
}
int anagramma(char str[], char str2[]) {

    int len, len2, aus = TRUE, par1[26], par2[26];
    int i;
    len = miaLen(str);
    len2 = miaLen(str2);
    miaUpper(str);
    miaUpper(str2);

    if(len == len2) {
        azzeraVet(par1, 26);
        azzeraVet(par2, 26);
        i=0;
        while(str[i] != '\0') {
            par1[str[i] - 65]++;
            par2[str2[i] - 65]++;
            i++;
        }
        i = 0;
        while(i < 26 && aus == TRUE) {
            if(par1[i] != par2[i])
                aus = FALSE;
            else
                i++;
        }
    }
    else
        aus = FALSE;
    return aus;
}
void contaVocaliConsonanti(char str[]){
    int i;
    int cont[26];
    int vocali,cons;

    int len= miaLen(str);
    azzeraVet(cont,26);

    miaLower(str);
    for(i=0;i<len;i++){
        if(str[i]>='a' && str[i]<='z')
        {
            cont[str[i]-'a']++;
        }
    }
    vocali=0;
    cons=0;
    for(i=0;i<26;i++)
        printf("La lettera %c compare %d volte\n", 'a'+i ,cont[i]);
    vocali=cont['a'-'a']+cont['e'-'a']+cont['i'-'a']+cont['o'-'a']+cont['u'-'a'];
    for(i=0;i<26;i++){
        cons=cons+cont[i];
    }
    cons-=vocali;
    printf("Il numero di vocali e' %d\n",vocali);
    printf("Il numero di consonanti e' %d\n",cons);
}
int miaConcat(char str[], char str2[]){
    int len1 = miaLen(str);
    int len2 = miaLen(str2);
    int concat = TRUE;

    if((len1 + len2) > MAX) {
        concat = FALSE;
    }
    else {
        int i = 0;

        while(str2[i] != '/0') {
        str[len1++] = str2[i++];
        }

        str[len1 + i] = '\0';

        printf("La stringa concatenanta e' %s",str);
    }

    return concat;
}
int compareString(char str[], char str2[]){
    int flag, i = 0, min, esci = FALSE, som1 = 0, som2 = 0;

    while(str[i] == str2[i] && str[i] != '/0' && str2[i] != '/0') {
        i++;
    }

    if(str[i] == str2[i]) {
        flag = 0;
    }
    else if(str[i] < str2[i]) {
        flag = -1;
    }
    else {
        flag = 1;
    }

    return flag;
}

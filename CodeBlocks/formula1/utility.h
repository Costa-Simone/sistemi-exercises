#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#define BUFFER 100

void splittaString(char row[], char ret[], int pos, char separatore) {
    int cnt = 0;
    int i = 0;

    while(cnt != pos){
        while(row[i] != separatore) {
            i++;
        }

        cnt++;
        i++;
    }

    cnt = 0;

    while(row[i] != separatore && row[i] != '\0'){
        ret[cnt] = row[i];
        i++;
        cnt++;
    }

    ret[cnt] = '\0';
}

#endif // UTILITY_H_INCLUDED

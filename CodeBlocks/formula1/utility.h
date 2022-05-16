#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#define BUFFER 100

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

#endif /// UTILITY_H_INCLUDED

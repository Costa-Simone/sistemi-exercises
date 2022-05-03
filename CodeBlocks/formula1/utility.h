#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#define BUFFER 100

char* splittaString(char row[], int pos, char separatore) {
    char ret[BUFFER];
    int i = 0, cnt = 0;
    //9;OCON E.;5;0;0
    while(cnt != pos) {
        while(row[i] != separatore) i++;

        cnt++; i++;
    }

    cnt = 0;

    while(row[i] != separatore && row[i] != '\0') {
        ret[cnt] = row[i];
        i++; cnt++;
    }

    ret[cnt] = '\0';

    printf("%s ", ret);

    return ret;
}

#endif // UTILITY_H_INCLUDED

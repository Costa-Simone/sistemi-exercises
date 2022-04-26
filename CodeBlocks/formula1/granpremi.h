#ifndef GRANPREMI_H_INCLUDED
#define GRANPREMI_H_INCLUDED

#define LEN_GP 30

typedef struct granpremio{
    int idGP;
    char nome[LEN_GP];
    int lung;
    int nGiri;
} Granpremi;

int punteggi[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
#endif // GRANPREMI_H_INCLUDED

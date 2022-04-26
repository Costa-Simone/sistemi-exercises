#ifndef SCUDERIE_H_INCLUDED
#define SCUDERIE_H_INCLUDED

#define LEN_SCUDERIA 30
#define LEN_MONOPOSTO 20
typedef struct scuderia{
    int idScuderia;
    char nome[LEN_SCUDERIA];
    char monoposto[LEN_MONOPOSTO];
    float rating;
    int totPunti;
}Scuderie;

#endif // SCUDERIE_H_INCLUDED

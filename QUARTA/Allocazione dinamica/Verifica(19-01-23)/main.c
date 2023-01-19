#include "libreria.h"


int main(void)
{
    Libri *testa = NULL;
    char scelta = ' ';

    testa = loadFromFile(testa, "Libri.csv");
    printf("Libri caricati: %d\n", contaNodi(testa));
    getchar();

    do
    {
        menu(&scelta);

        switch (scelta)
        {
        case 'A':
        case 'a':
            fflush(stdin);
            stampaLista(testa);
            getchar();
        break;
        case 'B': // Cerca ISIN ed elimina nodo se esiste
        case 'b':
            fflush(stdin);

            testa = FindAndDeleteNode(testa);

            getchar();
        break;
        case 'C': // Visualizza libri le cui pagine sono superiori a valore in input (Ordinamento per # pagine DESC)
        case 'c':
            fflush(stdin);

            testa = LibriWithMoreThanXPage(testa);

            getchar();
        break;
        case 'D': // Caricare, in una seconda lista, tutti i libri appartenenti ad un editore dato in input e visualizzarla
        case 'd':
            fflush(stdin);

            testa = LoadOnSecondListLibriOfAnEditor(testa);

            getchar();
        break;
        case 'Q':
        case 'q':
            printf("Arrivederci...\n");
            break;
        default:
            printf("Scelta non disponibile\n");
            getchar();
            break;
        }
    } while (scelta != 'q' && scelta != 'Q');
    return 0;
}
void menu(char *scelta)
{
    system("@cls||clear");
    printf("---LIBRERIA---\n");
    printf("A. Visualizza Libri\n");
    printf("B. Cerca ISIN ed elimina nodo se esiste\n");
    printf("C. Visualizza libri le cui pagine sono superiori a valore in input (Ordinamento per # pagine DESC)\n");
    printf("D. Caricare, in una seconda lista, tutti i libri appartenenti ad un editore dato in input e visualizzarla\n");
    printf("Q. Quit\n");
    printf("Scelta -> ");
    scanf("%c", scelta);
    getchar();
    system("@cls||clear");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../video.h"

int main() {
    PointerVideo lista = NULL;
    clock_t inicio, fim;
    double tempo;

    criaVideoLista(&lista);

    insercaoVideoLista(&lista, 20000);

    inicio = clock();

    liberaListaVideo(&lista);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo para remover 20.000 elementos: %.4f segundos\n", tempo);

    return 0;
}
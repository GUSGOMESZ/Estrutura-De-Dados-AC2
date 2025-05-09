#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../video.h"

int main() {
    PointerVideo lista = NULL;
    clock_t inicio, fim;
    double tempo;

    criaVideoLista(&lista);

    inicio = clock();

    insercaoVideoLista(&lista, 50000);

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo para inserir 50.000 elementos: %.4f segundos\n", tempo);

    liberaListaVideo(&lista);

    return 0;
}
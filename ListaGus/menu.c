#include <stdio.h>
#include "video.h"

int main()
{
    int option = 1;
    PointerVideo pointer_video;

    criaVideoLista(&pointer_video);

    do {
        printf("\nTESTES DE DESEMPENHO\n");
        printf("\n1 - Insere 100 videos na lista");
        printf("\n2 - Insere 1000 videos na lista");
        printf("\n3 - Exibir lista de videos");
        printf("\n0 - Sair\n");
        scanf("%d", &option);
    
        switch(option) {
            case 1:
                insercaoVideoLista(&pointer_video, 100);
                break;
            case 2:
                insercaoVideoLista(&pointer_video, 1000);
                break;
            case 3:
                exibirListaVideo(pointer_video);
                break;
        }
    } while(option != 0);

    printf("Testing commit");

    return 0;
}
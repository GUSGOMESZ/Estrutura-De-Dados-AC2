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
        printf("\n3 - Insere 1.000.000 videos na lista");
        printf("\n8 - Exibir lista de videos");
        printf("\n9 - Limpa lista");
        printf("\n0 - Sair\n");
        scanf("%d", &option);
    
        switch(option) {
            case 1:
                liberaListaVideo(&pointer_video);
                insercaoVideoLista(&pointer_video, 100);
                break;
            case 2:
                liberaListaVideo(&pointer_video);
                insercaoVideoLista(&pointer_video, 1000);
                break;
            case 3:
                liberaListaVideo(&pointer_video);
                insercaoVideoLista(&pointer_video, 1000000);
            case 8:
                exibirListaVideo(pointer_video);
                break;
            case 9:
                liberaListaVideo(&pointer_video);
                printf("\nLista Limpada.\n");
                break;
        }
    } while(option != 0);

    liberaListaVideo(&pointer_video);

    return 0;
}
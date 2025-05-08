#include <stdio.h>
#include <stdlib.h>
#include "video.h"

void criaVideoLista(PointerVideo *p_video) {
    *p_video = NULL;
}

int vaziaVideoLista(PointerVideo *p_video) {
    return (*p_video == NULL);
}

void insercaoVideoLista(PointerVideo *p_video, int quantity) {
    FILE *file = NULL;

    if (quantity == 100) {
        file = fopen("data100.csv", "r");
    } else if (quantity == 1000) {
        file = fopen("data1000.csv", "r");
    }

    if (!file) {
        fprintf(stderr, "Erro ao ler arquivo CSV\n");
        return;
    }

    Video *tail = NULL;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        Video *newVideo = (Video*)malloc(sizeof(Video));
        if (sscanf(line, "%d,%d,%99[^\n]", &newVideo->id, &newVideo->duration, newVideo->title) != 3) {
            free(newVideo);
            continue;
        }
        newVideo->next = NULL;

        if (*p_video == NULL) {
            *p_video = newVideo;
            tail = newVideo;
        } else {
            tail->next = newVideo;
            tail = newVideo;
        }
    }
    fclose(file);

}

void exibirListaVideo(PointerVideo head) {
    if (head == NULL) {
        printf("\nLista de videos esta vazia!\n");
        return;
    }

    Video *current = head;
    int count = 1;
    
    printf("\n=== LISTA DE VIDEOS ===\n");
    while (current != NULL) {
        printf("\nVideo %d\n", count++);
        printf("ID: %d\n", current->id);
        printf("Titulo: %s\n", current->title);
        printf("Duracao: %d minutos\n", current->duration);
        current = current->next;
    }
    printf("\n=== FIM DA LISTA ===\n");
}
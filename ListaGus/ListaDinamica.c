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
    } else {
        file = fopen("data1-000-000.csv", "r");
    }

    if (!file) {
        fprintf(stderr, "Erro ao ler arquivo CSV\n");
        return;
    }

    Video *tail = NULL;
    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        Video *newVideo = (Video*)malloc(sizeof(Video));
        if (sscanf(line, "%ld,%99[^,],%99[^,],%ld,%ld,%ld,%99[^\n]", &newVideo->id, newVideo->titulo, newVideo->duracao, &newVideo->visualizacoes, &newVideo->likes, &newVideo->dislikes, newVideo->tag) != 7) {
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

        // printf("%d\n", count++);
    }

    fclose(file);
}

void exibirListaVideo(PointerVideo head) {
    if (head == NULL) {
        printf("\nLista de videos esta vazia!\n");
        return;
    }

    Video *current = head;
    
    printf("\n=== LISTA DE VIDEOS ===\n");
    while (current != NULL) {
        printf("\nID: %ld\n", current->id);
        printf("Titulo: %s\n", current->titulo);
        printf("Duracao: %s\n", current->duracao);
        printf("Visualizacoes: %ld\n", current->visualizacoes);
        printf("Likes: %ld\n", current->likes);
        printf("Dislikes: %ld\n", current->dislikes);
        printf("Tag: %s\n", current->tag);
        current = current->next;
    }
    printf("\n=== FIM DA LISTA ===\n");
}

void liberaListaVideo(PointerVideo *head) {
    Video *current = *head;
    while (current != NULL) {
        Video *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

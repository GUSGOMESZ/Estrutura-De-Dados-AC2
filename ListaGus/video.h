/*
*   Esqueleto para a implementacao da struct video
*/

typedef struct video {
    long int id;
    char titulo[100];
    char duracao[10];
    long int visualizacoes;
    long int likes;
    long int dislikes;
    char tag[20];
    struct video *next;
} Video;

typedef Video *PointerVideo;

void criaVideoLista(PointerVideo *p_video);

int vaziaVideoLista(PointerVideo *p_video);

void insercaoVideoLista(PointerVideo *p_video, int quantity);

void exibirListaVideo(PointerVideo head);

void liberaListaVideo(PointerVideo *head);
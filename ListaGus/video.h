/*
*   Esqueleto para a implementacao da struct video
*/

typedef struct video {
    int id;
    int duration;
    char title[100];
    struct video *next;
} Video;

typedef Video *PointerVideo;

void criaVideoLista(PointerVideo *p_video);

int vaziaVideoLista(PointerVideo *p_video);

void insercaoVideoLista(PointerVideo *p_video, int quantity);

void exibirListaVideo(PointerVideo head);
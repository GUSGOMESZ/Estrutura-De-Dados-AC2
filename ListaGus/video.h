/*
*   Esqueleto para a implementacao da struct video
*/

typedef struct video {
    int id;
    int duration;
    char title[100];
} Video;

typedef Video *p_video;
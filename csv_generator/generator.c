#include <stdio.h>
#include <stdlib.h>   // srand, rand, malloc, free
#include <string.h>   // strlen, strcpy
#include <time.h>     // time

#define NUM_TAGS 10
#define MAX_TITULO_LEN 20
#define MIN_TITULO_LEN 5

const char *TAGS[NUM_TAGS] = {
    "Culinaria", "Jogos", "Musica", "Educacao",
    "Noticias", "Esportes", "Tecnologia", "Filmes",
    "Vlogs", "Moda"
};

const char CHARS_TITULO[] =
    "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789 ";

/**
 * Gera uma string aleatória de comprimento entre min e max
 * usando o conjunto CHARS_TITULO.
 */
char *gerar_string_aleatoria(int min, int max) {
    int len = min + rand() % (max - min + 1);
    char *s = malloc(len + 1);
    size_t n_chars = strlen(CHARS_TITULO);
    for (int i = 0; i < len; i++) {
        s[i] = CHARS_TITULO[rand() % n_chars];
    }
    s[len] = '\0';
    return s;
}

/**
 * Formata duração no padrão MM:SS.
 */
void gerar_duracao(char *buf) {
    int minutos = rand() % 60;
    int segundos = rand() % 60;
    sprintf(buf, "%02d:%02d", minutos, segundos);
}

/**
 * Escolhe aleatoriamente uma tag dentre TAGS.
 */
const char *escolher_tag() {
    return TAGS[rand() % NUM_TAGS];
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <nome_arquivo.csv> <num_registros>\n", argv[0]);
        return 1;
    }

    const char *nome_arquivo = argv[1];
    long num_registros = atol(argv[2]);

    // Inicializa gerador pseudoaleatório
    srand((unsigned int)time(NULL));  //  [oai_citation:2‡Cplusplus.com](https://cplusplus.com/reference/cstdlib/srand/?utm_source=chatgpt.com)

    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    // Cabeçalho CSV
    fprintf(fp, "id,titulo,duracao,visualizacoes,likes,dislikes,tag\n");  //  [oai_citation:3‡Stack Overflow](https://stackoverflow.com/questions/69571810/fprintf-to-a-csv-file-in-c-by-using-pointer?utm_source=chatgpt.com)

    // Geração de registros
    for (long i = 1; i <= num_registros; i++) {
        char *titulo = gerar_string_aleatoria(MIN_TITULO_LEN, MAX_TITULO_LEN);
        char duracao[6];
        gerar_duracao(duracao);

        long vis = rand() % 10000001;               // até 10^7 visualizações
        long likes = rand() % (vis + 1);            // até vis
        long dislikes = rand() % (vis - likes + 1); // até o restante

        const char *tag = escolher_tag();

        fprintf(fp, "%ld,%s,%s,%ld,%ld,%ld,%s\n",
                i, titulo, duracao, vis, likes, dislikes, tag);  //  [oai_citation:4‡Stack Overflow](https://stackoverflow.com/questions/69571810/fprintf-to-a-csv-file-in-c-by-using-pointer?utm_source=chatgpt.com)

        free(titulo);
    }

    fclose(fp);
    printf("Arquivo '%s' gerado com %ld registros.\n", nome_arquivo, num_registros);
    return 0;
}
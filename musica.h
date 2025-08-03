#ifndef MUSICA_H
#define MUSICA_H

typedef struct Musica {
    char nome[100];
    struct Musica *anterior;
    struct Musica *proxima;
} Musica;

extern Musica *inicio;
extern Musica *atual;

Musica* novaMusica(char *nome);
void adicionarMusica(char *nome);
void removerMusica(char *nome);
void listarMusicas(void);

#endif
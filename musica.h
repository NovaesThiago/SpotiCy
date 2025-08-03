#ifndef MUSICA_H
#define MUSICA_H

#include <stdbool.h>

typedef struct Musica {
    char nome[100];
    struct Musica *anterior;
    struct Musica *proxima;
} Musica;

Musica* novaMusica(char *nome);
void adicionarMusica(char *nome);
void removerMusica(char *nome);
void listarMusicas(void);

extern Musica *inicio;
extern Musica *atual;

#endif
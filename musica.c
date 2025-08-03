#include "musica.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Musica *inicio = NULL;
Musica *atual = NULL;

Musica* novaMusica(char *nome) {
    Musica *m = (Musica*) malloc(sizeof(Musica));
    strcpy(m->nome, nome);
    m->proxima = m->anterior = m;
    return m;
}


void adicionarMusica(char *nome) {
    Musica *m = novaMusica(nome);
    if (inicio == NULL) {
        inicio = atual = m;
    } else {
        Musica *fim = inicio->anterior;
        fim->proxima = m;
        m->anterior = fim;
        m->proxima = inicio;
        inicio->anterior = m;
    }
    printf("================================================================================\n");
    printf("ADICIONADA: %s \n", nome);
}

void removerMusica(char *nome) {
    if (inicio == NULL) return;

    Musica *temp = inicio;
    do {
        if (strcmp(temp->nome, nome) == 0) {
            if (temp->proxima == temp) {
                free(temp);
                inicio = atual = NULL;
                return;
            }
            temp->anterior->proxima = temp->proxima;
            temp->proxima->anterior = temp->anterior;
            if (temp == inicio) inicio = temp->proxima;
            if (temp == atual) atual = temp->proxima;
            free(temp);
            printf("================================================================================\n");
            printf("REMOVIDA: %s\n", nome);
            return;
        }
        temp = temp->proxima;
    } while (temp != inicio);
    printf("================================================================================\n");
    printf("MUSICA %s NÃO ENCONTRADA.\n", nome);
}

void listarMusicas() {
    if (inicio == NULL) {
        printf("================================================================================\n");
        printf("LISTA DE MUSICAS VAZIA.\n");
        return;
    }
    Musica *temp = inicio;
    printf("================================================================================\n");
    printf("MÚSICAS DISPONÍVEIS:\n");
    do {
        printf("- %s\n", temp->nome);
        temp = temp->proxima;
    } while (temp != inicio);
}
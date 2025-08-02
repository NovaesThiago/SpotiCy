#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char nome[100];
    struct Musica *anterior;
    struct Musica *proxima;
} Musica;

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
    printf("Adicionada: %s\n", nome);
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
            printf("Removida: %s\n", nome);
            return;
        }
        temp = temp->proxima;
    } while (temp != inicio);

    printf("Música '%s' não encontrada.\n", nome);
}

void tocarProxima() {
    if (atual == NULL) {
        printf("Nenhuma música para tocar.\n");
        return;
    }
    atual = atual->proxima;
    printf("Tocando: %s\n", atual->nome);
}

void tocarAnterior() {
    if (atual == NULL) {
        printf("Nenhuma música para tocar.\n");
        return;
    }
    atual = atual->anterior;
    printf("Tocando: %s\n", atual->nome);
}

void listarMusicas() {
    if (inicio == NULL) {
        printf("Lista de músicas vazia.\n");
        return;
    }

    Musica *temp = inicio;
    printf("Lista de músicas:\n");
    do {
        printf("- %s\n", temp->nome);
        temp = temp->proxima;
    } while (temp != inicio);
}

int main() {
    adicionarMusica("Imagine");
    adicionarMusica("Bohemian Rhapsody");
    adicionarMusica("Hey Jude");
    
    listarMusicas();

    tocarProxima();
    tocarAnterior();

    removerMusica("Bohemian Rhapsody");
    listarMusicas();

    return 0;
}
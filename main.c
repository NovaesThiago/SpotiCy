#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica { // Ele vai definir uma estrutura e dois ponteiros do tipo musica.
    char nome[100];
    struct Musica *anterior;
    struct Musica *proxima;
} Musica;

Musica *inicio = NULL;
Musica *atual = NULL;

Musica* novaMusica(char *nome) {// função devolve um ponteiro para o tipo Musica. O ponteiro char vai apontar para todos os caracteres da palavra até o \0 que marca o final.
    Musica *m = (Musica*) malloc(sizeof(Musica)); //Rapaz aqui é pro caba endoidar mesmo. um ponteiro do tipo Musica
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


int main(){

    int opcao;

    do{
    printf("==========================================================================\n");
    printf("|                      |>  SPOTICY TERMINAL EDITION                      |\n");
    printf("==========================================================================\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("|                                                                        |\n");
    printf("--------------------------------------------------------------------------\n");
    printf("|   1 [ |<< ]    2 [ |> ]    3 [ || ]    4 [ >>| ]    5 [ + ]    6 [ -> ]|\n");
    printf("--------------------------------------------------------------------------\n");

    opcao = scanf(" ");

    switch(opcao){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
    }
    }while (opcao != 6);
    
    return 0;
};
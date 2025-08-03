#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Musica {
    char nome[100];
    struct Musica *anterior;
    struct Musica *proxima;
} Musica;

Musica *inicio = NULL;
Musica *atual = NULL;
bool rodando = false;

Musica* novaMusica(char *nome) {
    Musica *m = (Musica*) malloc(sizeof(Musica));
    strcpy(m->nome, nome);
    m->proxima = m->anterior = m;
    return m;
}

void iniciar() {
    if (atual == NULL) {
        printf("==========================================================================\n");
        printf("NENHUMA MÚSICA SELECIONADA.\n");
        return;
    }
    rodando = true;
    printf("==========================================================================\n");
    printf("TOCANDO: %s\n", atual->nome);
}

void parar() {
    if (rodando) {
        printf("==========================================================================\n");
        printf("MÚSICA PAUSADA: %s\n", atual ? atual->nome : "DESCONHECIDA");
        rodando = false;
    } else {
        printf("==========================================================================\n");
        printf("NADA ESTÁ TOCANDO.\n");
    }
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
    printf("==========================================================================\n");
    printf("ADICIONADA: %s \n", nome);
}

void tocarProxima() {
    if (atual == NULL) {
        printf("==========================================================================\n");
        printf("NENHUMA MUSICA PARA TOCAR.\n");
        return;
    }
    atual = atual->proxima;
    if (rodando)
        printf("==========================================================================\n");
        printf("PRÓXIMA: %s\n", atual->nome);
}

void tocarAnterior() {
    if (atual == NULL) {
        printf("==========================================================================\n");
        printf("NENHUMA MUSICA PARA TOCAR.\n");
        return;
    }
    atual = atual->anterior;
    if (rodando)
        printf("==========================================================================\n");
        printf("ANTERIOR: %s\n", atual->nome);
}

void listarMusicas() {
    if (inicio == NULL) {
        printf("==========================================================================\n");
        printf("LISTA DE MUSICAS VAZIA.\n");
        return;
    }
    Musica *temp = inicio;
    printf("==========================================================================\n");
    printf("MÚSICAS DISPONÍVEIS:\n");
    do {
        printf("- %s\n", temp->nome);
        temp = temp->proxima;
    } while (temp != inicio);
}

int main() {
    int opcao;
    char nomeMusica[100];

    do {
        printf("==========================================================================\n");
        printf("|   1 [ |<< ]    2 [ |> ]    3 [ || ]    4 [ >>| ]    5 [ + ]    6 [ -> ]|\n");
        printf("==========================================================================\n");
        printf("|                      |>  SPOTICY TERMINAL EDITION                      |\n");
        printf("==========================================================================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                system("cls");
                tocarAnterior();
                break;
            case 2:
                system("cls");
                iniciar();
                break;
            case 3:
                system("cls");
                parar();
                break;
            case 4:
                system("cls");
                tocarProxima();
                break;
            case 5:
                system("cls");
                printf("==========================================================================\n");
                printf("DIGITE O NOME DA MUSICA: \n");
                printf("==========================================================================\n");
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                nomeMusica[strcspn(nomeMusica, "\n")] = 0;
                adicionarMusica(nomeMusica);
                break;
            case 6:
                printf("Saindo do Spoticy...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 6);

    return 0;
}
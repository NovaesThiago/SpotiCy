#include "player.h"
#include "musica.h"
#include <stdio.h>

bool rodando = false;

void iniciar() {
    if (atual == NULL) {
        printf("================================================================================\n");
        printf("NENHUMA MÚSICA SELECIONADA.\n");
        return;
    }
    rodando = true;
    printf("================================================================================\n");
    printf("TOCANDO: %s\n", atual->nome);
}

void parar() {
    if (rodando) {
        printf("================================================================================\n");
        printf("MÚSICA PAUSADA: %s\n", atual ? atual->nome : "DESCONHECIDA");
        rodando = false;
    } else {
        printf("================================================================================\n");
        printf("NADA ESTÁ TOCANDO.\n");
    }
}


void tocarProxima() {
    if (atual == NULL) {
        printf("================================================================================\n");
        printf("NENHUMA MUSICA PARA TOCAR.\n");
        return;
    }
    atual = atual->proxima;
    if (rodando)
        printf("================================================================================\n");
        printf("PRÓXIMA: %s\n", atual->nome);
}


void tocarAnterior() {
    if (atual == NULL) {
        printf("================================================================================\n");
        printf("NENHUMA MUSICA PARA TOCAR.\n");
        return;
    }
    atual = atual->anterior;
    if (rodando)
        printf("================================================================================\n");
        printf("ANTERIOR: %s\n", atual->nome);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "player.h"

int main() {
    int opcao;
    char nomeMusica[100];

    do {
        printf("================================================================================\n");
        printf("|0[ x ]   1 [ |<< ]    2 [ |> ]    3 [ || ]    4 [ >>| ]    5 [ + ]    6 [ -> ]|\n");
        printf("================================================================================\n");
        printf("|                         |>  SPOTICY TERMINAL EDITION                         |\n");
        printf("================================================================================\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 0:
                system("cls");
                printf("================================================================================\n");
                printf("DIGITE O NOME DA MUSICA: \n");
                printf("================================================================================\n");
                fgets(nomeMusica, sizeof(nomeMusica), stdin);
                nomeMusica[strcspn(nomeMusica, "\n")] = 0;
                removerMusica(nomeMusica);
                break;
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
                printf("================================================================================\n");
                printf("DIGITE O NOME DA MUSICA: \n");
                printf("================================================================================\n");
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
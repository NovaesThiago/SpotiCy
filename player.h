#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

extern bool rodando;

void iniciar(void);
void parar(void);
void tocarProxima(void);
void tocarAnterior(void);

#endif
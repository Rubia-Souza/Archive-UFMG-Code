#ifndef POSICAO_H
#define POSICAO_H

#include <stdbool.h>

typedef struct Posicao {
    unsigned int x;
    unsigned int y;
    unsigned int numero;
} Posicao;

Posicao* newPosicao();
void destruirPosicao(Posicao* posicao);

bool foiVisitada(const Posicao* posicao);

#endif

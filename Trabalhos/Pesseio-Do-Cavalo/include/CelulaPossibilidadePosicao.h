#ifndef CELULA_PRIORIDADE_H
#define CELULA_PRIORIDADE_H

#include "Posicao.h"

typedef struct CelulaPossibilidadePosicao {
    struct CelulaPossibilidadePosicao* proxima;
    Posicao* valor;
    unsigned int quantidadePossibilidades;
} CelulaPossibilidadePosicao;

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicao();
CelulaPossibilidadePosicao* newCelulaPossibilidadePosicaoComValor(Posicao* valor, const unsigned int quantidadePossibilidades);

void destruirCelulaPossibilidadePosicao(CelulaPossibilidadePosicao* celula);

#endif

#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include <stdbool.h>

#include "CelulaPossibilidadePosicao.h"
#include "Posicao.h"

typedef struct FilaPossibilidadePosicoes {
    CelulaPossibilidadePosicao* inicio;
    unsigned int tamanho;
} FilaPossibilidadePosicoes;

FilaPossibilidadePosicoes* newFilaPossibilidadePosicoes();
void destruirFilaPossibilidadePosicoes(FilaPossibilidadePosicoes* fila);

void adicionar(FilaPossibilidadePosicoes* fila, Posicao* posicao, const unsigned int quantidadePossibilidades);
Posicao* remover(FilaPossibilidadePosicoes* fila);

void limpar(FilaPossibilidadePosicoes* fila);
bool estaVazia(const FilaPossibilidadePosicoes* fila);

#endif

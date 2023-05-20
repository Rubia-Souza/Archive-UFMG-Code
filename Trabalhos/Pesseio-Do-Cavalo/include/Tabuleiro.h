#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdbool.h>

#include "Posicao.h"

#define TAMANHO_PADRAO_TABULEIRO 8

typedef struct Tabuleiro {
    unsigned int altura;
    unsigned int largura;
    unsigned int quantidadePosicoes;
    Posicao** posicoes;
} Tabuleiro;

Tabuleiro* newTabuleiro(const unsigned int largura, const unsigned int altura);
void destruirTabuleiro(Tabuleiro* tabuleiro);

bool posicaoXYEhValida(const Tabuleiro* tabuleiro, const unsigned int x, const unsigned int y);

void printTabuleiro(const Tabuleiro* tabuleiro);

#endif

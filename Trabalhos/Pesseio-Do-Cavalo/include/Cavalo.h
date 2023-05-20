#ifndef CAVALO_H
#define CAVALO_H

#include <stdbool.h>

#include "Movimentos.h"
#include "Posicao.h"
#include "Tabuleiro.h"

typedef struct Cavalo {
    Posicao* posicaoAtual;
    unsigned int casasDiferentesVisitadas;
    unsigned int totalCasasVisitadas;
    unsigned int totalCasasRetrocedidas;
} Cavalo;

Cavalo* newCavalo();
void destruirCavalo(Cavalo* cavalo);

void mover(Cavalo* cavalo, Posicao* novaPosicao);
void retroceder(Cavalo* cavalo, Posicao* posicaoAnterior);

void printDadosCavalo(const Cavalo* cavalo);

#endif

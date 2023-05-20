#include <stdio.h>
#include <stdlib.h>

#include "Cavalo.h"

#include "Movimentos.h"
#include "Posicao.h"
#include "Tabuleiro.h"

Cavalo* newCavalo() {
    Cavalo* cavalo = (Cavalo*) malloc(sizeof(Cavalo));

    cavalo->casasDiferentesVisitadas = 0;
    cavalo->totalCasasRetrocedidas = 0;
    cavalo->totalCasasVisitadas = 0;
    cavalo->posicaoAtual = NULL;

    return cavalo;
}

void destruirCavalo(Cavalo* cavalo) {
    cavalo->casasDiferentesVisitadas = 0;
    cavalo->totalCasasRetrocedidas = 0;
    cavalo->totalCasasVisitadas = 0;
    
    cavalo->posicaoAtual = NULL;

    free(cavalo);
    return;
}

void mover(Cavalo* cavalo, Posicao* novaPosicao) {
    cavalo->casasDiferentesVisitadas = cavalo->casasDiferentesVisitadas + 1;
    cavalo->totalCasasVisitadas = cavalo->totalCasasVisitadas + 1;

    novaPosicao->numero = cavalo->casasDiferentesVisitadas;

    cavalo->posicaoAtual = novaPosicao;

    return;
}

void retroceder(Cavalo* cavalo, Posicao* posicaoAnterior) {
    cavalo->totalCasasRetrocedidas = cavalo->totalCasasRetrocedidas + 1;
    cavalo->casasDiferentesVisitadas = cavalo->casasDiferentesVisitadas - 1;

    cavalo->posicaoAtual->numero = 0;
    cavalo->posicaoAtual = posicaoAnterior;

    return;
}

void printDadosCavalo(const Cavalo* cavalo) {
    printf("\nTotal Casas Visitadas: %d", cavalo->totalCasasVisitadas);
    printf("\nTotal Casas Retrocedidas: %d", cavalo->totalCasasRetrocedidas);
    printf("\nQuantidade Casas Diferentes Visitadas: %d\n", cavalo->casasDiferentesVisitadas);

    return;
}

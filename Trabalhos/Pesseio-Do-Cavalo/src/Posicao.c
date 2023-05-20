#include <stdlib.h>
#include <stdbool.h>

#include "Posicao.h"

Posicao* newPosicao() {
    Posicao* novaPosicao = (Posicao*) malloc(sizeof(Posicao));

    novaPosicao->x = 0;
    novaPosicao->y = 0;
    novaPosicao->numero = 0;

    return novaPosicao;
}

void destruirPosicao(Posicao* posicao) {
    posicao->x = 0;
    posicao->y = 0;
    posicao->numero = 0;

    free(posicao);
    
    return;
}

bool foiVisitada(const Posicao* posicao) {
    return (posicao->numero > 0);
}

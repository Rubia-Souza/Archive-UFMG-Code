#include <stdlib.h>

#include "CelulaPossibilidadePosicao.h"

#include "Posicao.h"

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicao() {
    CelulaPossibilidadePosicao* novaCelula = (CelulaPossibilidadePosicao*) malloc(sizeof(CelulaPossibilidadePosicao));
    
    novaCelula->proxima = NULL;
    novaCelula->valor = NULL;
    novaCelula->quantidadePossibilidades = 0;

    return novaCelula;
}

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicaoComValor(Posicao* valor, const unsigned int quantidadePossibilidades) {
    CelulaPossibilidadePosicao* novaCelula = (CelulaPossibilidadePosicao*) malloc(sizeof(CelulaPossibilidadePosicao));
    
    novaCelula->proxima = NULL;
    novaCelula->valor = valor;
    novaCelula->quantidadePossibilidades = quantidadePossibilidades;

    return novaCelula;
}

void destruirCelulaPossibilidadePosicao(CelulaPossibilidadePosicao* celula) {
    celula->proxima = NULL;
    celula->valor = NULL;
    celula->quantidadePossibilidades = 0;

    free(celula);
    return;
}

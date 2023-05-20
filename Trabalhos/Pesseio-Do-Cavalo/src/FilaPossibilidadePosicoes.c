#include <stdlib.h>
#include <stdbool.h>

#include "FilaPossibilidadePosicoes.h"

#include "CelulaPossibilidadePosicao.h"
#include "Posicao.h"

FilaPossibilidadePosicoes* newFilaPossibilidadePosicoes() {
    FilaPossibilidadePosicoes* fila = (FilaPossibilidadePosicoes*) malloc(sizeof(FilaPossibilidadePosicoes));

    fila->inicio = newCelulaPossibilidadePosicao();
    fila->tamanho = 0;

    return fila;
}

void destruirFilaPossibilidadePosicoes(FilaPossibilidadePosicoes* fila) {
    limpar(fila);
    fila->inicio = NULL;

    free(fila);
    return;
}

void adicionar(FilaPossibilidadePosicoes* fila, Posicao* posicao, const unsigned int quantidadePossibilidades) {
    if(estaVazia(fila)) {
        fila->inicio->proxima = newCelulaPossibilidadePosicaoComValor(posicao, quantidadePossibilidades);
        fila->tamanho++;
        return;
    }

    CelulaPossibilidadePosicao* anterior = fila->inicio;
    while(anterior->proxima != NULL && quantidadePossibilidades > anterior->proxima->quantidadePossibilidades) {
        anterior = anterior->proxima;
    }

    CelulaPossibilidadePosicao* continuacaoFila = anterior->proxima;
    anterior->proxima = newCelulaPossibilidadePosicaoComValor(posicao, quantidadePossibilidades);
    anterior->proxima->proxima = continuacaoFila;

    fila->tamanho++;
    return;
}

Posicao* remover(FilaPossibilidadePosicoes* fila) {
    if(estaVazia(fila)) {
        return NULL;
    }

    CelulaPossibilidadePosicao* primeiraCelula = fila->inicio->proxima;

    Posicao* valor = primeiraCelula->valor;
    fila->inicio->proxima = primeiraCelula->proxima;

    destruirCelulaPossibilidadePosicao(primeiraCelula);
    return valor;
}

void limpar(FilaPossibilidadePosicoes* fila) {
    if(estaVazia(fila)) {
        return;
    }

    CelulaPossibilidadePosicao* proximaCelula = NULL;
    for(CelulaPossibilidadePosicao* iterador = fila->inicio->proxima; iterador != NULL; iterador = proximaCelula) {
        proximaCelula = iterador->proxima;
        destruirCelulaPossibilidadePosicao(iterador);
    }

    fila->tamanho = 0;
    return;
}

bool estaVazia(const FilaPossibilidadePosicoes* fila) {
    return (fila->tamanho <= 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Tabuleiro.h"

#include "Posicao.h"
#include "Cavalo.h"

Tabuleiro* newTabuleiro(const unsigned int largura, const unsigned int altura) {
    Tabuleiro* novoTabuleiro = (Tabuleiro*) malloc(sizeof(Tabuleiro));

    novoTabuleiro->altura = altura;
    novoTabuleiro->largura = largura;

    novoTabuleiro->posicoes = (Posicao**) malloc(novoTabuleiro->altura * sizeof(Posicao*));
    for(unsigned int y = 0; y < novoTabuleiro->altura; y++) {
        novoTabuleiro->posicoes[y] = (Posicao*) malloc(novoTabuleiro->largura * sizeof(Posicao));

        for(unsigned int x = 0; x < novoTabuleiro->largura; x++) {
            novoTabuleiro->posicoes[y][x].x = x;
            novoTabuleiro->posicoes[y][x].y = y;
            novoTabuleiro->posicoes[y][x].numero = 0;
        }
    }

    novoTabuleiro->quantidadePosicoes = (novoTabuleiro->altura * novoTabuleiro->largura);
    return novoTabuleiro;
}

void destruirTabuleiro(Tabuleiro* tabuleiro) {
    tabuleiro->altura = 0;
    tabuleiro->largura = 0;
    
    for(unsigned int y = 0; y < tabuleiro->altura; y++) {
        for(unsigned int x = 0; x < tabuleiro->largura; x++) {
            tabuleiro->posicoes[y][x].x = 0;
            tabuleiro->posicoes[y][x].y = 0;
            tabuleiro->posicoes[y][x].numero = 0;
        }

        free(tabuleiro->posicoes[y]);
    }
    
    free(tabuleiro);
    return;
}

bool posicaoXYEhValida(const Tabuleiro* tabuleiro, const unsigned int x, const unsigned int y) {
    return (x >= 0 && x < tabuleiro->largura && y >= 0 && y < tabuleiro->altura);
}

void printTabuleiro(const Tabuleiro* tabuleiro) {
    printf("\t");
    for(unsigned int i = 0; i < tabuleiro->largura; i++) {
        printf("%d", i + 1);

        if(i != (tabuleiro->largura - 1)) {
            printf("\t");
        }
    }
    printf("\n");

    for(unsigned int y = 0; y < tabuleiro->altura; y++) {
        printf("%d\t", y + 1);

        for(unsigned int x = 0; x < tabuleiro->largura; x++) {
            printf("%d", tabuleiro->posicoes[y][x].numero);

            if(x != (tabuleiro->largura - 1)) {
                printf("\t");
            }
        }

        printf("\n");
    }

    return;
}

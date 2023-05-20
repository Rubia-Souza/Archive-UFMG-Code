#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

#include "passeio.h"

#include "Cavalo.h"
#include "Posicao.h"
#include "Tabuleiro.h"
#include "EscritorArquivoSaida.h"
#include "FilaPossibilidadePosicoes.h"

bool andar(Cavalo* cavalo, Tabuleiro* tabuleiro);

void passeio(const unsigned int x, const unsigned int y) {
    if(x > TAMANHO_PADRAO_TABULEIRO || y > TAMANHO_PADRAO_TABULEIRO) {
        return;
    }

    inicializarTiposMovimentos();

    Tabuleiro* tabuleiro = newTabuleiro(TAMANHO_PADRAO_TABULEIRO, TAMANHO_PADRAO_TABULEIRO);
    Cavalo* epona = newCavalo();
    
    unsigned int xPosicaoInicial = (x == 0) ? 0 : x - 1;
    unsigned int yPosicaoInicial = (y == 0) ? 0 : y - 1;

    epona->posicaoAtual = &tabuleiro->posicoes[xPosicaoInicial][yPosicaoInicial];
    epona->casasDiferentesVisitadas++;
    epona->totalCasasVisitadas++;

    tabuleiro->posicoes[xPosicaoInicial][yPosicaoInicial].numero = 1;

    andar(epona, tabuleiro);
    criarArquivoSaida(tabuleiro, epona);

    printTabuleiro(tabuleiro);
    printDadosCavalo(epona);

    destruirCavalo(epona);
    destruirTabuleiro(tabuleiro);
    return;
}

bool andar(Cavalo* cavalo, Tabuleiro* tabuleiro) {
    if(cavalo->casasDiferentesVisitadas >= tabuleiro->quantidadePosicoes) {
        return true;
    }

    FilaPossibilidadePosicoes* filaPosicoes = newFilaPossibilidadePosicoes();

    for(unsigned int i = 0; i < QUANTIDADE_TIPOS_MOVIMENTOS; i++) {
        int proximaPosicaoEixoX = cavalo->posicaoAtual->x + TIPOS_MOVIMENTOS[i].horizontal;
        int proximaPosicaoEixoY = cavalo->posicaoAtual->y + TIPOS_MOVIMENTOS[i].vertical;

        if(!posicaoXYEhValida(tabuleiro, proximaPosicaoEixoX, proximaPosicaoEixoY)) {
            continue;
        }

        Posicao* proximaPosicao = &tabuleiro->posicoes[proximaPosicaoEixoY][proximaPosicaoEixoX];
        if(!foiVisitada(proximaPosicao)) {
            unsigned int quantidadePossibilidades = 0;

            for(unsigned int j = 0; j < QUANTIDADE_TIPOS_MOVIMENTOS; j++) {
                int posicaoDerivadaProximaEixoX = proximaPosicao->x + TIPOS_MOVIMENTOS[j].horizontal;
                int posicaoDerivadaProximaEixoY = proximaPosicao->y + TIPOS_MOVIMENTOS[j].vertical;

                if(!posicaoXYEhValida(tabuleiro, posicaoDerivadaProximaEixoX, posicaoDerivadaProximaEixoY)) {
                    continue;
                }
                else if(!foiVisitada(&tabuleiro->posicoes[posicaoDerivadaProximaEixoY][posicaoDerivadaProximaEixoX])) {
                    quantidadePossibilidades++;
                }
            }

            adicionar(filaPosicoes, proximaPosicao, quantidadePossibilidades);
        }
    }

    for(unsigned int i = 0; i < filaPosicoes->tamanho; i++) {
        Posicao* posicaoAnterior = cavalo->posicaoAtual;
        Posicao* proximaPosicao = remover(filaPosicoes);
        
        mover(cavalo, proximaPosicao);

        if(andar(cavalo, tabuleiro)) {
            destruirFilaPossibilidadePosicoes(filaPosicoes);
            return true;
        }

        retroceder(cavalo, posicaoAnterior);
    }

    destruirFilaPossibilidadePosicoes(filaPosicoes);
    return false;
}

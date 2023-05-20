#include "QuickSortMediana.h"

#include <cmath>

#include "Utils.h"
#include "Selecao.h"
#include "DadosDesempenho.h"
#include "Registro.h"

QuickSortMediana::QuickSortMediana() {}

QuickSortMediana::~QuickSortMediana() {}

void QuickSortMediana::ordenarCrescente(Registro vetor[], const unsigned int tamanho, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) {
    quickSortCrescente(vetor, 0, tamanho - 1, quantidadePossiveisPivos, dadosDesempenho);
    return;
}

void QuickSortMediana::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) {
    quickSortDecrescente(vetor, 0, tamanho - 1, quantidadePossiveisPivos, dadosDesempenho);
    return;
}

void QuickSortMediana::quickSortCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita, quantidadePossiveisPivos, dadosDesempenho);

    if(posicaoInicial < indexDireita) {
        quickSortCrescente(vetor, posicaoInicial, indexDireita, quantidadePossiveisPivos, dadosDesempenho);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortCrescente(vetor, indexEsquerda, poiscaoFinal, quantidadePossiveisPivos, dadosDesempenho);
    }

    return;
}

void QuickSortMediana::particionarCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = selecionarPivo(vetor, posicaoInicial, poiscaoFinal, quantidadePossiveisPivos, dadosDesempenho);

    do {
        dadosDesempenho.quantidadeComparacoes++;
        while(pivo > vetor[*indexEsquerda]) {
            dadosDesempenho.quantidadeComparacoes++;
            (*indexEsquerda)++;
        }

        dadosDesempenho.quantidadeComparacoes++;
        while(pivo < vetor[*indexDireita]) {
            dadosDesempenho.quantidadeComparacoes++;
            (*indexDireita)--;
        }

        if(*indexEsquerda <= *indexDireita) {
            Registro trocaTemporaria = vetor[*indexEsquerda];
            vetor[*indexEsquerda] = vetor[*indexDireita];
            vetor[*indexDireita] = trocaTemporaria;

            dadosDesempenho.quantidadeAtribuicoes += 3;

            (*indexEsquerda)++;
            (*indexDireita)--;
        }
    } while(*indexEsquerda <= *indexDireita);
    
    return;
}

Registro QuickSortMediana::selecionarPivo(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) {
    unsigned int quantidadePivosSeraoEscolhidos = 0;
    if(quantidadePossiveisPivos >= (poiscaoFinal - posicaoInicial + 1)) {
        return vetor[posicaoInicial];
    }
    else {
        quantidadePivosSeraoEscolhidos = quantidadePossiveisPivos;
    }
    unsigned int* posicoesEscolhidas = new unsigned int[quantidadePivosSeraoEscolhidos];

    posicoesEscolhidas[0] = Utils::gerarNumeroInteiroAleatorioEmUmaFaixa(posicaoInicial, poiscaoFinal);
    for(unsigned int i = 1; i < quantidadePivosSeraoEscolhidos; i++) {
        unsigned int possivelPosicao = Utils::gerarNumeroInteiroAleatorioEmUmaFaixa(posicaoInicial, poiscaoFinal);

        for(unsigned int j = 0; j < i; j++) {
            if(possivelPosicao == posicoesEscolhidas[j]) {
                i--;
                break;
            }
            
            if(j == i - 1) {
                posicoesEscolhidas[i] = possivelPosicao;
                break;
            }
        }
    }

    Selecao::ordenarCrescente(posicoesEscolhidas, quantidadePivosSeraoEscolhidos);

    unsigned int indexMediana = std::floor(quantidadePivosSeraoEscolhidos / 2.0); 
    unsigned int indexPivoEscolhido = posicoesEscolhidas[indexMediana];

    delete[] posicoesEscolhidas;
    return vetor[indexPivoEscolhido];
}


void QuickSortMediana::quickSortDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarDecrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita, quantidadePossiveisPivos, dadosDesempenho);

    if(posicaoInicial < indexDireita) {
        quickSortDecrescente(vetor, posicaoInicial, indexDireita, quantidadePossiveisPivos, dadosDesempenho);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortDecrescente(vetor, indexEsquerda, poiscaoFinal, quantidadePossiveisPivos, dadosDesempenho);
    }

    return;
}

void QuickSortMediana::particionarDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = selecionarPivo(vetor, posicaoInicial, poiscaoFinal, quantidadePossiveisPivos, dadosDesempenho);

    do {
        dadosDesempenho.quantidadeComparacoes++;
        while(pivo < vetor[*indexEsquerda]) {
            dadosDesempenho.quantidadeComparacoes++;
            (*indexEsquerda)++;
        }

        dadosDesempenho.quantidadeComparacoes++;
        while(pivo > vetor[*indexDireita]) {
            dadosDesempenho.quantidadeComparacoes++;
            (*indexDireita)--;
        }

        if(*indexEsquerda <= *indexDireita) {
            Registro trocaTemporaria = vetor[*indexEsquerda];
            vetor[*indexEsquerda] = vetor[*indexDireita];
            vetor[*indexDireita] = trocaTemporaria;

            dadosDesempenho.quantidadeAtribuicoes += 3;

            (*indexEsquerda)++;
            (*indexDireita)--;
        }
    } while(*indexEsquerda <= *indexDireita);
    
    return;
}

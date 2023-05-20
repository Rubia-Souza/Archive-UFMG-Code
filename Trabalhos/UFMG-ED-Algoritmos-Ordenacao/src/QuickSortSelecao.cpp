#include "QuickSortSelecao.h"

#include "Registro.h"
#include "DadosDesempenho.h"

QuickSortSelecao::QuickSortSelecao() {}

QuickSortSelecao::~QuickSortSelecao() {}

void QuickSortSelecao::ordenarCrescente(Registro vetor[], const unsigned int tamanho, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho) {
    quickSortCrescente(vetor, 0, tamanho-1, tamanhoMinimo, dadosDesempenho);
    return;
}

void QuickSortSelecao::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho) {
    quickSortDecrescente(vetor, 0, tamanho-1, tamanhoMinimo, dadosDesempenho);
    return;
}

void QuickSortSelecao::quickSortCrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho) {
    while(posicaoInicial < posicaoFinal) {
        if (posicaoFinal - posicaoInicial < tamanhoMinimo) {
            selecaoCrescente(vetor, posicaoInicial, posicaoFinal, dadosDesempenho);
            break;
        }
        else {
            unsigned int pivo = particionarCrescente(vetor, posicaoInicial, posicaoFinal, dadosDesempenho);

            if (pivo - posicaoInicial < posicaoFinal - pivo) {
                quickSortCrescente(vetor, posicaoInicial, pivo - 1, tamanhoMinimo, dadosDesempenho);
                posicaoInicial = pivo + 1;
            }
            else {
                quickSortCrescente(vetor, pivo + 1, posicaoFinal, tamanhoMinimo, dadosDesempenho);
                posicaoFinal = pivo - 1;
            }
        }
    }

    return;
}

unsigned int QuickSortSelecao::particionarCrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho) {
    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[posicaoFinal];
    unsigned int indexPivo = posicaoInicial;

    for(int indexEsquerda = posicaoInicial; indexEsquerda < posicaoFinal; indexEsquerda++) {
        dadosDesempenho.quantidadeComparacoes++;
        if(vetor[indexEsquerda] <= pivo) {
            Registro conteudo = vetor[indexEsquerda];
            vetor[indexEsquerda] = vetor[indexPivo];
            vetor[indexPivo] = conteudo;

            dadosDesempenho.quantidadeAtribuicoes += 3;

            indexPivo++;
        }
    }
    
    Registro conteudo = vetor[indexPivo];
    vetor[indexPivo] = vetor[posicaoFinal];
    vetor[posicaoFinal] = conteudo;

    dadosDesempenho.quantidadeAtribuicoes += 3;

    return indexPivo;
}

void QuickSortSelecao::selecaoCrescente(Registro vetor[], const int posicaoInicial, const int posicaoFinal, DadosDesempenho& dadosDesempenho) {
    for(int i = posicaoInicial; i <= posicaoFinal; i++) {
        int indexMaiorElemento = i;
        for(int j = i + 1; j <= posicaoFinal; j++) {
            if(vetor[indexMaiorElemento] > vetor[j]) {
                indexMaiorElemento = j;
            }
        }

        Registro conteudo = vetor[i];
        vetor[i] = vetor[indexMaiorElemento];
        vetor[indexMaiorElemento] = conteudo;
    }


    return;
}


void QuickSortSelecao::quickSortDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho) {
    while(posicaoInicial < posicaoFinal) {
        if (posicaoFinal - posicaoInicial < tamanhoMinimo) {
            selecaoDecrescente(vetor, posicaoInicial, posicaoFinal, dadosDesempenho);
            break;
        }
        else {
            unsigned int pivo = particionarCrescente(vetor, posicaoInicial, posicaoFinal, dadosDesempenho);

            if (pivo - posicaoInicial < posicaoFinal - pivo) {
                quickSortCrescente(vetor, posicaoInicial, pivo - 1, tamanhoMinimo, dadosDesempenho);
                posicaoInicial = pivo + 1;
            }
            else {
                quickSortCrescente(vetor, pivo + 1, posicaoFinal, tamanhoMinimo, dadosDesempenho);
                posicaoFinal = pivo - 1;
            }
        }
    }

    return;
}

unsigned int QuickSortSelecao::particionarDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho) {
    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[posicaoFinal];
    unsigned int indexPivo = posicaoInicial;

    for(int indexEsquerda = posicaoInicial; indexEsquerda < posicaoFinal; indexEsquerda++) {
        dadosDesempenho.quantidadeComparacoes++;
        if(vetor[indexEsquerda] >= pivo) {
            Registro conteudo = vetor[indexEsquerda];
            vetor[indexEsquerda] = vetor[indexPivo];
            vetor[indexPivo] = conteudo;

            dadosDesempenho.quantidadeAtribuicoes += 3;

            indexPivo++;
        }
    }
    
    Registro conteudo = vetor[indexPivo];
    vetor[indexPivo] = vetor[posicaoFinal];
    vetor[posicaoFinal] = conteudo;

    dadosDesempenho.quantidadeAtribuicoes += 3;

    return indexPivo;
}

void QuickSortSelecao::selecaoDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho) {
    for(int i = posicaoInicial; i <= posicaoFinal; i++) {
        int indexMenor = i;
        for(int j = i + 1; j <= posicaoFinal; j++) {
            if(vetor[indexMenor] > vetor[j]) {
                indexMenor = j;
            }
        }
        
        Registro conteudo = vetor[i];
        vetor[i] = vetor[indexMenor];
        vetor[indexMenor] = conteudo;
    }

    return;
}

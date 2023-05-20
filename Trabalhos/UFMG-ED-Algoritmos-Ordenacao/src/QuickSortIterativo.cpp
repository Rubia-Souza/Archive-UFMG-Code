#include "QuickSortIterativo.h"

#include "Registro.h"
#include "DadosDesempenho.h"

QuickSortIterativo::QuickSortIterativo() {}

QuickSortIterativo::~QuickSortIterativo() {}

void QuickSortIterativo::ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    quickSortCrescente(vetor, 0, tamanho-1, dadosDesempenho);
    return;
}

void QuickSortIterativo::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    quickSortDecrescente(vetor, 0, tamanho-1, dadosDesempenho);
    return;
}

void QuickSortIterativo::quickSortCrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho) {
    int* pilha = new int[topo - base + 1];

    int indexPilha = 0;
    pilha[indexPilha] = base;

    indexPilha++;
    pilha[indexPilha] = topo;

    while(indexPilha >= 0) {
        topo = pilha[indexPilha];
        indexPilha--;

        base = pilha[indexPilha];
        indexPilha--;

        int indexPivo = particionarCrescente(vetor, base, topo, dadosDesempenho);

        if(indexPivo - 1 > base) {
            indexPilha++;
            pilha[indexPilha] = base;

            indexPilha++;
            pilha[indexPilha] = indexPivo - 1;
        }

        if(indexPivo + 1 < topo) {
            indexPilha++;
            pilha[indexPilha] = indexPivo + 1;

            indexPilha++;
            pilha[indexPilha] = topo;
        }
    }
    
    delete[] pilha;
    return;
}

int QuickSortIterativo::particionarCrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho) {
    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[topo];
    int indexPivo = base - 1;

    for(int indexBaixo = base; indexBaixo < topo; indexBaixo++) {
        dadosDesempenho.quantidadeComparacoes++;
        if(vetor[indexBaixo] <= pivo) {
            indexPivo++;

            Registro conteudo = vetor[indexPivo];
            vetor[indexPivo] = vetor[indexBaixo];
            vetor[indexBaixo] = conteudo;

            dadosDesempenho.quantidadeAtribuicoes += 3;
        }
    }

    indexPivo++;

    Registro conteudo = vetor[indexPivo];
    vetor[indexPivo] = vetor[topo];
    vetor[topo] = conteudo;

    dadosDesempenho.quantidadeAtribuicoes += 3;
    return indexPivo;
}

void QuickSortIterativo::quickSortDecrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho) {
    int* pilha = new int[topo - base + 1];

    int indexPilha = 0;
    pilha[indexPilha] = base;

    indexPilha++;
    pilha[indexPilha] = topo;

    while(indexPilha >= 0) {
        topo = pilha[indexPilha];
        indexPilha--;

        base = pilha[indexPilha];
        indexPilha--;

        int indexPivo = particionarDecrescente(vetor, base, topo, dadosDesempenho);

        if(indexPivo - 1 > base) {
            indexPilha++;
            pilha[indexPilha] = base;

            indexPilha++;
            pilha[indexPilha] = indexPivo - 1;
        }

        if(indexPivo + 1 < topo) {
            indexPilha++;
            pilha[indexPilha] = indexPivo + 1;

            indexPilha++;
            pilha[indexPilha] = topo;
        }
    }
    
    delete[] pilha;
    return;
}

int QuickSortIterativo::particionarDecrescente(Registro vetor[], int base, int topo, DadosDesempenho& dadosDesempenho) {
    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[topo];
    int indexPivo = base - 1;

    for(int indexBaixo = base; indexBaixo < topo; indexBaixo++) {
        dadosDesempenho.quantidadeComparacoes++;
        if(vetor[indexBaixo] >= pivo) {
            indexPivo++;

            Registro conteudo = vetor[indexPivo];
            vetor[indexPivo] = vetor[indexBaixo];
            vetor[indexBaixo] = conteudo;

            dadosDesempenho.quantidadeAtribuicoes += 3;
        }
    }

    indexPivo++;

    Registro conteudo = vetor[indexPivo];
    vetor[indexPivo] = vetor[topo];
    vetor[topo] = conteudo;

    dadosDesempenho.quantidadeAtribuicoes += 3;
    return indexPivo;
}

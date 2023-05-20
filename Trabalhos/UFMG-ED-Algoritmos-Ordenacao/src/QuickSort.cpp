#include "QuickSort.h"

#include "Registro.h"
#include "DadosDesempenho.h"

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

void QuickSort::ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    quickSortCrescente(vetor, 0, tamanho-1, dadosDesempenho);
    return;
}

void QuickSort::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    quickSortDecrescente(vetor, 0, tamanho-1, dadosDesempenho);
    return;
}

void QuickSort::quickSortCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, DadosDesempenho& dadosDesempenho) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita, dadosDesempenho);

    if(posicaoInicial < indexDireita) {
        quickSortCrescente(vetor, posicaoInicial, indexDireita, dadosDesempenho);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortCrescente(vetor, indexEsquerda, poiscaoFinal, dadosDesempenho);
    }

    return;
}

void QuickSort::particionarCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

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

void QuickSort::quickSortDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, DadosDesempenho& dadosDesempenho) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarDecrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita, dadosDesempenho);

    if(posicaoInicial < indexDireita) {
        quickSortDecrescente(vetor, posicaoInicial, indexDireita, dadosDesempenho);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortDecrescente(vetor, indexEsquerda, poiscaoFinal, dadosDesempenho);
    }

    return;
}

void QuickSort::particionarDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    dadosDesempenho.quantidadeAtribuicoes++;
    Registro pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

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
#include "QuickSort.h"

#include "Verbete.h"

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

void QuickSort::ordenarCrescente(Verbete* vetor[], const unsigned int tamanho) {
    if(tamanho <= 0) {
        return;
    }

    quickSortCrescente(vetor, 0, tamanho-1);
    return;
}

void QuickSort::ordenarDecrescente(Verbete* vetor[], const unsigned int tamanho) {
    if(tamanho <= 0) {
        return;
    }
    
    quickSortDecrescente(vetor, 0, tamanho-1);
    return;
}

void QuickSort::quickSortCrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita);

    if(posicaoInicial < indexDireita) {
        quickSortCrescente(vetor, posicaoInicial, indexDireita);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortCrescente(vetor, indexEsquerda, poiscaoFinal);
    }

    return;
}

void QuickSort::particionarCrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    Verbete* pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

    do {
        while(pivo->getPalavra() > vetor[*indexEsquerda]->getPalavra()) {
            (*indexEsquerda)++;
        }

        while(pivo->getPalavra() < vetor[*indexDireita]->getPalavra()) {
            (*indexDireita)--;
        }

        if(*indexEsquerda <= *indexDireita) {
            Verbete* trocaTemporaria = vetor[*indexEsquerda];
            vetor[*indexEsquerda] = vetor[*indexDireita];
            vetor[*indexDireita] = trocaTemporaria;

            (*indexEsquerda)++;
            (*indexDireita)--;
        }
    } while(*indexEsquerda <= *indexDireita);
    
    return;
}

void QuickSort::quickSortDecrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal) { 
    int indexEsquerda = 0;
    int indexDireita = 0;

    particionarDecrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita);

    if(posicaoInicial < indexDireita) {
        quickSortDecrescente(vetor, posicaoInicial, indexDireita);
    }

    if(indexEsquerda < poiscaoFinal) {
        quickSortDecrescente(vetor, indexEsquerda, poiscaoFinal);
    }

    return;
}

void QuickSort::particionarDecrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
    *indexEsquerda = posicaoInicial;
    *indexDireita = poiscaoFinal;

    Verbete* pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

    do {
        while(pivo->getPalavra() < vetor[*indexEsquerda]->getPalavra()) {
            (*indexEsquerda)++;
        }

        while(pivo->getPalavra() > vetor[*indexDireita]->getPalavra()) {
            (*indexDireita)--;
        }

        if(*indexEsquerda <= *indexDireita) {
            Verbete* trocaTemporaria = vetor[*indexEsquerda];
            vetor[*indexEsquerda] = vetor[*indexDireita];
            vetor[*indexDireita] = trocaTemporaria;

            (*indexEsquerda)++;
            (*indexDireita)--;
        }
    } while(*indexEsquerda <= *indexDireita);
    
    return;
}
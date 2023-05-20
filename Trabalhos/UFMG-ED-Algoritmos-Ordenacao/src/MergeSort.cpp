#include "MergeSort.h"

#include "Registro.h"
#include "DadosDesempenho.h"

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

void MergeSort::ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesemepnho) {
    mergeSortCrescente(vetor, 0, tamanho-1, dadosDesemepnho);
    return;
}

void MergeSort::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesemepnho) {
    mergeSortDecrescente(vetor, 0, tamanho-1, dadosDesemepnho);
    return;
}

void MergeSort::mergeSortCrescente(Registro vetor[], const unsigned int posicaoInicial, const unsigned int posicaoFinal, DadosDesempenho& dadosDesemepnho) {
    if(posicaoInicial >= posicaoFinal) {
        return;
    }

    unsigned int meio = posicaoInicial + (posicaoFinal - posicaoInicial) / 2;
    mergeSortCrescente(vetor, posicaoInicial, meio, dadosDesemepnho);
    mergeSortCrescente(vetor, meio + 1, posicaoFinal, dadosDesemepnho);
    mergeCrescente(vetor, posicaoInicial, meio, posicaoFinal, dadosDesemepnho);

    return;
}

void MergeSort::mergeCrescente(Registro vetor[], const int indexEsquerdo, const int indexMeio, const int indexDireito, DadosDesempenho& dadosDesemepnho) {
    const unsigned int tamanhoParteEsquerda = indexMeio - indexEsquerdo + 1;
    const unsigned int tamanhoParteDireita = indexDireito - indexMeio;

    Registro* parteEsquerda = new Registro[tamanhoParteEsquerda];
    Registro* parteDireita = new Registro[tamanhoParteDireita];

    for(unsigned int i = 0; i < tamanhoParteEsquerda; i++) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        parteEsquerda[i] = vetor[indexEsquerdo + i];
    }
    for(unsigned int i = 0; i < tamanhoParteDireita; i++) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        parteDireita[i] = vetor[indexMeio + i + 1];
    }

    unsigned int indexParteEsquerda = 0;
    unsigned int indexParteDireita = 0;
    
    unsigned int indexVetorFinal = indexEsquerdo;

    while(indexParteEsquerda < tamanhoParteEsquerda && indexParteDireita < tamanhoParteDireita) {
        dadosDesemepnho.quantidadeComparacoes++;
        if(parteEsquerda[indexParteEsquerda] <= parteDireita[indexParteDireita]) {
            dadosDesemepnho.quantidadeAtribuicoes++;
            vetor[indexVetorFinal] = parteEsquerda[indexParteEsquerda];
            indexParteEsquerda++;
        }
        else {
            dadosDesemepnho.quantidadeAtribuicoes++;
            vetor[indexVetorFinal] = parteDireita[indexParteDireita];
            indexParteDireita++;
        }

        indexVetorFinal++;
    }

    while(indexParteEsquerda < tamanhoParteEsquerda) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        vetor[indexVetorFinal] = parteEsquerda[indexParteEsquerda];
        indexParteEsquerda++;
        indexVetorFinal++;
    }

    while(indexParteDireita < tamanhoParteDireita) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        vetor[indexVetorFinal] = parteDireita[indexParteDireita];
        indexParteDireita++;
        indexVetorFinal++;
    }

    delete[] parteEsquerda;
    delete[] parteDireita;

    return;
}

void MergeSort::mergeSortDecrescente(Registro vetor[], const unsigned int posicaoInicial, const unsigned int posicaoFinal, DadosDesempenho& dadosDesemepnho) {
    if(posicaoInicial >= posicaoFinal) {
        return;
    }

    unsigned int meio = posicaoInicial + (posicaoFinal - posicaoInicial) / 2;
    mergeSortDecrescente(vetor, posicaoInicial, meio, dadosDesemepnho);
    mergeSortDecrescente(vetor, meio + 1, posicaoFinal, dadosDesemepnho);
    mergeDecrescente(vetor, posicaoInicial, meio, posicaoFinal, dadosDesemepnho);

    return;
}

void MergeSort::mergeDecrescente(Registro vetor[], const int indexEsquerdo, const int indexMeio, const int indexDireito, DadosDesempenho& dadosDesemepnho) {
    const unsigned int tamanhoParteEsquerda = indexMeio - indexEsquerdo + 1;
    const unsigned int tamanhoParteDireita = indexDireito - indexMeio;

    Registro* parteEsquerda = new Registro[tamanhoParteEsquerda];
    Registro* parteDireita = new Registro[tamanhoParteDireita];

    for(unsigned int i = 0; i < tamanhoParteEsquerda; i++) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        parteEsquerda[i] = vetor[indexEsquerdo + i];
    }
    for(unsigned int i = 0; i < tamanhoParteDireita; i++) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        parteDireita[i] = vetor[indexMeio + i + 1];
    }

    unsigned int indexParteEsquerda = 0;
    unsigned int indexParteDireita = 0;
    
    unsigned int indexVetorFinal = indexEsquerdo;

    while(indexParteEsquerda < tamanhoParteEsquerda && indexParteDireita < tamanhoParteDireita) {
        dadosDesemepnho.quantidadeComparacoes++;
        if(parteEsquerda[indexParteEsquerda] >= parteDireita[indexParteDireita]) {
            dadosDesemepnho.quantidadeAtribuicoes++;
            vetor[indexVetorFinal] = parteEsquerda[indexParteEsquerda];
            indexParteEsquerda++;
        }
        else {
            dadosDesemepnho.quantidadeAtribuicoes++;
            vetor[indexVetorFinal] = parteDireita[indexParteDireita];
            indexParteDireita++;
        }

        indexVetorFinal++;
    }

    while(indexParteEsquerda < tamanhoParteEsquerda) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        vetor[indexVetorFinal] = parteEsquerda[indexParteEsquerda];
        indexParteEsquerda++;
        indexVetorFinal++;
    }

    while(indexParteDireita < tamanhoParteDireita) {
        dadosDesemepnho.quantidadeAtribuicoes++;
        vetor[indexVetorFinal] = parteDireita[indexParteDireita];
        indexParteDireita++;
        indexVetorFinal++;
    }

    delete[] parteEsquerda;
    delete[] parteDireita;

    return;
}

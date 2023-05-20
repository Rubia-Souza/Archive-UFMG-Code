#include "HeapSort.h"

#include "Registro.h"
#include "DadosDesempenho.h"

HeapSort::HeapSort() {}

HeapSort::~HeapSort() {}

void HeapSort::ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    for(int i = (tamanho / 2 - 1); i >= 0; i--) {
        criarHeapCrescente(vetor, tamanho, i, dadosDesempenho);
    }

    for(int i = (tamanho - 1); i >= 0; i--) {
        Registro conteudo = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = conteudo;

        dadosDesempenho.quantidadeAtribuicoes += 3;

        criarHeapCrescente(vetor, i, 0, dadosDesempenho);
    }

    return;
}

void HeapSort::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    for(int i = (tamanho / 2 - 1); i >= 0; i--) {
        criarHeapDecrescente(vetor, tamanho, i, dadosDesempenho);
    }

    for(int i = (tamanho - 1); i >= 0; i--) {
        Registro conteudo = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = conteudo;

        dadosDesempenho.quantidadeAtribuicoes += 3;

        criarHeapDecrescente(vetor, i, 0, dadosDesempenho);
    }

    return;
}

void HeapSort::criarHeapCrescente(Registro vetor[], int tamanho, int indexAtual, DadosDesempenho& dadosDesempenho) {
    int nodoPai = indexAtual;

    int nodoEsquerdo = (2 * indexAtual) + 1;
    int nodoDireito = (2 * indexAtual) + 2;

    dadosDesempenho.quantidadeComparacoes++;
    if(nodoEsquerdo < tamanho && vetor[nodoEsquerdo] > vetor[nodoPai]) {
        nodoPai = nodoEsquerdo;
    }

    dadosDesempenho.quantidadeComparacoes++;
    if(nodoDireito < tamanho && vetor[nodoDireito] > vetor[nodoPai]) {
        nodoPai = nodoDireito;
    }

    if(nodoPai != indexAtual) {
        Registro conteudo = vetor[indexAtual];
        vetor[indexAtual] = vetor[nodoPai];
        vetor[nodoPai] = conteudo;

        dadosDesempenho.quantidadeAtribuicoes += 3;

        criarHeapCrescente(vetor, tamanho, nodoPai, dadosDesempenho);
    }
    
    return;
}

void HeapSort::criarHeapDecrescente(Registro vetor[], int tamanho, int indexAtual, DadosDesempenho& dadosDesempenho) {
    int nodoPai = indexAtual;

    int nodoEsquerdo = (2 * indexAtual) + 1;
    int nodoDireito = (2 * indexAtual) + 2;

    dadosDesempenho.quantidadeComparacoes++;
    if(nodoEsquerdo < tamanho && vetor[nodoEsquerdo] < vetor[nodoPai]) {
        nodoPai = nodoEsquerdo;
    }

    dadosDesempenho.quantidadeComparacoes++;
    if(nodoDireito < tamanho && vetor[nodoDireito] < vetor[nodoPai]) {
        nodoPai = nodoDireito;
    }

    if(nodoPai != indexAtual) {
        Registro conteudo = vetor[indexAtual];
        vetor[indexAtual] = vetor[nodoPai];
        vetor[nodoPai] = conteudo;

        dadosDesempenho.quantidadeAtribuicoes += 3;

        criarHeapDecrescente(vetor, tamanho, nodoPai, dadosDesempenho);
    }
    
    return;
}


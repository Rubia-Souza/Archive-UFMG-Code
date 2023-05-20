#include "QuickSortIterativoInteligente.h"

#include "Pilha.h"
#include "Registro.h"
#include "FaixaOrdenacao.h"
#include "DadosDesempenho.h"

QuickSortIterativoInteligente::QuickSortIterativoInteligente() {}

QuickSortIterativoInteligente::~QuickSortIterativoInteligente() {}

void QuickSortIterativoInteligente::ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    Pilha pilha;

    int posicaoInicial = 0;
    int posicaoFinal = tamanho - 1;

    FaixaOrdencao faixaOrdenacao;
    faixaOrdenacao.fim = posicaoFinal;
    faixaOrdenacao.inicio = posicaoInicial;

    pilha.empilhar(faixaOrdenacao);

    int indexEsquerdo = 0;
    int indexDireito = 0;
    do {
        bool haElementosParaProcessar = posicaoFinal > posicaoInicial;
        if(haElementosParaProcessar) {
            particionarCrescente(vetor, posicaoInicial, posicaoFinal, &indexEsquerdo, &indexDireito, dadosDesempenho);

            int tamanhoParticaoEsquerda = indexDireito - posicaoInicial;
            int tamanhoParticaoDireita = posicaoFinal - indexEsquerdo;
            if (tamanhoParticaoEsquerda > tamanhoParticaoDireita) {
                faixaOrdenacao.fim = indexDireito;
                faixaOrdenacao.inicio = posicaoInicial;

                pilha.empilhar(faixaOrdenacao);

                posicaoInicial = indexEsquerdo;
            }
            else {
                faixaOrdenacao.inicio = indexEsquerdo;
                faixaOrdenacao.fim = posicaoFinal;

                pilha.empilhar(faixaOrdenacao);

                posicaoFinal = indexDireito;
            }
        }
        else {
            faixaOrdenacao = *pilha.desempilhar();

            posicaoFinal = faixaOrdenacao.fim;
            posicaoInicial = faixaOrdenacao.inicio;
        } 
    } while(!pilha.estaVazia());

    return;
}

void QuickSortIterativoInteligente::ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho) {
    Pilha pilha;

    int posicaoInicial = 0;
    int posicaoFinal = tamanho - 1;

    FaixaOrdencao faixaOrdenacao;
    faixaOrdenacao.fim = posicaoFinal;
    faixaOrdenacao.inicio = posicaoInicial;

    pilha.empilhar(faixaOrdenacao);

    int indexEsquerdo = 0;
    int indexDireito = 0;
    do {
        bool haElementosParaProcessar = posicaoFinal > posicaoInicial;
        if(haElementosParaProcessar) {
            particionarDecrescente(vetor, posicaoInicial, posicaoFinal, &indexEsquerdo, &indexDireito, dadosDesempenho);

            int tamanhoParticaoEsquerda = indexDireito - posicaoInicial;
            int tamanhoParticaoDireita = posicaoFinal - indexEsquerdo;
            if (tamanhoParticaoEsquerda > tamanhoParticaoDireita) {
                faixaOrdenacao.fim = indexDireito;
                faixaOrdenacao.inicio = posicaoInicial;

                pilha.empilhar(faixaOrdenacao);

                posicaoInicial = indexEsquerdo;
            }
            else {
                faixaOrdenacao.inicio = indexEsquerdo;
                faixaOrdenacao.fim = posicaoFinal;

                pilha.empilhar(faixaOrdenacao);

                posicaoFinal = indexDireito;
            }
        }
        else {
            faixaOrdenacao = *pilha.desempilhar();
            
            posicaoFinal = faixaOrdenacao.fim;
            posicaoInicial = faixaOrdenacao.inicio;
        } 
    } while(!pilha.estaVazia());

    return;
}

void QuickSortIterativoInteligente::particionarCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho) {
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

void QuickSortIterativoInteligente::particionarDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho) {
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

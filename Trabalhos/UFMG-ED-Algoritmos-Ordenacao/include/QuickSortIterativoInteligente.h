#ifndef QUICK_SORT_ITERATIVO_INTELIGENTE_H
#define QUICK_SORT_ITERATIVO_INTELIGENTE_H

#include "Pilha.h"
#include "Registro.h"
#include "FaixaOrdenacao.h"
#include "DadosDesempenho.h"

class QuickSortIterativoInteligente {
    private:
        QuickSortIterativoInteligente();

    public:
        virtual ~QuickSortIterativoInteligente();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Quick Sort Iterativo Inteligente
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Quick Sort Iterativo Inteligente
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);
    
    private:
        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static void particionarCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho);
        
        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static void particionarDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, DadosDesempenho& dadosDesempenho);
};

#endif

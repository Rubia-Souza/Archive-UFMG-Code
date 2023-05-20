#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Verbete.h"

class QuickSort {
    private:
        QuickSort();

    public:
        virtual ~QuickSort();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Quick Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         */
        static void ordenarCrescente(Verbete* vetor[], const unsigned int tamanho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Quick Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         */
        static void ordenarDecrescente(Verbete* vetor[], const unsigned int tamanho);
    
    private:
        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         */
        static void quickSortCrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         */
        static void particionarCrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita);

        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         */
        static void quickSortDecrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         */
        static void particionarDecrescente(Verbete* vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita);
};

#endif

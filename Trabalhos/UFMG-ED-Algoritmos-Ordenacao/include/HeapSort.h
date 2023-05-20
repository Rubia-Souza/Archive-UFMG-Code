#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include "Registro.h"
#include "DadosDesempenho.h"

class HeapSort {
    private:
        HeapSort();

    public:
        virtual ~HeapSort();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Heap Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Heap Sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, DadosDesempenho& dadosDesempenho);
    
    private:
        /**
         * @brief Ajusta o vetor para ter a estrutura de um heap crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor
         * @param indexAtual É o index do ponto atual a ser ajustado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void criarHeapCrescente(Registro vetor[], int tamanho, int indexAtual, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Ajusta o vetor para ter a estrutura de um heap decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor
         * @param indexAtual É o index do ponto atual a ser ajustado
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void criarHeapDecrescente(Registro vetor[], int tamanho, int indexAtual, DadosDesempenho& dadosDesempenho);
};

#endif

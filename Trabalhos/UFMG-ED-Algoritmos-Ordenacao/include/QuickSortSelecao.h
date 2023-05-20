#ifndef QUICK_SORT_SELECAO_H
#define QUICK_SORT_SELECAO_H

#include "Registro.h"
#include "DadosDesempenho.h"

class QuickSortSelecao {
    private:
        QuickSortSelecao();

    public:
        virtual ~QuickSortSelecao();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Quick Sort com Seleção
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param tamanhoMinimo É o tamanho mínimo que irá iniciar o algoritmo de ordenação por Seleção
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Quick Sort com Seleção
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param tamanhoMinimo É o tamanho mínimo que irá iniciar o algoritmo de ordenação por Seleção
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho);
    
    private:
        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param tamanhoMinimo É o tamanho mínimo que irá iniciar o algoritmo de ordenação por Seleção
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortCrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param posicaoFinal É o ponto final do vetor atual 
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static unsigned int particionarCrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a ordenação crescente do vetor por meio do algoritmo de ordenação por Seleção
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void selecaoCrescente(Registro vetor[], const int posicaoInicial, const int posicaoFinal, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param tamanhoMinimo É o tamanho mínimo que irá iniciar o algoritmo de ordenação por Seleção
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, const int tamanhoMinimo, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param posicaoFinal É o ponto final do vetor atual 
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static unsigned int particionarDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a ordenação decrescente do vetor por meio do algoritmo de ordenação por Seleção
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void selecaoDecrescente(Registro vetor[], int posicaoInicial, int posicaoFinal, DadosDesempenho& dadosDesempenho);
};

#endif

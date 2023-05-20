#ifndef QUICK_SORT_MEDIANA_H
#define QUICK_SORT_MEDIANA_H

#include <cmath>

#include "Utils.h"
#include "Selecao.h"
#include "DadosDesempenho.h"
#include "Registro.h"

class QuickSortMediana {
    private:
        QuickSortMediana();

    public:
        virtual ~QuickSortMediana();

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Quick Sort com Mediana
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarCrescente(Registro vetor[], const unsigned int tamanho, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Quick Sort com Mediana
         * 
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void ordenarDecrescente(Registro vetor[], const unsigned int tamanho, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);
    
    private:
        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem crescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static void particionarCrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Seleciona a mediana entre elementos aleatórios diferentes no vetor
         * 
         * @param vetor É o vetor que será ordenado e terá os elementos selecionados
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         * @return Registro É o pivo selecionado como mediana dos valores aleatórios escolhidos
         */
        static Registro selecionarPivo(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza as chamadas recursivas do quick sort
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo
         */
        static void quickSortDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);

        /**
         * @brief Realiza a partição da faixa atual do vetor com base no pivo em ordem decrescente
         * 
         * @param vetor É o vetor que será ordenado
         * @param posicaoInicial É o ponto inicial do vetor atual
         * @param poiscaoFinal É o ponto final do vetor atual 
         * @param indexEsquerda É o index que percorre o vetor a esquerda do pivô
         * @param indexDireita É o index que percorre o vetor a direita do pivô
         * @param quantidadePossiveisPivos É a quantidade de pivos que serão selecionados aleatoriamente para formar a mediana
         * @param dadosDesempenho É o objeto que irá armazenar os dados de desempenho da execução do algoritmo 
         */
        static void particionarDecrescente(Registro vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita, const int quantidadePossiveisPivos, DadosDesempenho& dadosDesempenho);
};

#endif

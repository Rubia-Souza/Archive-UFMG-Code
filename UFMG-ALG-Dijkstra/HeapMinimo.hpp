#ifndef HEAP_MINIMO_HPP
#define HEAP_MINIMO_HPP

#include <vector>

#include "Vertice.hpp"

class HeapMinimo {
    private:
        unsigned int tamanhoMaximo = 0;
        unsigned int tamanhoOcupado = 0;
        std::vector<std::pair<Vertice*, unsigned int>>* distancias = nullptr;

    public:
        /**
         * @brief Cria um novo Objeto de Heap Mínimo
         * 
         * @param tamanhoMaximo É a quantidade máxima de objetos que podem ser colocados no heap
         */
        HeapMinimo(const unsigned int tamanhoMaximo);

        /**
         * @brief Destroi o objeto do Heap Mínimo
         * 
         */
        ~HeapMinimo();

        /**
         * @brief Adiciona um objeto ao Heap Mínimo
         * 
         * @details Ao adicionar um vértice com uma distância menor, o heap é ajustado automaticamente para posicionar corretamente o novo vértice
         * @throw Lança uma exceção caso o Heap já esteja totalmente preenchido
         * 
         * @param vertice É o Vértice que será adicionado ao Heap
         * @param distancia É a menor distância calculada até agora do Vértice adicionado até a origem
         */
        void adicionar(Vertice* vertice, const unsigned int distancia);

        /**
         * @brief Atualiza um valor de distância de um Vértice no heap
         * 
         * @details Ao atualizar um vértice com uma distância menor, o heap é ajustado automaticamente para posicionar corretamente o novo vértice
         * @throw Lança uma exceção caso a distância atualizada seja maior ou caso o heap esteja vazio
         * 
         * @param vertice É o vértice que terá o valor atualizado
         * @param novaDistancia É a nova distância estimada do Vértice atualizado até a origem
         */
        void atualizar(Vertice* vertice, const unsigned int novaDistancia);

        /**
         * @brief Remove o Vértice com menor distância até a origem e o retorna
         * 
         * @details Ao remover a raiz, o heap é ajustado automaticamente para posicionar o objeto de menor distância dentre os restantes nessa posição
         * @throw Lança uma exceção ao tentar remover um objeto com o heap vazio
         * 
         * @return Vertice* É o Vértice com a menor distância até a origem presente no heap
         */
        Vertice* popMenor();

        /**
         * @brief Verifica se o heap está vazio
         * 
         * @return true Se o heap estiver vazio
         * @return false Se o heap não estiver vazio
         */
        bool estaVazio() const;

        /**
         * @brief Imprime as informações do heap na saida padrão [DEBUG]
         * 
         */
        void printHeap();
    
    private:
        /**
         * @brief Atualiza recursivamente a posição do objeto no index informado para encontrar aquela em que seus dois filhos são maiores que ele e ele é maior que seu pai
         * 
         * @param index É o index do objeto que será ajustado no heap
         */
        void ajustarHeap(const int index);

        /**
         * @brief Retorna o pai de uma determinada posição
         * 
         * @param index É a posição que será obtido o pai
         * @return int É o index do pai para a posição informada
         */
        int getPai(const int index) const;

        /**
         * @brief Retorna o filho a direita de uma determinada posição
         * 
         * @param index É a posição que será obtido o filho a direita
         * @return int É o index do filho a direita para a posição informada
         */
        int getFilhoDireito(const int index) const;

        /**
         * @brief Retorna o filho a esquerda de uma determinada posição
         * 
         * @param index É a posição que será obtido o filho a esquerda
         * @return int É o index do filho a esquerda para a posição informada
         */
        int getFilhoEsquerdo(const int index) const;
};

#endif
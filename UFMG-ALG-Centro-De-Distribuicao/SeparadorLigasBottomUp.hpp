#ifndef SEPARADOR_LIGAS_BOTTOM_UP_HPP
#define SEPARADOR_LIGAS_BOTTOM_UP_HPP

#include <vector>

#include "SeparadorLigas.hpp"

class SeparadorLigasBottomUp : public SeparadorLigas {
    public:
        /**
         * @brief Cria uma nova instância da classe SeparadorLigasBottomUp
         * 
         * @details Aplica a solução para a separação de ligas de forma Bottom Up
         * Ou seja, ela parte dos problemas menores e vai construindo a solução
         * armazenado os resultados anteriores até chegar na problema solicitado
         */
        SeparadorLigasBottomUp();

        /**
         * @brief Cria uma nova instância da classe SeparadorLigasBottomUp
         */
        virtual ~SeparadorLigasBottomUp();

        /**
         * @brief Retorna a menor quantidade de ligas que podem ser utilizadas para cumprir a demanda especificada dentre os tamanhos presentes no vetor de ligas metálicas
         * 
         * @param demanda É a demanda que deve ser atendida pela ligas disponíveis no estoque (Capacidade)
         * @param ligasMetalicas São as ligas que estão disponíveis no estoque e serão enviadas para o cliente (Itens)
         * @return unsigned int É a menor quantidade de ligas que podem ser selecionadas para atender a demanda especificada
         */
        virtual unsigned int Separar(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas) const override;
};

#endif
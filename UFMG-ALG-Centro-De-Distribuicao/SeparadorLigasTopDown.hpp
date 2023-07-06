#ifndef SEPARADOR_LIGAS_TOP_DOWN_HPP
#define SEPARADOR_LIGAS_TOP_DOWN_HPP

#include <vector>

#include "SeparadorLigas.hpp"

class SeparadorLigasTopDown : public SeparadorLigas {
    public:
        /**
         * @brief Cria uma nova instância da classe SeparadorLigasTopDown
         * 
         * @details Aplica a solução de forma Top Down. Ou seja, ele parte do problema original
         * e realiza diversas chamadas recursivas para resolver subproblemas. Cada subproblema
         * resolvido tem sua resposta armazenada para que, caso ele apareca novamente, não seja necessário
         * computá-lo de novo. Uma vez que todas chamadas recursivas finalizam o problema original é
         * resolvido.
         */
        SeparadorLigasTopDown();

        /**
         * @brief Cria uma nova instância da classe SeparadorLigasTopDown
         */
        virtual ~SeparadorLigasTopDown();

        /**
         * @brief Retorna a menor quantidade de ligas que podem ser utilizadas para cumprir a demanda especificada dentre os tamanhos presentes no vetor de ligas metálicas
         * 
         * @param demanda É a demanda que deve ser atendida pela ligas disponíveis no estoque (Capacidade)
         * @param ligasMetalicas São as ligas que estão disponíveis no estoque e serão enviadas para o cliente (Itens)
         * @return unsigned int É a menor quantidade de ligas que podem ser selecionadas para atender a demanda especificada
         */
        virtual unsigned int Separar(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas) const override;
    
    private:
        /**
         * @brief Resolve um subproblema de forma recursiva, encontrando a menor quantidade de ligas que podem ser aplicadas para a demanda informada dentre os tamanhos presentes no vetor de ligas metálicas
         * 
         * @details O caso base ocorre quando a demanda possui valor 0. Assim, nenhum liga métalica é necessária para atender a demanda
         * 
         * @param demanda É a demanda do subproblema atual que deve ser atendida pela ligas disponíveis no estoque (Capacidade)
         * @param ligasMetalicas São as ligas que estão disponíveis no estoque e serão enviadas para o cliente (Itens)
         * @param registroResultados É o vetor que armazena os resultados dos subproblemas que foram solucionados até então. Como as ligas disponíveis são sepre as mesmas para uma chamada, um subproblema é identificado pela demanda
         * @return unsigned int É a menor quantidade de ligas que podem ser selecionadas para atender a demanda especificada no subproblema atual
         */
        unsigned int SepararRecursivo(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas, std::vector<unsigned int>& registroResultados) const;
};

#endif
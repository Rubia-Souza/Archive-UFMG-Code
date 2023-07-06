#ifndef SEPARADOR_LIGAS_HPP
#define SEPARADOR_LIGAS_HPP

#include <vector>

class SeparadorLigas {
    protected:
        /**
         * @brief Cria uma nova instância da classe SeparadorLigas
         */
        SeparadorLigas();

    public:
        /**
         * @brief Destroi uma instância da classe Separador Ligas
         */
        virtual ~SeparadorLigas();

        /**
         * @brief Retorna a menor quantidade de ligas que podem ser utilizadas para cumprir a demanda especificada dentre os tamanhos presentes no vetor de ligas metálicas
         * 
         * @param demanda É a demanda que deve ser atendida pela ligas disponíveis no estoque (Capacidade)
         * @param ligasMetalicas São as ligas que estão disponíveis no estoque e serão enviadas para o cliente (Itens)
         * @return unsigned int É a menor quantidade de ligas que podem ser selecionadas para atender a demanda especificada
         */
        virtual unsigned int Separar(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas) const = 0;
};

#endif
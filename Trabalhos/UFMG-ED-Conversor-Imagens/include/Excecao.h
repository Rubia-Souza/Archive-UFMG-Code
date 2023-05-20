#ifndef EXCECOES_H
#define EXCECOES_H

#include <string>
#include <stdexcept>

class Excecao : public std::runtime_error {
    public:
        /**
         * @brief Cria o objeto de Excecao
         * 
         * @details Representa um erro de execução durante o programa
         * 
         * @param mensagem É a mesagem que a Excecao contem
         */
        Excecao(const std::string mensagem);

        /**
             * @brief Destroi a exceção Excecao
             * 
             */
        virtual ~Excecao();
};

#endif

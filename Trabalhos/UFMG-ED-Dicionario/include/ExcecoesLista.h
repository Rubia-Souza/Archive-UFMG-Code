#ifndef EXCECOES_LISTA_H
#define EXCECOES_LISTA_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesLista {
    class IndexInvalidoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de IndexInvalidoException
             * 
             * @details Representa um erro ao informar um index inválido para a lista
             * 
             * @param mensagem É a mesagem que a IndexInvalidoException contem
             */
            IndexInvalidoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção IndexInvalidoException
             * 
             */
            virtual ~IndexInvalidoException();
    };
}

#endif

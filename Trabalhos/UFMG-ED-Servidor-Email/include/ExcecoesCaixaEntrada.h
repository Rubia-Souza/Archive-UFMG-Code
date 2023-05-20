#ifndef EXCECOES_CAIXA_ENTRADA_H
#define EXCECOES_CAIXA_ENTRADA_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesCaixaEntrada {
    class AcessoCaixaEntradaVaziaException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de AcessoCaixaEntradaVaziaException
             * 
             * @details Representa um erro ao tentar acessar a caixa de entrada vazia
             * 
             * @param mensagem É a mesagem que a AcessoCaixaEntradaVaziaException contem
             */
            AcessoCaixaEntradaVaziaException(const std::string mensagem);

            /**
             * @brief Destroi a exceção AcessoCaixaEntradaVaziaException
             * 
             */
            virtual ~AcessoCaixaEntradaVaziaException();
    };
}

#endif

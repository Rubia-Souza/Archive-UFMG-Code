#ifndef EXCECOES_PGM_READER_H
#define EXCECOES_PGM_READER_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesPGMWriter {
    class CriacaoArquivoSaidaException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de CriacaoArquivoSaidaException
             * 
             * @details Representa um erro ao não criar a imagem de saida PGM
             * 
             * @param mensagem É a mesagem que a CriacaoArquivoSaidaException contem
             */
            CriacaoArquivoSaidaException(const std::string mensagem);

            /**
             * @brief Destroi a exceção CriacaoArquivoSaidaException
             * 
             */
            virtual ~CriacaoArquivoSaidaException();
    };
}

#endif

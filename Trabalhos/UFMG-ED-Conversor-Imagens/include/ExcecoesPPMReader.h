#ifndef EXCECOES_PPM_READER_H
#define EXCECOES_PPM_READER_H

#include <string>
#include <stdexcept>

#include "Excecao.h"

namespace ExcecoesPPMReader {
    class LeituraException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de LeituraException
             * 
             * @details Representa um erro durante a leitura da imagem PPM
             * 
             * @param mensagem É a mesagem que a LeituraException contem
             */
            LeituraException(const std::string mensagem);

            /**
             * @brief Destroi a exceção LeituraException
             * 
             */
            virtual ~LeituraException();
    };

    class FormatoInvalidoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de FormatoInvalidoException
             * 
             * @details Representa um erro ao informar uma imagem de entrada que não é PPM
             * 
             * @param mensagem É a mesagem que a FormatoInvalidoException contem
             */
            FormatoInvalidoException(const std::string mensagem);
            
            /**
             * @brief Destroi a exceção FormatoInvalidoException
             * 
             */
            virtual ~FormatoInvalidoException();
    };

    class FalhaAbrirArquivoException : public Excecao {
        public:
            /**
             * @brief Cria o objeto de FalhaAbrirArquivoException
             * 
             * @details Representa um erro ao abrir a imagem que será lida
             * 
             * @param mensagem É a mesagem que a FalhaAbrirArquivoException contem
             */
            FalhaAbrirArquivoException(const std::string mensagem);

            /**
             * @brief Destroi a exceção FalhaAbrirArquivoException
             * 
             */
            virtual ~FalhaAbrirArquivoException();
    };
}

#endif

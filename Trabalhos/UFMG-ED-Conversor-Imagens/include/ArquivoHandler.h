#ifndef ARQUIVO_HANDLER_H
#define ARQUIVO_HANDLER_H

#include <string>

class ArquivoHandler {
    private:
        std::string caminho = "";

    public:
        /**
         * @brief Cria objeto Arquivo Handler
         * 
         * @param caminho Caminho do arquivo
         */
        ArquivoHandler(const std::string caminho);

        /**
         * @brief Destroi objeto Arquivo Handler
         * 
         */
        virtual ~ArquivoHandler();

        /**
         * @brief Difine o Caminho do arquivo
         * 
         * @param caminho Caminho do arquivo
         */
        void setCaminho(const std::string caminho);

        /**
         * @brief Busca o Caminho do arquivo
         * 
         * @return String do Caminho do arquivo
         */
        std::string getCaminho() const;
};

#endif

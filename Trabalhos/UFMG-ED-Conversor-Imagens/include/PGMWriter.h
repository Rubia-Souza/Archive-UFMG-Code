#ifndef PGM_WRITER_H
#define PGM_WRITER_H

#include <string>
#include <fstream>
#include <iostream>

#include "ArquivoHandler.h"
#include "Imagem.h"

class PGMWriter : public ArquivoHandler {
    private:
        static const std::string MENSAGEM_ERRO_CRIAR_ARQUIVO;

    public:
        /**
         * @brief Cria um objeto PGMWriter
         * 
         * @param caminho É o caminho onde o arquivo será escrito
         */
        PGMWriter(const std::string caminho);

        /**
         * @brief Destroi o objeto PGMWriter
         * 
         */
        virtual ~PGMWriter();

        /**
         * @brief Gera um arquivo de imagem PGM com os dados informados
         * 
         * @param imagem É a imagem que será escrita como arqivo PGM
         */
        void criarImagem(const Imagem& imagem) const;

    private:
        /**
         * @brief Escreve o tipo da imagem no cabeçalho do arquivo
         * 
         * @param arquivo É o arquivo onde a informação será gravada
         * @param imagem É a imagem que contem as informações de referência
         */
        void escreverTipoImagem(std::ofstream* arquivo, const Imagem& imagem) const;

        /**
         * @brief Escreve as dimensões da imagem no cabeçalho do arquivo
         * 
         * @param arquivo É o arquivo onde a informação será gravada
         * @param imagem É a imagem que contem as informações de referência
         */
        void escreverDimensoes(std::ofstream* arquivo, const Imagem& imagem) const;

        /**
         * @brief Escreve o tom maximo dos pixels na imagem no cabeçalho do arquivo
         * 
         * @param arquivo É o arquivo onde a informação será gravada
         * @param imagem É a imagem que contem as informações de referência
         */
        void escreverQuantidadeTons(std::ofstream* arquivo, const Imagem& imagem) const;

        /**
         * @brief Escreve a lista de pixels da imagem n arquivo gerado
         * 
         * @param arquivo É o arquivo onde a informação será gravada
         * @param imagem É a imagem que contem as informações de referência
         */
        void escreverPixels(std::ofstream* arquivo, const Imagem& imagem) const;
};

#endif

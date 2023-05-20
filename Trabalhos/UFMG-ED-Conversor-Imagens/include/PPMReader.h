#ifndef PGM_READER_H
#define PGM_READER_H

#include <string>
#include <fstream>
#include <iostream>

#include "ArquivoHandler.h"
#include "Imagem.h"
#include "PPMPixel.h"

class PPMReader : public ArquivoHandler {
    private:
        static const std::string MENSAGEM_ERRO_AO_ABRIR_ARQUIVO;
        static const std::string MENSAGEM_ERRO_FORMATO_INVALIDO;
        static const std::string MENSAGEM_ERRO_LEITURA_FALHOU;

    public:
        /**
         * @brief Cria um objeto do tipo PPMReader
         * 
         * @param caminho É o caminho do arquivo que será lido
         */
        PPMReader(const std::string caminho);

        /**
         * @brief Destroi o objeto PPMReader
         * 
         */
        virtual ~PPMReader();

        /**
         * @brief Le a imagem a partir do caminho informado
         * 
         * @return Imagem* é imagem lida do arquivo
         */
        Imagem* lerImagem() const;
    
    private:
        /**
         * @brief Extrai o tipo ASCII da Imagem a partir do cabeçalho
         * 
         * @param arquivo É o arquivo que será lido
         * @return std::string É o tipo ASCII da Imagem presente no cabeçalho
         */
        std::string getTipoImagem(std::fstream& arquivo) const;

        /**
         * @brief Extrai as Dimensoes da Imagem a partir do cabeçalho
         * 
         * @param arquivo É o arquivo que será lido
         * @return std::pair<unsigned int, unsigned int> São as dimensões da imagem
         */
        std::pair<unsigned int, unsigned int> getDimensoes(std::fstream& arquivo) const;

        /**
         * @brief Extrai o Tom Máximo dos piexls da Imagem a partir do cabeçalho
         * 
         * @param arquivo É o arquivo que será lido
         * @return unsigned int é o tom máximo que os pixels da imagem podem ter
         */
        unsigned int getQuantidadeTons(std::fstream& arquivo) const;

        /**
         * @brief Extrai os Pixels da Imagem
         * 
         * @param arquivo É o arquivo que será lido
         * @param tomMaximo É o maior tom que o pixel pode ter
         * @return PPMPixel* É o pixel extraido da imagem
         */
        PPMPixel* getPixels(std::fstream& arquivo, const short tomMaximo) const;
};

#endif

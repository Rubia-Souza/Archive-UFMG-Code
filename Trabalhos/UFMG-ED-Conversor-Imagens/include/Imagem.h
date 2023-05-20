#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>

#include "Lista.h"
#include "Pixel.h"

class Imagem {
    private:
        std::string tipo = "";
        unsigned int altura = 0;
        unsigned int largura = 0;
        short quatidadeTons = 0;
        Lista<Pixel*>* pixels;

    public:
        /**
         * @brief Cria o objeto Imagem
         * 
         */
        Imagem();

        /**
         * @brief Cria o objeto Imagem
         * 
         * @param tipo 
         * @param altura 
         * @param largura 
         * @param quatidadeTons 
         */
        Imagem(const std::string tipo, const unsigned int altura, const unsigned int largura, const short quatidadeTons);

        /**
         * @brief Destroi o objeto de Imagem
         * 
         */
        virtual ~Imagem();

        /**
         * @brief Define o atributo tipo
         * 
         * @param tipo É o tipo ASCII da imagem
         */
        void setTipo(const std::string tipo);

        /**
         * @brief Retorna o atributo tipo
         * 
         * @return string É o tipo ASCII da imagem
         */
        std::string getTipo() const;

        /**
         * @brief Define o atributo altura
         * 
         * @param altura É a altura da imagem
         */
        void setAltura(const unsigned int altura);

        /**
         * @brief Retorna o atributo altura
         * 
         * @return unsigned int É a altura da imagem
         */
        unsigned int getAltura() const;

        /**
         * @brief Define o atributo largura
         * 
         * @param largura É a largura da imagem
         */
        void setLargura(const unsigned int largura);

        /**
         * @brief Retorna o atributo largura
         * 
         * @return unsigned int É a largura da imagem
         */
        unsigned int getLargura() const;

        /**
         * @brief Define o atributo quantidadeTons
         * 
         * @param quantidadeTons É o tom maximo que um pixel consegue chegar
         */
        void setQuantidadeTons(const short quatidadeTons);

        /**
         * @brief Retorna o atributo quantidadeTons
         * 
         * @return short É o tom maximo que um pixel pode ter na imagem
         */
        short getQuantidadeTons() const;

        /**
         * @brief Retorna a lista de pixels da imagem
         * 
         * @return Lista<Pixel*>* É a lista de pixels da imagem
         */
        Lista<Pixel*>* getPixels() const;

        /**
         * @brief Retorna a quantidade total de pixels que a imagem possui
         * 
         * @return unsigend int é a quantidade total de pixels que a imagem possui
         */
        unsigned int getTotalPixels() const;
};

#endif

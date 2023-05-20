#ifndef PPM_PIXEL_H
#define PPM_PIXEL_H

#include "Pixel.h"

class PPMPixel : public Pixel {
    private:
        short vermelho = 0;
        short verde = 0;
        short azul = 0;

    public:
        /**
         * @brief Cria um pixel do tipo PPMPixel
         * 
         */
        PPMPixel();

        /**
         * @brief Cria um pixel do tipo PPMPixel
         * 
         * @param vermelho É o nível da cor vermelha
         * @param verde É o nível da cor verde
         * @param azul É o nível da cor azul
         * @param tomMaximo É o maior tom que cada cor pode chegar
         */
        PPMPixel(const short vermelho, const short verde, const short azul, const short tomMaximo);

        /**
         * @brief Destroi o objeto PPMPixel
         * 
         */
        virtual ~PPMPixel();

        /**
         * @brief Define o atributo Vermelho
         * 
         * @param vermelho É o nível do tom vermelho da cor
         */
        void setVermelho(const short vermelho);

        /**
         * @brief Retorna o atributo Vermelho
         * 
         * @return short É o nível do tom vermelho
         */
        short getVermelho() const;

        /**
         * @brief [DEBUG] Retorna um ponteiro para a cor vermelha
         * 
         * @details Essa função apenas é utilizada para o memlog
         * 
         * @return short* É o ponteiro para a cor vermelha do pixel
         */
        short* getEnderecoVermelho();

        /**
         * @brief Define o atributo Verde
         * 
         * @param verde É o nível do tom verde da cor
         */
        void setVerde(const short verde);

        /**
         * @brief Retorna o atributo Verde
         * 
         * @return short É o nível do tom verde
         */
        short getVerde() const;

        /**
         * @brief [DEBUG] Retorna um ponteiro para a cor verde
         * 
         * @details Essa função apenas é utilizada para o memlog
         * 
         * @return short* É o ponteiro para a cor verde do pixel
         */
        short* getEnderecoVerde();

        /**
         * @brief Define o atributo Azul
         * 
         * @param azul É o nível do tom Azul da cor
         */
        void setAzul(const short azul);

        /**
         * @brief Retorna o atributo Azul
         * 
         * @return short É o nível do tom azul
         */
        short getAzul() const;

        /**
         * @brief [DEBUG] Retorna um ponteiro para a cor azul
         * 
         * @details Essa função apenas é utilizada para o memlog
         * 
         * @return short* É o ponteiro para a cor azul do pixel
         */
        short* getEnderecoAzul();
};

#endif

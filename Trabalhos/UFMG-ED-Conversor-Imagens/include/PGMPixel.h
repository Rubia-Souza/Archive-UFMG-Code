#ifndef PGM_PIXEL_H
#define PGM_PIXEL_H

#include "Pixel.h"

class PGMPixel : public Pixel {
    private:
        short valor = 0;

    public:
        /**
         * @brief Cria um objeto do tipo PGMPixel
         * 
         */
        PGMPixel();

        /**
         * @brief Cria um objeto do tipo PGMPixel
         * 
         * @param valor É o tom de cinza do pixel
         * @param tomMaximo É o maior tom que o pixel pode ter
         */
        PGMPixel(const short valor, const short tomMaximo);

        /**
         * @brief Destroi o objeto PGMPixel
         * 
         */
        virtual ~PGMPixel();

        /**
         * @brief Define o atributo Valor
         * 
         * @param valor É o tom de cinza do pixel
         */
        void setValor(const short valor);

        /**
         * @brief Retorna o objeto Valor
         * 
         * @return short É o tom de cinza do pixel
         */
        short getValor() const;

        /**
         * @brief [DEBUG] Retorna um ponteiro para o tom de cinza
         * 
         * @details Essa função apenas é utilizada para o memlog
         * 
         * @return short* É o ponteiro para o tom de cinza do pixel
         */
        short* getEnderecoValor();
};

#endif

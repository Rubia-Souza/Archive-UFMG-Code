#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
    private:
        short tomMaximo = 0;

    protected:
        /**
         * @brief Cria um objeto do tipo Pixel
         * 
         */
        Pixel();

        /**
         * @brief Cria um objeto do tipo Pixel
         * 
         * @param tomMaximo É o maior tom que o pixel pode ter 
         */
        Pixel(const short tomMaximo);

    public:
        /**
         * @brief Destroi o objeto Pixel
         * 
         */
        virtual ~Pixel();

        /**
         * @brief Define o atributo Tom Maximo
         * 
         * @param tomMaximo É o maior tom que o pixel pode ter
         */
        void setTomMaximo(const short tomMaximo);

        /**
         * @brief Retorna o atributo Tom Maximo
         * 
         * @return short É o maior tom que o pixel pode ter
         */
        short getTomMaximo() const;
};

#endif

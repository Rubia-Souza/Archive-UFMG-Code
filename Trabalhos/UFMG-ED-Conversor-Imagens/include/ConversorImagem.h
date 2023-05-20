#ifndef CONVERSOR_IMAGEM_H
#define CONVERSOR_IMAGEM_H

#include "Imagem.h"

class ConversorImagem {
    public:
        /**
         * @brief Converte a imagem PPM para PGM
         * 
         * @param imagemPPM É imagem PPM que será convertida
         * @return Imagem* É a imagem PGM resultante da conversão
         */
        static Imagem* converterPPMparaPGM(const Imagem& imagemPPM);
};

#endif

#ifndef CELULA_H
#define CELULA_H

#include "FaixaOrdenacao.h"

class Celula {
    public:
        Celula* proxima = nullptr;
        Celula* anterior = nullptr;
        FaixaOrdencao* valor = nullptr;

        /**
         * @brief Cria um novo objeto Celula
         * 
         */
        Celula();

        /**
         * @brief Destroi objeto Celula
         * 
         */
        virtual ~Celula();
};

#endif

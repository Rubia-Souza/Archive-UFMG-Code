#ifndef NODO_H
#define NODO_H

#include "Verbete.h"

class Nodo {
    private:
        Nodo* esquerdo = nullptr;
        Nodo* direito = nullptr;

        Verbete* conteudo = nullptr;
        int altura = 0;

    public:
        /**
         * @brief Cria um objeto do tipo Nodo
         * 
         */
        Nodo();

        /**
         * @brief Destroi um objeto do tipo Nodo
         * 
         */
        virtual ~Nodo();

        /**
         * @brief Define o atributo Nodo Esquerdo
         * 
         * @param esquerdo É a referência no Nodo Esquerdo
         */
        void setNodoEsquerdo(Nodo* esquerdo);

        /**
         * @brief Retorna o atributo Nodo Esquerdo
         * 
         * @return Nodo*& É a referência para o Nodo Esquerdo
         */
        Nodo*& getNodoEsquerdo();

        /**
         * @brief Define o atributo Nodo Direito
         * 
         * @param direito É a referência no Nodo Direito
         */
        void setNodoDireito(Nodo* direito);

        /**
         * @brief Retorna o atributo Nodo Direito
         * 
         * @return Nodo*& É a referência para o Nodo Direito
         */
        Nodo*& getNodoDireito();

        /**
         * @brief Define o atributo Conteudo
         * 
         * @param conteudo É o valor que será armazenado no Conteudo
         */
        void setConteudo(Verbete* conteudo);

        /**
         * @brief Retorna o valor do atributo conteudo
         * 
         * @return Verbete* É o valor do conteudo do nodo
         */
        Verbete* getConteudo();

        /**
         * @brief Define a altura do nodo
         * 
         * @param altura É a altura do nodo
         */
        void setAltura(const int altura);

        /**
         * @brief Retorna a altura do nodo
         * 
         * @return int É a altura do nodo
         */
        int getAltura() const;
};

#endif

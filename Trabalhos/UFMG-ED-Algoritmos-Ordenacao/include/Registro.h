#ifndef REGISTRO_H
#define REGISTRO_H

#include "Constantes.h"

class Registro {
    public:
        int chave = 0;
        char textos[QUANTIDADE_STRINGS_REGISTRO][TAMANHO_PADRAO_STRING_REGISTRO];
        float numeros[QUANTIDADE_NUMEROS_REGISTRO];

        /**
         * @brief Cria um novo objeto Registro
         * 
         */
        Registro();
        //Registro(const Registro& registro);

        /**
         * @brief Destroi objeto registro
         * 
         */
        virtual ~Registro();

        //Registro& operator=(const Registro& outroRegistro);

        /**
         * @brief Realiza a comparação <= entre dois registros
         * 
         * @param outroRegistro É o registro no lado direito da operação
         * @return true Se o registro no lado esquerdo tem uma chave menor ou igual
         * @return false Se o registro no lado direito tem uma chave menor ou igual
         */
        bool operator<=(const Registro& outroRegistro);

        /**
         * @brief Realiza a comparação < entre dois registros
         * 
         * @param outroRegistro É o registro no lado direito da operação
         * @return true Se o registro no lado esquerdo tem uma chave menor
         * @return false Se o registro no lado direito tem uma chave menor
         */
        bool operator<(const Registro& outroRegistro);

        /**
         * @brief Realiza a comparação >= entre dois registros
         * 
         * @param outroRegistro É o registro no lado direito da operação
         * @return true Se o registro no lado esquerdo tem uma chave maior ou igual
         * @return false Se o registro no lado direito tem uma chave maior ou igual
         */
        bool operator>=(const Registro& outroRegistro);

        /**
         * @brief Realiza a comparação > entre dois registros
         * 
         * @param outroRegistro É o registro no lado direito da operação
         * @return true Se o registro no lado esquerdo tem uma chave maior
         * @return false Se o registro no lado direito tem uma chave maior
         */
        bool operator>(const Registro& outroRegistro);

        /**
         * @brief Printa as informações do Registro no terminal
         * 
         */
        void print();
};

#endif

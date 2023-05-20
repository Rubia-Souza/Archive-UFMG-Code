#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem {
    private:
        std::string texto = "";
        unsigned int prioridade = 0;

    public:
        /**
         * @brief Cria o objeto de Mensagem
         * 
         */
        Mensagem();

        /**
         * @brief Cria o objeto de Mensagem
         * 
         * @param texto É o texto que a Mensagem contem
         * @param prioridade É a prioridade dada a Mensagem
         */
        Mensagem(const std::string texto, const unsigned int prioridade);

        /**
         * @brief Destroi o objeto Mensagem
         * 
         */
        virtual ~Mensagem();

        /**
         * @brief Define o Texto da mensagem
         * 
         * @param texto É o Texo que a mensagem contém
         */
        void setTexto(const std::string texto);
        
        /**
         * @brief Retorna o Texto da Mensagem
         * 
         * @return std::string  É o Texto que a mensagem contém
         */
        std::string getTexto() const;

        /**
         * @brief Define a Prioridade da Mensagem
         * 
         * @param prioridade É o nível de prioridade da Mensagem
         */
        void setPrioridade(const unsigned int prioridade);

        /**
         * @brief Retorna a Prioridade da mensagem
         * 
         * @return unsigned int É o nível de prioridade da mensagem
         */
        unsigned int getPrioridade() const;
};

#endif

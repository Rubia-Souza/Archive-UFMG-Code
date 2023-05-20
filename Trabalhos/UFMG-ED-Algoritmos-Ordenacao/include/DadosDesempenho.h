#ifndef DADOS_DESEMPENHO_H
#define DADOS_DESEMPENHO_H

class DadosDesempenho {
    public:
        unsigned int quantidadeComparacoes = 0;
        unsigned int quantidadeAtribuicoes = 0;

        /**
         * @brief Cria um objeto Dados Desempenho
         * 
         */
        DadosDesempenho();

        /**
         * @brief Destroi objeto Dados Desempenho
         * 
         */
        virtual ~DadosDesempenho();

        /**
         * @brief Printa informações do objeto no terminal
         * 
         */
        void print() const;
};

#endif

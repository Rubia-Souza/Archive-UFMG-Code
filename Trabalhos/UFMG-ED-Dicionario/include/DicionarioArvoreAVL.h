#ifndef DICIONARIO_ARVORE_AVL_H
#define DICIONARIO_ARVORE_AVL_H

#include <string>
#include <fstream>

#include "Nodo.h"

#include "Dicionario.h"
#include "Verbete.h"

class DicionarioArvoreAVL : public Dicionario {
    private:
        static const unsigned int ESPACAMENTO_PADRAO = 10;
        Nodo* raiz = nullptr;

        unsigned int quantidadeElementos = 0;

    public:
        /**
         * @brief Cria objeto DicionarioArvoreAVL
         * 
         */
        DicionarioArvoreAVL();

        /**
         * @brief Destroi objeto DicionarioArvoreAVL
         * 
         */
        virtual ~DicionarioArvoreAVL();

        /**
         * @brief Insere um verbete no dicionário
         * 
         * @param verbete É o verbete que será inserido
         */
        virtual void inserir(Verbete& verbete) override;

        /**
         * @brief Busca um verbete com base em uma palavra
         * 
         * @param palavra É a palavra do verbete que será buscado
         * @return Verbete* É o verbete da palavra, se existir. Caso contrário, é nullptr
         */
        virtual Verbete* pesquisar(const std::string palavra, const TiposVerbete tipo) override;

        /**
         * @brief Sobre-escreve as informações de um verbete
         * 
         * @details Caso o verbete não seja encontrado, nada é feito.
         * 
         * @param verbete É as novas informações que serão sobre-escritas no verbete
         */
        virtual void atualizar(Verbete& verbete) override;

        /**
         * @brief Remove o verbete com a palavra informada caso encontrado
         * 
         * @param palavra É a palavra do verbete que será buscado e removido
         */
        virtual void remover(const std::string palavra, const TiposVerbete tipo) override;

        /**
         * @brief Imprime o dicionário no terminal
         * 
         */
        virtual void imprimir() override;

        /**
         * @brief Imprime as informações do dicionário no arquivo informado
         * 
         * @param arquivo É o arquivo que terá as informações do Dicionario escrita
         */
        virtual void imprimirEmArquivo(std::ofstream* arquivo) override;

        /**
         * @brief Imprime as informações em estrutura de Arvore na horizontal
         * 
         */
        void imprimirArvoreHorizontal();

        /**
         * @brief Remove todos elementos do dicionário
         * 
         */
        virtual void limpar() override;

        /**
         * @brief Verifica se o dicionário está vazio
         * 
         * @return true Se o dicionário estiver vazio
         * @return false Se o dicionário não estiver vazio
         */
        virtual bool estaVazia() override;

        /**
         * @brief Remove todos os verbetes com mais de um significado no dicionário
         * 
         */
        virtual void removerVerbetesComMaisDeUmSignificado() override;
    
    private:
        /**
         * @brief Insere de forma recursiva um Verbete na Arvore
         * 
         * @details Caso haja um desbalanceamento, a arvore é ajustada com a respectiva rotação necessária
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param verbete É o verbete que será inserido
         * @return Nodo* É o nodo para atulizar os antecedentes
         */
        Nodo* inserirRecursivamente(Nodo* nodo, Verbete& verbete);

        /**
         * @brief Pesquisa uma palavra de forma recursiva ao longo da arvore
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param palavra É a palavra que será pesquisada
         * @return Verbete* São as informações do verbete associado a palavra
         */
        Verbete* pesquisarRecursivamente(Nodo*& nodo, const std::string palavra, const TiposVerbete tipo);

        /**
         * @brief Atualiza as informações de um verbete ao encontrá-lo de forma recursiva
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param verbete São as novas informações que serão sobre-escritas no verbete
         */
        void atualizarRecursivamente(Nodo*& nodo, Verbete& verbete);

        /**
         * @brief Remove um verbete de forma recursiva ao longo da arvore
         * 
         * @details Caso haja um desbalanceamento, a arvore é ajustada com a respectiva rotação necessária
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param palavra É a palavra do verbete que será removido
         * @return Nodo* É o nodo para atulizar os antecedentes
         */
        Nodo* removerRecursivamente(Nodo* nodo, const std::string palavra, const TiposVerbete tipo);

        /**
         * @brief Busca o menor elemento em uma determinada subarvore
         * 
         * @param subarvore É a raiz da subarvore que será buscada
         * @return Nodo* É o menor elemento presente na subarvore
         */
        Nodo* encontrarMenorValorSubArvoreDireita(Nodo* subarvore);

        /**
         * @brief Imprime a arvore de forma recursiva in-order
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         */
        void imprimirRecursivamente(Nodo*& nodo);

        /**
         * @brief Imprime a arvore de forma recursiva in-order
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param arquivo É o arquivo onde as informações da arvore serão escritas
         */
        void imprimirEmArquivoRecursivo(Nodo*& nodo, std::ofstream* arquivo);

        /**
         * @brief Imprime uma estrutura de arvore e nodos horizontalmente no terminal
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param espacamento É o espaçamento entre os nodos
         */
        void imprimirArvoreHorizontal(Nodo*& nodo, unsigned int espacamento);

        /**
         * @brief Apaga todos os nodos da arvore de forma recursiva
         * 
         * @param nodo É o nodo de referência sendo percorrido atualmente
         */
        void limparRecursivamente(Nodo*& nodo);

        /**
         * @brief Adiciona todas as palavras com um significado ou mais no array de palavras
         * 
         * @param verebetes É o array que terá os verbetes com suas respectivas palavras e tipos que possuem mais de um significado
         * @param nodo É o nodo de referência sendo percorrido atualmente
         * @param index É o index do array atual
         */
        void buscarVerbetesComMaisDeUmSignificadoRecursivo(Verbete verebetes[], Nodo* nodo, unsigned int& index);

        /**
         * @brief Calcula a altura do nodo com base nas subarvores a esquerda e direita
         * 
         * @param nodo É o nodo que terá altura atualizada
         */
        void atualizarAlturaNodo(Nodo*& nodo);

        /**
         * @brief Calcula o fator de balanceamento do nodo informada
         * 
         * @param nodo É o nodo que terá o balanceamento calculado
         * @return int Retorna o fator de balanceamento do nodo informado
         */
        int calcularFatorBalanceamento(Nodo*& nodo);

        /**
         * @brief Rotaciona uma parte da arvore para a esquerda
         * 
         * @param nodo Pivo de rotação, nodo base da onde ocorreu o desbalanceamento
         * @return Nodo* Nova base para a subarvore ajustada
         */
        Nodo* rotacionarParaEsquerda(Nodo* nodo);

        /**
         * @brief Rotaciona uma parte da arvore para a direita
         * 
         * @param nodo Pivo de rotação, nodo base da onde ocorreu o desbalanceamento
         * @return Nodo* Nova base para a subarvore ajustada
         */
        Nodo* rotacionarParaDireita(Nodo* nodo);
};

#endif

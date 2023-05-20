#ifndef LISTA_H
#define LISTA_H

#include <stdexcept>
#include <string>

#include "Celula.h"
#include "ExcecoesLista.h"

template<typename T>
class Lista {
    private:
        static const std::string MENSAGEM_ERRO_AO_ADICIONAR_ITEM;
        static const std::string MENSAGEM_ERRO_AO_REMOVER_ITEM;
        static const std::string MENSAGEM_ERRO_AO_BUSCAR_ITEM;
        static const std::string MENSAGEM_ERRO_POSICAO_INVALIDA;

        unsigned int tamanho = 0;
        Celula<T>* inicio = nullptr;
        Celula<T>* fim = nullptr;

    public:
        /**
         * @brief Cria um objeto Lista duplamente encadeade
         * 
         */
        Lista() {
            inicio = new Celula<T>();
            fim = new Celula<T>();

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);

            return;
        }

        /**
         * @brief Destroy o objeto Lista
         * 
         */
        virtual ~Lista() {
            Celula<T>* proxima = nullptr;

            for(Celula<T>* iterador = inicio; iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }

            return;
        }

        /**
         * @brief Adiciona um item ao fim da lista
         * 
         * @param valor É o item que será adicionado a lista
         */
        void adicionarFim(const T valor) {
            Celula<T>* nova = new Celula<T>(valor);
            Celula<T>* anteriorAoFim = fim->getAnteriorCelula();

            fim->setAnteriorCelula(nova);
            anteriorAoFim->setProximaCelula(nova);

            nova->setProximaCelula(fim);
            nova->setAnteriorCelula(anteriorAoFim);

            tamanho++;
            return;
        }

        /**
         * @brief Adiciona um item ao comeco da lista
         * 
         * @param valor É o item que será adicionado a lista
         */
        void adicionarComeco(const T valor) {
            Celula<T>* nova = new Celula<T>(valor);
            Celula<T>* posteriorAoInicio = inicio->getProximaCelula();

            inicio->setProximaCelula(nova);
            posteriorAoInicio->setAnteriorCelula(nova);

            nova->setProximaCelula(posteriorAoInicio);
            nova->setAnteriorCelula(inicio);

            tamanho++;
            return;
        }

        /**
         * @brief Adiciona um item a uma determinda posição na lista
         * 
         * @param valor É o item que será adicionado a lista
         * @param posicao É a posição que o item será inserido
         */
        void adicionarNaPosicao(const T valor, const unsigned int posicao) {
            if(posicao > getTamanho() || posicao < 0) {
                throw ExcecoesLista::IndexInvalidoException(MENSAGEM_ERRO_AO_ADICIONAR_ITEM + MENSAGEM_ERRO_POSICAO_INVALIDA);
            }
            else if(estaVazia()) {
                adicionarComeco(valor);
                return;
            }

            Celula<T>* nova = new Celula<T>(valor);

            Celula<T>* referencia = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                referencia = referencia->getProximaCelula();
            }

            Celula<T>* anteriorReferencia = referencia->getAnteriorCelula();

            anteriorReferencia->setProximaCelula(nova);
            referencia->setAnteriorCelula(nova);

            nova->setProximaCelula(referencia);
            nova->setAnteriorCelula(anteriorReferencia);

            tamanho++;
            return;
        }
        
        /**
         * @brief Remove o item do fim da lista
         * 
         */
        void removerFim() {
            if(estaVazia()) {
                return;
            }

            Celula<T>* alvo = fim->getAnteriorCelula();
            Celula<T>* anteriorAoAlvo = alvo->getAnteriorCelula();

            anteriorAoAlvo->setProximaCelula(fim);
            fim->setAnteriorCelula(anteriorAoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        /**
         * @brief Remove o item do fim do começo da lista
         * 
         */
        void removerComeco() {
            if(estaVazia()) {
                return;
            }
            
            Celula<T>* alvo = inicio->getProximaCelula();
            Celula<T>* proximaDoAlvo = alvo->getProximaCelula();

            proximaDoAlvo->setAnteriorCelula(inicio);
            inicio->setProximaCelula(proximaDoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        /**
         * @brief Remove um item em uma determinada posição
         * 
         * @param posicao É a posição que do item que será removido
         */
        void remover(const unsigned int posicao) {
            if(posicao > getTamanho() || posicao < 0) {
                throw ExcecoesLista::IndexInvalidoException(MENSAGEM_ERRO_AO_REMOVER_ITEM + MENSAGEM_ERRO_POSICAO_INVALIDA);
            }
            else if(estaVazia()) {
                return;
            }
            
            Celula<T>* alvo = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                alvo = alvo->getProximaCelula();
            }

            Celula<T>* anteriorAoAlvo = alvo->getAnteriorCelula();
            Celula<T>* posteriorAoAlvo = alvo->getProximaCelula();

            anteriorAoAlvo->setProximaCelula(posteriorAoAlvo);
            posteriorAoAlvo->setAnteriorCelula(anteriorAoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        /**
         * @brief Remove um item com base em um determinado iterador
         * 
         * @param iterador É o iterador que contém a célula que será removida
         */
        void remover(Celula<T>* iterador) {
            if(estaVazia() || iterador == inicio || iterador == fim) {
                return;
            }

            Celula<T>* anteriorAoAlvo = iterador->getAnteriorCelula();
            Celula<T>* posteriorAoAlvo = iterador->getProximaCelula();

            anteriorAoAlvo->setProximaCelula(posteriorAoAlvo);
            posteriorAoAlvo->setAnteriorCelula(anteriorAoAlvo);

            delete iterador;
            tamanho--;
            return;
        }

        /**
         * @brief Remove todos os itens da lista
         * 
         */
        void limpar() {
            if(estaVazia()) {
                return;
            }
            
            Celula<T>* proxima = nullptr;
            for(Celula<T>* iterador = inicio->getProximaCelula(); iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);
            tamanho = 0;
            return;
        }

        /**
         * @brief Retorna o tamanho da lista
         * 
         * @return unsigned int é o tamanho da lista
         */
        unsigned int getTamanho() const {
            return tamanho;
        }

        /**
         * @brief Retorna o item em uma determinada posição
         * 
         * @param posicao É a posição do item que será retornado
         * @return T É o item retornado na posição especificada
         */
        T get(const unsigned int posicao) const {
            if(estaVazia() || posicao > getTamanho() || posicao < 0) {
                throw ExcecoesLista::IndexInvalidoException(MENSAGEM_ERRO_AO_BUSCAR_ITEM + MENSAGEM_ERRO_POSICAO_INVALIDA);
            }

            Celula<T>* alvo = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                alvo = alvo->getProximaCelula();
            }

            return alvo->getValor();
        }

        /**
         * @brief Retorna um ponteiro para a posição inicial da lista
         * 
         * @return Celula<T>* É a posição inicial da lista
         */
        Celula<T>* getInicio() const {
            return inicio;
        }

        /**
         * @brief Retorna um ponteiro para a posição final da lista
         * 
         * @return Celula<T>* É a posição final da lista
         */
        Celula<T>* getFim() const {
            return fim;
        }

        /**
         * @brief Verifica se a lista está vazia
         * 
         * @return true A lista está vazia
         * @return false A lista não está vazia
         */
        bool estaVazia() const {
            return (getTamanho() == 0);
        }
};

template<typename T>
const std::string Lista<T>::MENSAGEM_ERRO_AO_ADICIONAR_ITEM = "[ERRO] Erro ao adicionar item: ";

template<typename T>
const std::string Lista<T>::MENSAGEM_ERRO_AO_REMOVER_ITEM = "[ERRO] Erro ao remover item: ";

template<typename T>
const std::string Lista<T>::MENSAGEM_ERRO_AO_BUSCAR_ITEM = "[ERRO] Erro ao buscar item: ";

template<typename T>
const std::string Lista<T>::MENSAGEM_ERRO_POSICAO_INVALIDA = "Posicao fora dos limites da lista.";

#endif

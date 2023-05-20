#ifndef LISTA_PRIORIDADE_H
#define LISTA_PRIORIDADE_H

#include <string>
#include <stdexcept>

#include "Lista.h"
#include "CelulaPrioridade.h"
#include "ExcecoesLista.h"

template<typename T>
class FilaPrioridade : public Lista {
    private:
        static const std::string MENSAGEM_ERRO_FILA_VAZIA;

        CelulaPrioridade<T>* inicio = nullptr;
        CelulaPrioridade<T>* fim = nullptr;

    public:
        /**
         * @brief Cria um objeto Fila de Prioridade duplamente encadeada
         * 
         */
        FilaPrioridade() {
            inicio = new CelulaPrioridade<T>();
            fim = new CelulaPrioridade<T>();

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);

            return;
        }

        /**
         * @brief Destroy o objeto Lista
         * 
         */
        virtual ~FilaPrioridade() {
            CelulaPrioridade<T>* proxima = nullptr;

            for(CelulaPrioridade<T>* iterador = inicio; iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }
            
            return;
        }

        /**
         * @brief Adiciona um item a na Fila de Prioridade
         * 
         * @param valor É o item que será adicionado na Fila
         * @param prioridade É prioridade que este item tem em relação aos outros
         */
        void adicionar(T* valor, const unsigned int prioridade) {
            CelulaPrioridade<T>* novaCelula = new CelulaPrioridade<T>(valor, prioridade);
            CelulaPrioridade<T>* referencia = fim->getAnteriorCelula();

            if(!estaVazia()) {
                while(novaCelula->getPrioridade() > referencia->getPrioridade() && referencia != inicio) {
                    referencia = referencia->getAnteriorCelula();
                }   
            }

            CelulaPrioridade<T>* proximaReferencia = referencia->getProximaCelula();

            novaCelula->setAnteriorCelula(referencia);
            novaCelula->setProximaCelula(proximaReferencia);

            proximaReferencia->setAnteriorCelula(novaCelula);
            referencia->setProximaCelula(novaCelula);

            tamanho++;
            return;
        }

        /**
         * @brief Retorna o item em uma determinada posição
         * 
         * @param posicao É a posição do item que será retornado
         * @return T É o item retornado na posição especificada
         */
        T* get(const unsigned int posicao) const {
            if(estaVazia() || posicao > getTamanho() || posicao < 0) {
                throw ExcecoesLista::IndexInvalidoException(MENSAGEM_ERRO_AO_BUSCAR_ITEM + MENSAGEM_ERRO_POSICAO_INVALIDA);
            }

            CelulaPrioridade<T>* alvo = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                alvo = alvo->getProximaCelula();
            }

            return alvo->getValor();
        }

        /**
         * @brief Remove o primeiro item da Fila de Prioridade e o retorna
         * 
         * @return T É o primeiro item da lista de prioridade
         */
        T pop() {
            if(estaVazia()) {
                throw ExcecoesLista::IndexInvalidoException(MENSAGEM_ERRO_AO_BUSCAR_ITEM + MENSAGEM_ERRO_FILA_VAZIA);
            }

            CelulaPrioridade<T>* alvo = inicio->getProximaCelula();
            CelulaPrioridade<T>* anteriorAoAlvo = alvo->getAnteriorCelula();
            CelulaPrioridade<T>* posteriorAoAlvo = alvo->getProximaCelula();

            anteriorAoAlvo->setProximaCelula(posteriorAoAlvo);
            posteriorAoAlvo->setAnteriorCelula(anteriorAoAlvo);
            T valor = *alvo->getValor();

            delete alvo;
            tamanho--;

            return valor;
        }

        /**
         * @brief Remove todos os itens da Fila
         * 
         */
        void virtual limpar() override {
            if(estaVazia()) {
                return;
            }
            
            CelulaPrioridade<T>* proxima = nullptr;
            for(CelulaPrioridade<T>* iterador = inicio->getProximaCelula(); iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);
            tamanho = 0;
            return;
        }

        /**
         * @brief Retorna o Inicio da Fila
         * 
         * @return CelulaPrioridade<T>* É o Início da Fila
         */
        CelulaPrioridade<T>* getInicio() const {
            return inicio;
        }
        
        /**
         * @brief Retorna o Fim da Fila
         * 
         * @return CelulaPrioridade<T>*  É o Fim da Fila
         */
        CelulaPrioridade<T>* getFim() const {
            return fim;
        }
};

template<typename T>
const std::string FilaPrioridade<T>::MENSAGEM_ERRO_FILA_VAZIA = "A lista esta vazia.";

#endif

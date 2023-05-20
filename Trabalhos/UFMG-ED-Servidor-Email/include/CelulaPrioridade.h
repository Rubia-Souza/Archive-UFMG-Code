#ifndef CELULA_PRIORIDADE_H
#define CELULA_PRIORIDADE_H

template<typename T>
class CelulaPrioridade {
    private:
        CelulaPrioridade<T>* proxima = nullptr;
        CelulaPrioridade<T>* anterior = nullptr;
        T* valor = nullptr;

        unsigned int prioridade = 0;

    public:
        /**
         * @brief Cria um objeto CelulaPrioridade
         * 
         */
        CelulaPrioridade() {}

        /**
         * @brief Cria um objeto CelulaPrioridade
         * 
         * @param valor É o dado armazenado na CelulaPrioridade
         */
        CelulaPrioridade(T* valor) {
            setValor(valor);
            setProximaCelula(new CelulaPrioridade<T>());
            setAnteriorCelula(new CelulaPrioridade<T>());

            return;
        }

        /**
         * @brief Cria um objeto CelulaPrioridade
         * 
         * @param valor É o dado armazenado na CelulaPrioridade
         * @param prioridade É a prioridade que será dada para o posicionamento da CelulaPrioridade
         */
        CelulaPrioridade(T* valor, const unsigned int prioridade) {
            setValor(valor);
            setPrioridade(prioridade);
            setProximaCelula(new CelulaPrioridade<T>());
            setAnteriorCelula(new CelulaPrioridade<T>());

            return;
        }

        /**
         * @brief Cria um objeto CelulaPrioridade
         * 
         * @param valor É o dado armazenado na CelulaPrioridade
         * @param proxima É a proxima CelulaPrioridade em relação a atual
         * @param anterior É a CelulaPrioridade anterior em relação a atual
         */
        CelulaPrioridade(T* valor, CelulaPrioridade<T>* proxima, CelulaPrioridade<T>* anterior) {
            setValor(valor);
            setProximaCelula(proxima);
            setAnteriorCelula(anterior);

            return;
        }

        /**
         * @brief Cria um objeto CelulaPrioridade
         * 
         * @param valor É o dado armazenado na CelulaPrioridade
         * @param prioridade É a prioridade que será dada para o posicionamento da CelulaPrioridade
         * @param proxima É a proxima CelulaPrioridade em relação a atual
         * @param anterior É a CelulaPrioridade anterior em relação a atual
         */
        CelulaPrioridade(T* valor, unsigned int prioridade, CelulaPrioridade<T>* proxima, CelulaPrioridade<T>* anterior) {
            setValor(valor);
            setPrioridade(prioridade);
            setProximaCelula(proxima);
            setAnteriorCelula(anterior);

            return;
        }

        /**
         * @brief Destroi o objeto CelulaPrioridade
         * 
         */
        virtual ~CelulaPrioridade() {
            proxima = nullptr;
            anterior = nullptr;
            delete valor;

            return;
        }

        /**
         * @brief Define o atributo Valor
         * 
         * @param valor É o dado armazenado na celula
         */
        void setValor(T* valor) {
            this->valor = valor;
            return;
        }

        /**
         * @brief Retorna o atributo valor
         * 
         * @return T É o valor armazenado pela celula
         */
        T* getValor() const {
            return valor;
        }

        /**
         * @brief Define o atributo proixma da celula
         * 
         * @param proxima É a proxima celula em relação a atual
         */
        void setProximaCelula(CelulaPrioridade<T>* proxima) {
            this->proxima = proxima;
            return;
        }

        /**
         * @brief Retorna a Proxima Celula em relação a atual
         * 
         * @return CelulaPrioridade<T>* É a proxima celula em relação a atual
         */
        CelulaPrioridade<T>* getProximaCelula() const {
            return proxima;
        }

        /**
         * @brief Define o atributo anterior da celula
         * 
         * @param proxima É a celula anterior em relação a atual
         */
        void setAnteriorCelula(CelulaPrioridade<T>* anterior) {
            this->anterior = anterior;
            return;
        }

        /**
         * @brief Retorna a Celula anterior em relação a atual
         * 
         * @return CelulaPrioridade<T>* É a celula anterior em relação a atual
         */
        CelulaPrioridade<T>* getAnteriorCelula() const {
            return anterior;
        }

        /**
         * @brief Define o atributo prioridade
         * 
         * @param prioridade É a prioridade que será dada para o posicionamento da CelulaPrioridade
         */
        void setPrioridade(const unsigned int prioridade) {
            this->prioridade = prioridade;
            return;
        }

        /**
         * @brief Retorna o atributo valor
         * 
         * @return unsigned int É a prioridade que será dada para o posicionamento da CelulaPrioridade
         */
        unsigned int getPrioridade() const {
            return prioridade;
        }
};

#endif

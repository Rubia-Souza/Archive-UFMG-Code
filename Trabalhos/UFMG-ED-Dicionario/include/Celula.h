#ifndef CELULA_H
#define CELULA_H

template<typename T>
class Celula {
    private:
        T valor;
        Celula* proxima = nullptr;
        Celula* anterior = nullptr;

    public:
        /**
         * @brief Cria um objeto Celula
         * 
         */
        Celula() {}

        /**
         * @brief Cria um objeto Celula
         * 
         * @param valor É o dado armazenado na celula
         */
        Celula(const T valor) {
            setValor(valor);
            setProximaCelula(new Celula<T>());
            setAnteriorCelula(new Celula<T>());

            return;
        }

        /**
         * @brief Cria um objeto Celula
         * 
         * @param valor É o dado armazenado na celula
         * @param proxima É a proxima celula em relação a atual
         * @param anterior É a celula anterior em relação a atual
         */
        Celula(const T valor, Celula<T>* proxima, Celula<T>* anterior) {
            setValor(valor);
            setProximaCelula(proxima);
            setAnteriorCelula(anterior);

            return;
        }

        /**
         * @brief Destroi o objeto Celula
         * 
         */
        virtual ~Celula() {
            proxima = nullptr;
            anterior = nullptr;

            return;
        }

        /**
         * @brief Define o atributo Valor
         * 
         * @param valor É o dado armazenado na celula
         */
        void setValor(const T valor) {
            this->valor = valor;
            return;
        }

        /**
         * @brief Retorna o atributo valor
         * 
         * @return T É o valor armazenado pela celula
         */
        T getValor() const {
            return valor;
        }

        /**
         * @brief Define o atributo proixma da celula
         * 
         * @param proxima É a proxima celula em relação a atual
         */
        void setProximaCelula(Celula<T>* proxima) {
            this->proxima = proxima;
            return;
        }

        /**
         * @brief Retorna a Proxima Celula em relação a atual
         * 
         * @return Celula<T>* É a proxima celula em relação a atual
         */
        Celula<T>* getProximaCelula() const {
            return proxima;
        }

        /**
         * @brief Define o atributo anterior da celula
         * 
         * @param proxima É a celula anterior em relação a atual
         */
        void setAnteriorCelula(Celula<T>* anterior) {
            this->anterior = anterior;
            return;
        }

        /**
         * @brief Retorna a Celula anterior em relação a atual
         * 
         * @return Celula<T>* É a celula anterior em relação a atual
         */
        Celula<T>* getAnteriorCelula() const {
            return anterior;
        }
};

#endif

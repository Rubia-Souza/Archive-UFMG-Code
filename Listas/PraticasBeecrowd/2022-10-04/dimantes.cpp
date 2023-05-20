#include <iostream>
#include <limits>
#include <string>

#pragma region .: Celula :.

class Celula {
    private:
        char valor;
        Celula* proxima = nullptr;
        Celula* anterior = nullptr;

    public:
        Celula() {}

        Celula(const char valor) {
            setValor(valor);
            setProximaCelula(new Celula());
            setAnteriorCelula(new Celula());
        }

        Celula(const char valor, Celula* proxima, Celula* anterior) {
            setValor(valor);
            setProximaCelula(proxima);
            setAnteriorCelula(anterior);
        }

        virtual ~Celula() {
            proxima = nullptr;
            anterior = nullptr;
        }

        void setValor(const char valor) {
            this->valor = valor;
            return;
        }

        char getValor() const {
            return valor;
        }

        void setProximaCelula(Celula* proxima) {
            this->proxima = proxima;
            return;
        }

        Celula* getProximaCelula() const {
            return proxima;
        }

        void setAnteriorCelula(Celula* anterior) {
            this->anterior = anterior;
            return;
        }

        Celula* getAnteriorCelula() const {
            return anterior;
        }
};

#pragma endregion

#pragma region .: Lista :.

class Lista {
    private:
        unsigned int tamanho = 0;
        Celula* inicio = nullptr;
        Celula* fim = nullptr;

    public:
        Lista() {
            inicio = new Celula();
            fim = new Celula();

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);
        }

        virtual ~Lista() {
            Celula* proxima = nullptr;
            for(Celula* iterador = inicio; iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }
        }

        void adicionarFim(const char valor) {
            Celula* nova = new Celula(valor);
            Celula* anteriorAoFim = fim->getAnteriorCelula();

            fim->setAnteriorCelula(nova);
            anteriorAoFim->setProximaCelula(nova);

            nova->setProximaCelula(fim);
            nova->setAnteriorCelula(anteriorAoFim);

            tamanho++;
            return;
        }

        void adicionarComeco(const char valor) {
            Celula* nova = new Celula(valor);
            Celula* posteriorAoInicio = inicio->getProximaCelula();

            inicio->setProximaCelula(nova);
            posteriorAoInicio->setAnteriorCelula(nova);

            nova->setProximaCelula(posteriorAoInicio);
            nova->setAnteriorCelula(inicio);

            tamanho++;
            return;
        }

        void adicionarNaPosicao(const char valor, const unsigned int posicao) {
            if(posicao > getTamanho() || posicao < 0) {
                return;
            }
            else if(estaVazia()) {
                adicionarComeco(valor);
                return;
            }

            Celula* nova = new Celula(valor);

            Celula* referencia = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                referencia = referencia->getProximaCelula();
            }

            Celula* anteriorReferencia = referencia->getAnteriorCelula();

            anteriorReferencia->setProximaCelula(nova);
            referencia->setAnteriorCelula(nova);

            nova->setProximaCelula(referencia);
            nova->setAnteriorCelula(anteriorReferencia);

            tamanho++;
            return;
        }
        
        void removerFim() {
            if(estaVazia()) {
                return;
            }

            Celula* alvo = fim->getAnteriorCelula();
            Celula* anteriorAoAlvo = alvo->getAnteriorCelula();

            anteriorAoAlvo->setProximaCelula(fim);
            fim->setAnteriorCelula(anteriorAoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        void removerComeco() {
            if(estaVazia()) {
                return;
            }
            
            Celula* alvo = inicio->getProximaCelula();
            Celula* proximaDoAlvo = alvo->getProximaCelula();

            proximaDoAlvo->setAnteriorCelula(inicio);
            inicio->setProximaCelula(proximaDoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        void remover(const unsigned int posicao) {
            if(estaVazia() || posicao > getTamanho() || posicao < 0) {
                return;
            }
            
            Celula* alvo = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                alvo = alvo->getProximaCelula();
            }

            Celula* anteriorAoAlvo = alvo->getAnteriorCelula();
            Celula* posteriorAoAlvo = alvo->getProximaCelula();

            anteriorAoAlvo->setProximaCelula(posteriorAoAlvo);
            posteriorAoAlvo->setAnteriorCelula(anteriorAoAlvo);

            delete alvo;
            tamanho--;
            return;
        }

        void remover(Celula* celula) {
            if(estaVazia() || celula == fim || celula == inicio) {
                return;
            }

            Celula* anteriorAoAlvo = celula->getAnteriorCelula();
            Celula* posteriorAoAlvo = celula->getProximaCelula();

            anteriorAoAlvo->setProximaCelula(posteriorAoAlvo);
            posteriorAoAlvo->setAnteriorCelula(anteriorAoAlvo);

            delete celula;
            tamanho--;
            return;
        }

        void limpar() {
            if(estaVazia()) {
                return;
            }
            
            Celula* proxima = nullptr;
            for(Celula* iterador = inicio->getProximaCelula(); iterador != fim; iterador = proxima) {
                proxima = iterador->getProximaCelula();
                delete iterador;
            }

            inicio->setProximaCelula(fim);
            fim->setAnteriorCelula(inicio);
            tamanho = 0;
            return;
        }

        unsigned int getTamanho() const {
            return tamanho;
        }

        char get(const unsigned int posicao) const {
            if(estaVazia() || posicao > getTamanho() || posicao < 0) {
                return ' ';
            }

            Celula* alvo = inicio->getProximaCelula();
            for(unsigned int i = 0; i < posicao && i < getTamanho(); i++) {
                alvo = alvo->getProximaCelula();
            }

            return alvo->getValor();
        }

        Celula* getInicio() const {
            return inicio;
        }

        Celula* getFim() const {
            return fim;
        }

        bool estaVazia() const {
            return (getTamanho() == 0);
        }
};

#pragma endregion

int main() {
    unsigned int quantidadeCasosTeste = 0;
    std::cin >> quantidadeCasosTeste;
    std::getchar();

    Lista* lista = new Lista();

    for(unsigned int i = 0; i < quantidadeCasosTeste; i++) {
        std::string linhaAtual = "";

        std::getline(std::cin, linhaAtual);

        for(unsigned int letra = 0; letra < linhaAtual.length(); letra++) {
            if(linhaAtual[letra] != '.') {
                lista->adicionarFim(linhaAtual[letra]);
            }
        }
        
        unsigned int contadorDimantes = 0;
        Celula* iterador = lista->getInicio()->getProximaCelula();
        while(iterador != lista->getFim()) {
            Celula* atual = iterador;
            Celula* proxima = iterador->getProximaCelula();

            if(atual->getValor() == '<' && proxima->getValor() == '>') {
                contadorDimantes++;

                lista->remover(atual);
                lista->remover(proxima);

                iterador = lista->getInicio()->getProximaCelula();
                continue;
            }

            iterador = iterador->getProximaCelula();
        }

        std::cout << contadorDimantes << "\n";
        lista->limpar();
    }

    delete lista;
    return 0;
}

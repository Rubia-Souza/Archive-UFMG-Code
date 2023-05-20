#include <iostream>
#include <string>

#pragma region .: Nodo :.

class Nodo {
    public:
        Nodo* esquerda = nullptr;
        Nodo* direita = nullptr;

    private:
        std::pair<char, unsigned int> valor;

    public:
        Nodo() {
            esquerda = nullptr;
            direita = nullptr;

            return;
        }

        virtual ~Nodo() {
            delete esquerda;
            delete direita;

            return;
        }

        void setLetra(std::pair<char, unsigned int> valor) {
            this->valor = valor;
            return;
        }

        char getLetra() {
            return valor.first;
        }

        unsigned int getPrioridade() {
            return valor.second;
        }

        void printNodo() {
            std::cout << getLetra();
            return;
        }
};

#pragma endregion

#pragma region .: Arvore :.

class Arvore {
    private:
        Nodo* raiz;

    public:
        Arvore() {
            raiz = nullptr;
            return;
        }

        virtual ~Arvore() {
            raiz = nullptr;
            return;
        }

        void inserir(std::pair<char, unsigned int> valor) {
            InserirRecursivamente(raiz, valor);
            return;
        }

        void printArvore() {
            CaminharPosOrdem(raiz);
            return;
        }

        void limpar() {
            ApagarRecursivamente(raiz);
            delete raiz;

            return;
        }
    
    private:
        void CaminharPosOrdem(Nodo* nodo) {
            if(nodo != nullptr) {
                CaminharPosOrdem(nodo->esquerda);
                CaminharPosOrdem(nodo->direita);
                nodo->printNodo();
            }
        }

        void InserirRecursivamente(Nodo*& nodo, std::pair<char, unsigned int> valor) {
            if(nodo == nullptr) {
                nodo = new Nodo();
                nodo->setLetra(valor);
                return;
            }

            if(nodo->getPrioridade() >= valor.second) {
                InserirRecursivamente(nodo->esquerda, valor);
            }
            else if(nodo->getPrioridade() < valor.second) {
                InserirRecursivamente(nodo->direita, valor);
            }

            return;
        }

        void ApagarRecursivamente(Nodo* nodo) {
            if(nodo != nullptr) {
                ApagarRecursivamente(nodo->esquerda);
                ApagarRecursivamente(nodo->direita);
                delete nodo;
            }
        }
};

#pragma endregion

int main() {
    std::string ordemInsercao = "", prioridade = "";
    std::pair<char, unsigned int> pesosPorLetra[26];
    std::pair<char, unsigned int> ordemInsercaoPesos[26];

    while(std::cin >> ordemInsercao >> prioridade) {
        Arvore arvore;
        for(unsigned int i = 0; i < prioridade.length(); i++) {
            pesosPorLetra[i] = std::pair<char, unsigned int>(prioridade[i], i);
        }

        for(unsigned int i = 0; i < ordemInsercao.length(); i++) {
            for(unsigned int j = 0; j < ordemInsercao.length(); j++) {
                if(ordemInsercao[i] == pesosPorLetra[j].first) {
                    ordemInsercaoPesos[i] = std::pair<char, unsigned int>(ordemInsercao[i], pesosPorLetra[j].second);
                }
            }
        }
        
        for(unsigned int i = 0; i < ordemInsercao.length(); i++) {
            arvore.inserir(ordemInsercaoPesos[i]);
        }

        arvore.printArvore();
        std::cout << "\n";
    }

    return 0;
}

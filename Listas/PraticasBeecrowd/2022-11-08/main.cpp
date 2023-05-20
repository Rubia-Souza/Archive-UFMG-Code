#include <iostream>
#include <string>
#include <vector>

class Assassino {
    public:
        bool estaMorto = false;
        unsigned int quantidadePessoasMortas = 0;
        std::string nome = "";
};

#pragma region .: Nodo :.

class Nodo {
    public:
        Nodo* esquerda = nullptr;
        Nodo* direita = nullptr;
        Assassino assassino;

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

        void printNodo() {
            if(assassino.estaMorto) {
                return;
            }
            else {
                printf("%s %d\n", assassino.nome.c_str(), assassino.quantidadePessoasMortas);
            }

            return;
        }
};

#pragma endregion

#pragma region .: Arvore :.

class Arvore {
    private:
        Nodo* raiz = nullptr;

    public:
        Arvore() {
            raiz = nullptr;
            return;
        }

        virtual ~Arvore() {
            raiz = nullptr;
            return;
        }

        void adicionarAssassinato(std::string nomeAssassino) {
            adicionarAssassinoRecursivo(nomeAssassino, raiz);
            return;
        }

        void adicionarAssassinado(std::string nomeAssassinado) {
            adicionarAssassinadoRecursivo(nomeAssassinado, raiz);
            return;
        }

        void marcarAssassinoMorto(std::string nomeAssassino) {
            marcarAssassinoMortoRecursivo(nomeAssassino, raiz);
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
        void adicionarAssassinoRecursivo(std::string nomeAssassino, Nodo*& nodo) {
            if(nodo == nullptr) {
                nodo = new Nodo();
                nodo->assassino.nome = nomeAssassino;
                nodo->assassino.quantidadePessoasMortas++;
                return;
            }
            else if(nodo->assassino.nome == nomeAssassino) {
                nodo->assassino.quantidadePessoasMortas++;
            }
            else if(nodo->assassino.nome > nomeAssassino) {
                adicionarAssassinoRecursivo(nomeAssassino, nodo->esquerda);
            }
            else if(nodo->assassino.nome < nomeAssassino) {
                adicionarAssassinoRecursivo(nomeAssassino, nodo->direita);
            }

            return;
        }

        void adicionarAssassinadoRecursivo(std::string nomeAssassinado, Nodo*& nodo) {
            if(nodo == nullptr) {
                nodo = new Nodo();
                nodo->assassino.nome = nomeAssassinado;
                nodo->assassino.estaMorto = true;
                return;
            }
            else if(nodo->assassino.nome == nomeAssassinado) {
                nodo->assassino.estaMorto = true;
            }
            else if(nodo->assassino.nome > nomeAssassinado) {
                adicionarAssassinadoRecursivo(nomeAssassinado, nodo->esquerda);
            }
            else if(nodo->assassino.nome < nomeAssassinado) {
                adicionarAssassinadoRecursivo(nomeAssassinado, nodo->direita);
            }

            return;
        }

        void marcarAssassinoMortoRecursivo(std::string nomeAssassino, Nodo* nodo) {
            if(nodo == nullptr) {
                return;
            }

            if(nodo->assassino.nome == nomeAssassino) {
                nodo->assassino.estaMorto = true;
            }
            else if(nodo->assassino.nome < nomeAssassino) {
                marcarAssassinoMortoRecursivo(nomeAssassino, nodo->esquerda);
            }
            else if(nodo->assassino.nome > nomeAssassino) {
                marcarAssassinoMortoRecursivo(nomeAssassino, nodo->direita);
            }

            return;
        }

        void CaminharPosOrdem(Nodo* nodo) {
            if(nodo != nullptr) {
                CaminharPosOrdem(nodo->esquerda);
                nodo->printNodo();
                CaminharPosOrdem(nodo->direita);
            }
        }

        void ApagarRecursivamente(Nodo* nodo) {
            if(nodo != nullptr) {
                ApagarRecursivamente(nodo->esquerda);
                ApagarRecursivamente(nodo->direita);
                delete nodo;
            }
        }
};

int main() {
    char nomeAssassino[200];
    char nomeAssassinado[200];

    Arvore* assassinos = new Arvore();
    while(scanf("%s %s", &nomeAssassino, &nomeAssassinado) != EOF) {
        std::string assassino = nomeAssassino;
        std::string assassinado = nomeAssassinado;
        assassinos->adicionarAssassinato(assassino);
        assassinos->adicionarAssassinado(assassinado);
    }

    printf("HALL OF MURDERERS\n");
    assassinos->printArvore();

    delete assassinos;
    return 0;
}

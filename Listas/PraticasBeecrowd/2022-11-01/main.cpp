#include <iostream>
#include <string>
#include <vector>

#pragma region .: Registro :.

class Registro {
    public:
        std::string nome;
        unsigned int numeroRegistro;
        bool desejaSerAmigo;

        Registro(std::string nome, unsigned int numeroRegistro, bool desejaSerAmigo) {
            this->nome = nome;
            this->numeroRegistro = numeroRegistro;
            this->desejaSerAmigo = desejaSerAmigo;

            return;
        }
};

#pragma endregion

#pragma region .: QuickSort :.

class QuickSort {
    private:
        QuickSort() {}

    public:
        virtual ~QuickSort() {}

        static void ordenarCrescente(std::vector<Registro*>* vetor, const unsigned int tamanho) {
            quickSortCrescente(vetor, 0, tamanho-1);
            return;
        }
    
    private:  
        static void quickSortCrescente(std::vector<Registro*>* vetor, int posicaoInicial, int poiscaoFinal) { 
            int indexEsquerda = 0;
            int indexDireita = 0;

            particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita);

            if (posicaoInicial < indexDireita) {
                quickSortCrescente(vetor, posicaoInicial, indexDireita);
            }

            if (indexEsquerda < poiscaoFinal) {
                quickSortCrescente(vetor, indexEsquerda, poiscaoFinal);
            }

            return;
        }

        static void particionarCrescente(std::vector<Registro*>* vetor, int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            Registro* pivo = vetor->at((*indexEsquerda + *indexDireita) / 2);

            do {
                while (pivo->nome.size() < vetor->at(*indexEsquerda)->nome.size()) {
                    (*indexEsquerda)++;
                }

                while (pivo->nome.size() > vetor->at(*indexDireita)->nome.size()) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    Registro* trocaTemporaria = vetor->at(*indexEsquerda);
                    vetor->at(*indexEsquerda) = vetor->at(*indexDireita);
                    vetor->at(*indexDireita) = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
            
            return;
        }
};

#pragma endregion

#pragma region .: QuickSortAlfabetico :.

class QuickSortAlfabetico {
    private:
        QuickSortAlfabetico() {}

    public:
        virtual ~QuickSortAlfabetico() {}

        static void ordenarCrescente(std::vector<Registro*>* vetor, const unsigned int tamanho) {
            quickSortCrescente(vetor, 0, tamanho-1);
            return;
        }
    
    private:  
        static void quickSortCrescente(std::vector<Registro*>* vetor, int posicaoInicial, int poiscaoFinal) { 
            int indexEsquerda = 0;
            int indexDireita = 0;

            particionarCrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita);

            if (posicaoInicial < indexDireita) {
                quickSortCrescente(vetor, posicaoInicial, indexDireita);
            }

            if (indexEsquerda < poiscaoFinal) {
                quickSortCrescente(vetor, indexEsquerda, poiscaoFinal);
            }

            return;
        }

        static void particionarCrescente(std::vector<Registro*>* vetor, int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            Registro* pivo = vetor->at((*indexEsquerda + *indexDireita) / 2);

            do {
                while (pivo->nome > vetor->at(*indexEsquerda)->nome) {
                    (*indexEsquerda)++;
                }

                while (pivo->nome < vetor->at(*indexDireita)->nome) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    Registro* trocaTemporaria = vetor->at(*indexEsquerda);
                    vetor->at(*indexEsquerda) = vetor->at(*indexDireita);
                    vetor->at(*indexDireita) = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
            
            return;
        }
};

#pragma endregion

int main() {
    const std::string CONFIRMACAO_DESEJA_SER_AMIGO = "YES";
    const std::string IDENTIFICACAO_FIM_ARQUIVO = "FIM";

    std::vector<Registro*> inscricoesSim;
    std::vector<Registro*> inscricoesNao;

    std::string nome = "";
    std::string opcao = "";
    unsigned int quantidadeRegistros = 0;

    std::cin >> nome;
    while(nome != IDENTIFICACAO_FIM_ARQUIVO) {
        std::cin >> opcao;

        bool jaCadastrado = false;
        for(unsigned int i = 0; i < inscricoesSim.size(); i++) {
            if(inscricoesSim[i]->nome == nome) {
                jaCadastrado = true;
                break;
            }
        }
        for(unsigned int i = 0; i < inscricoesNao.size(); i++) {
            if(inscricoesNao[i]->nome == nome) {
                jaCadastrado = true;
                break;
            }
        }

        if(jaCadastrado) {
            std::cin >> nome;
            continue;
        }

        quantidadeRegistros++;
        bool desejaSerAmigo = opcao == CONFIRMACAO_DESEJA_SER_AMIGO;
        if(desejaSerAmigo) {
            inscricoesSim.push_back(new Registro(nome, quantidadeRegistros, desejaSerAmigo));
        }
        else {
            inscricoesNao.push_back(new Registro(nome, quantidadeRegistros, desejaSerAmigo));
        }
        
        std::cin >> nome;
    }

    QuickSort::ordenarCrescente(&inscricoesSim, inscricoesSim.size());
    Registro* vencedor = inscricoesSim[0];
    for(unsigned int i = 1; i < inscricoesSim.size(); i++) {
        if(vencedor->numeroRegistro > inscricoesSim[i]->numeroRegistro && vencedor->nome.size() == inscricoesSim[i]->nome.size()) {
            vencedor = inscricoesSim[i];
        }
    }

    QuickSortAlfabetico::ordenarCrescente(&inscricoesSim, inscricoesSim.size());
    for(unsigned int i = 0; i < inscricoesSim.size(); i++) {
        std::cout << inscricoesSim[i]->nome << "\n";
    }
    
    QuickSortAlfabetico::ordenarCrescente(&inscricoesNao, inscricoesNao.size());
    for(unsigned int i = 0; i < inscricoesNao.size(); i++) {
        std::cout << inscricoesNao[i]->nome << "\n";
    }

    std::cout << "\nAmigo do Habay:\n";
    std::cout << vencedor->nome << "\n";
    return 0;
}

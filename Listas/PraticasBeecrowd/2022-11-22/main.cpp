#include <iostream>
#include <vector>
#include <algorithm>

#pragma region .: QuickSort :.

class QuickSort {
    private:
        QuickSort() {}

    public:
        virtual ~QuickSort() {}

        template<typename T>
        static void ordenarCrescente(T vetor[], const unsigned int tamanho) {
            quickSortCrescente(vetor, 0, tamanho-1);
            return;
        }

        template<typename T>
        static void ordenarDecrescente(T vetor[], const unsigned int tamanho) {
            quickSortDecrescente(vetor, 0, tamanho-1);
            return;
        }
    
    private:
        template<typename T>
        static void quickSortCrescente(T vetor[], int posicaoInicial, int poiscaoFinal) { 
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

        template<typename T>
        static void particionarCrescente(T vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            T pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

            do {
                while (pivo > vetor[*indexEsquerda]) {
                    (*indexEsquerda)++;
                }

                while (pivo < vetor[*indexDireita]) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    T trocaTemporaria = vetor[*indexEsquerda];
                    vetor[*indexEsquerda] = vetor[*indexDireita];
                    vetor[*indexDireita] = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
            
            return;
        }

        template<typename T>
        static void quickSortDecrescente(T vetor[], int posicaoInicial, int poiscaoFinal) { 
            int indexEsquerda = 0;
            int indexDireita = 0;

            particionarDecrescente(vetor, posicaoInicial, poiscaoFinal, &indexEsquerda, &indexDireita);

            if (posicaoInicial < indexDireita) {
                quickSortDecrescente(vetor, posicaoInicial, indexDireita);
            }

            if (indexEsquerda < poiscaoFinal) {
                quickSortDecrescente(vetor, indexEsquerda, poiscaoFinal);
            }

            return;
        }

        template<typename T>
        static void particionarDecrescente(T vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            T pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

            do {
                while (pivo < vetor[*indexEsquerda]) {
                    (*indexEsquerda)++;
                }

                while (pivo > vetor[*indexDireita]) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    T trocaTemporaria = vetor[*indexEsquerda];
                    vetor[*indexEsquerda] = vetor[*indexDireita];
                    vetor[*indexDireita] = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
            
            return;
        }
};

#pragma endregion

int main() {
    unsigned int quantidadeCaixasParafusos = 0;
    unsigned int tamanhoInicialLote = 0;
    unsigned int tamanhoFinalLote = 0;
    unsigned int numeroPesquisa = 0;

    while(std::cin >> quantidadeCaixasParafusos) {
        std::vector<int> tamanhos;
        std::vector<int> mapeamento(101);

        for(unsigned int i = 0; i < quantidadeCaixasParafusos; i++) {
            std::cin >> tamanhoInicialLote >> tamanhoFinalLote;

            for(unsigned int j = tamanhoInicialLote; j <= tamanhoFinalLote; j++) {
                tamanhos.push_back(j);
                mapeamento[j]++;
            }
        }

        std::sort(tamanhos.begin(), tamanhos.end());

        std::cin >> numeroPesquisa;
        if(mapeamento[numeroPesquisa] == 0) {
            std::cout << numeroPesquisa << " not found\n";
        }
        else {
            int entrada = 0;

            for(unsigned int i = 0; i < tamanhos.size(); i++) {
                if(tamanhos[i] == numeroPesquisa) {
                    entrada = i;
                    break;
                }
            }

            std::cout << numeroPesquisa << " found from " << entrada << " to " << entrada + mapeamento[numeroPesquisa] - 1 << "\n";
        }
    }

	return 0;
}

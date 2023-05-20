#include <iostream>
#include <string>

#pragma region .: QuickSort :.

class QuickSort {
    private:
        QuickSort() {}

    public:
        virtual ~QuickSort() {}

        static void ordenarCrescente(std::string vetor[], const unsigned int tamanho) {
            quickSortCrescente(vetor, 0, tamanho-1);
            return;
        }

        static void ordenarDecrescente(std::string vetor[], const unsigned int tamanho) {
            quickSortDecrescente(vetor, 0, tamanho-1);
            return;
        }
    
    private:  
        static void quickSortCrescente(std::string vetor[], int posicaoInicial, int poiscaoFinal) { 
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

        static void particionarCrescente(std::string vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            std::string pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

            do {
                while (pivo > vetor[*indexEsquerda]) {
                    (*indexEsquerda)++;
                }

                while (pivo < vetor[*indexDireita]) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    std::string trocaTemporaria = vetor[*indexEsquerda];
                    vetor[*indexEsquerda] = vetor[*indexDireita];
                    vetor[*indexDireita] = trocaTemporaria;

                    (*indexEsquerda)++;
                    (*indexDireita)--;
                }
            } while(*indexEsquerda <= *indexDireita);
            
            return;
        }

        static void quickSortDecrescente(std::string vetor[], int posicaoInicial, int poiscaoFinal) { 
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

        static void particionarDecrescente(std::string vetor[], int posicaoInicial, int poiscaoFinal, int* indexEsquerda, int* indexDireita) {
            *indexEsquerda = posicaoInicial;
            *indexDireita = poiscaoFinal;

            std::string pivo = vetor[(*indexEsquerda + *indexDireita) / 2];

            do {
                while (pivo < vetor[*indexEsquerda]) {
                    (*indexEsquerda)++;
                }

                while (pivo > vetor[*indexDireita]) {
                    (*indexDireita)--;
                }

                if (*indexEsquerda <= *indexDireita) {
                    std::string trocaTemporaria = vetor[*indexEsquerda];
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

int main()
{
    std::string *numeros = nullptr;
    unsigned int quantidadeNumeros = 0;
    unsigned int quantidadeNumerosRemovidos = 0;

    while (std::cin >> quantidadeNumeros)
    {
        numeros = new std::string[quantidadeNumeros];
        for (unsigned int i = 0; i < quantidadeNumeros; i++)
        {
            std::cin >> numeros[i];
        }

        QuickSort::ordenarCrescente(numeros, quantidadeNumeros);
        for (unsigned int i = 1; i < quantidadeNumeros; i++)
        {
            std::string numeroAnterior = numeros[i - 1];
            std::string numeroAtual = numeros[i];

            for (unsigned int j = 0; j < numeroAnterior.length() && j < numeroAtual.length(); j++)
            {
                if (numeroAnterior[j] == numeroAtual[j])
                {
                    quantidadeNumerosRemovidos++;
                }
                else
                {
                    break;
                }
            }
        }

        std::cout << quantidadeNumerosRemovidos << "\n";
        quantidadeNumerosRemovidos = 0;
        delete[] numeros;
    }

    return 0;
}

#ifndef SELECAO_H
#define SELECAO_H

class Selecao {
    private:
        Selecao() {}
        
    public:
        virtual ~Selecao() {}

        /**
         * @brief Realiaza a ordenação em ordem crescente por meio do algoritmo Seleção
         * 
         * @tparam T É o tipo de dados armazenados no vetor
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         */
        template<typename T>
        static void ordenarCrescente(T* vetor, const unsigned int tamanho) {
            for(unsigned int i = 0; i < tamanho; i++) {
                unsigned int indexMaior = 0;
                for(unsigned int j = 1; j < tamanho-i; j++) {
                    if(vetor[indexMaior] < vetor[j]) {
                        indexMaior = j;
                    }
                }

                T conteudo = vetor[tamanho-i-1];
                vetor[tamanho-i-1] = vetor[indexMaior];
                vetor[indexMaior] = conteudo;
            }

            return;
        }

        /**
         * @brief Realiaza a ordenação em ordem decrescente por meio do algoritmo Seleção
         * 
         * @tparam T É o tipo de dados armazenados no vetor
         * @param vetor É o vetor que será ordenado
         * @param tamanho É o tamanho do vetor que será ordenado
         */
        template<typename T>
        static void ordenarDecrescente(T* vetor, const unsigned int tamanho) {
            for(unsigned int i = 0; i < tamanho; i++) {
                unsigned int indexMenor = 0;
                for(unsigned int j = 1; j < tamanho-i; j++) {
                    if(vetor[indexMenor] > vetor[j]) {
                        indexMenor = j;
                    }
                }
                
                T conteudo = vetor[tamanho-i-1];
                vetor[tamanho-i-1] = vetor[indexMenor];
                vetor[indexMenor] = conteudo;
            }

            return;
        }
};

#endif

#include <string>
#include <iostream>
#include <algorithm>

#include "Set.hpp"

const char COMANDO_INSERIR = 'i';
const char COMANDO_REMOVER = 'r';
const char COMANDO_PERTENCE = 'n';
const char COMANDO_UNIAO = 'u';
const char COMANDO_INTERSECAO = 't';
const char COMANDO_DIFERENCA_SIMETRICA = 'd';
const char COMANDO_IMPRIMIR = 'p';

Set* carregarConjuntoEntrada();

int main(int argc, char** argv){
    int n;
    char comando;
    std::string dado = "";

    std::cin >> n;
    Set* conjunto1 = new Set(1);

    for(int i = 0; i < n; i++){
        std::cin >> comando;

        switch(comando) {
            case(COMANDO_INSERIR): {
                std::cin >> dado;
                conjunto1->inserir(dado);

                break;
            }
            case(COMANDO_REMOVER): {
                std::cin >> dado;
                conjunto1->remover(dado);

                break;
            }
            case(COMANDO_PERTENCE): {
                std::cin >> dado;
                std::transform(dado.begin(), dado.end(), dado.begin(), ::tolower);
                
                if(conjunto1->pertence(dado)) {
                    std::cout << "O elemento " << dado << " pertence ao conjunto!" << std::endl;
                }
                else {
                    std::cout << "O elemento " << dado << " nao pertence ao conjunto!" << std::endl;
                }

                break;
            }
            case(COMANDO_UNIAO): {
                std::cout << "A uniao dos conjuntos e: ";

                Set* conjunto2 = carregarConjuntoEntrada();
                Set* resultadoUniao = conjunto1->uniao(*conjunto2);
                
                resultadoUniao->print();
                
                delete conjunto2;
                delete resultadoUniao;

                break;
            }
            case(COMANDO_INTERSECAO): {
                std::cout << "A intersecao dos conjuntos e: ";

                Set* conjunto2 = carregarConjuntoEntrada();
                Set* resultadoIntersecao = conjunto1->intersecao(*conjunto2);

                resultadoIntersecao->print();

                delete conjunto2;
                delete resultadoIntersecao;

                break;
            }
            case(COMANDO_DIFERENCA_SIMETRICA): {
                std::cout << "A diferenca simetrica dos conjuntos e: ";
                
                Set* conjunto2 = carregarConjuntoEntrada();
                Set* resultadoDiferenca = conjunto1->diferencaSimetrica(*conjunto2);
                
                resultadoDiferenca->print();
                
                delete conjunto2;
                delete resultadoDiferenca;
                
                break;
            }
            case(COMANDO_IMPRIMIR): {
                conjunto1->print();
                break;
            }
            default: {
                break;
            }
        }
    }

    delete conjunto1;

    return 0;
}

Set* carregarConjuntoEntrada() {
    int n;
    std::string dado;
    std::cin >> n;

    Set* conjuntoEntrada = new Set(n);
    for(int i = 0; i < n; i++){
        std::cin >> dado;
        conjuntoEntrada->inserir(dado);
    }

    return conjuntoEntrada;
}

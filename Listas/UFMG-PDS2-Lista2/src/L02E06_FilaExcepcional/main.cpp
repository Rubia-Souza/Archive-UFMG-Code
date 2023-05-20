#include <iostream>
#include <string>

#include "./classes/Exceptions/Exceptions.hpp"
#include "./classes/LimitedQueue/LimitedQueue.hpp"
#include "./avaliacao_basica_excecoes.hpp"

#define INICIALIZAR_FILA 'i'
#define INSERIR_INTEIRO 'p'
#define REMOVER_PRIMEIRO_ELEMENTO 'o'
#define IMPRIMIR_PRIMEIRO_ELEMENTO 'f'
#define IMPRIMIR_ULTIMO_ELEMENTO 'l'
#define IMPRIMIR_FILA 'm'
#define BUSCAR_INTEIRO 'd'
#define AVALIACAO_BASICA 'b'

LimitedQueue* handleInicializarFila();
void handleInserirInteiro(LimitedQueue* queue);
void handleRemoverPrimeiroElemento(LimitedQueue* queue);
void handleImprimirPrimeiroElemento(const LimitedQueue& queue);
void handleImprimirUltimoElemento(const LimitedQueue& queue);
void handleImprimirFila(const LimitedQueue& queue);
void handleBuscarInteiro(const LimitedQueue& queue);
void handleException(const std::string exceptionName);

int main() {
    char option;
    LimitedQueue* queue = nullptr;

    while(std::cin >> option) {
        try {
            switch(option) {
                case(INICIALIZAR_FILA): {
                    if(queue != nullptr) {
                        delete queue;
                    }

                    queue = handleInicializarFila();
                    break;
                }

                case(INSERIR_INTEIRO): {
                    handleInserirInteiro(queue);
                    break;
                }

                case(REMOVER_PRIMEIRO_ELEMENTO): {
                    handleRemoverPrimeiroElemento(queue);
                    break;
                }

                case(IMPRIMIR_PRIMEIRO_ELEMENTO): {
                    handleImprimirPrimeiroElemento(*queue);
                    break;
                }

                case(IMPRIMIR_ULTIMO_ELEMENTO): {
                    handleImprimirUltimoElemento(*queue);
                    break;
                }

                case(IMPRIMIR_FILA): {
                    handleImprimirFila(*queue);
                    break;
                }

                case(BUSCAR_INTEIRO): {
                    handleBuscarInteiro(*queue);
                    break;
                }

                case(AVALIACAO_BASICA): {
                    avaliacao_basica();
                    break;
                }
            }
        }
        catch(Exceptions::CustomException& exp) {
            handleException(exp.getName());
        }
    }

    delete queue;
    return 0;
}

LimitedQueue* handleInicializarFila() {
    unsigned int maxSize = 0;
    std::cin >> maxSize;

    return new LimitedQueue(maxSize);
}

void handleInserirInteiro(LimitedQueue* queue) {
    int value = 0;
    std::cin >> value;

    queue->push_back(value);
    return;
}

void handleRemoverPrimeiroElemento(LimitedQueue* queue) {
    queue->pop_front();
    return;
}

void handleImprimirPrimeiroElemento(const LimitedQueue& queue) {
    int firstValue = queue.front();
    std::cout << firstValue << "\n";
    return;
}

void handleImprimirUltimoElemento(const LimitedQueue& queue) {
    int lastValue = queue.back();
    std::cout << lastValue << "\n";
    return;
}

void handleImprimirFila(const LimitedQueue& queue) {
    queue.print();
    return;
}

void handleBuscarInteiro(const LimitedQueue& queue) {
    int value = 0;
    std::cin >> value;

    unsigned int position = queue.find(value);
    std::cout << position << "\n";

    return;
}

void handleException(const std::string exceptionName) {
    std::cout << "Excecao: " << exceptionName << "\n";
    return;
}

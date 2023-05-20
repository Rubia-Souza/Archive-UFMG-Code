#include <iostream>
#include <ctime>

#include "Registro.h"
#include "Utils.h"
#include "QuickSort.h"
#include "QuickSortMediana.h"
#include "QuickSortSelecao.h"
#include "QuickSortIterativo.h"
#include "QuickSortIterativoInteligente.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "DadosDesempenho.h"

#define MAXIMO_OPCOES 7

enum Opcoes {
    Sair = 0,
    QuickSortPadrao = 1,
    QuickSortMediana = 2,
    QuickSortSelecao = 3,
    QuickSortPilha = 4,
    QuickSortPilhaInteligente = 5,
    MergeSort = 6,
    HeapSort = 7,
};

void configurarSementeAleatoria();
void printOpcoes();
unsigned int getOpcao();
void executarTeste(const unsigned int opcao);
void testQuickSortPadrao();
unsigned int getQuantidadeRegistros();
void printChavesVetor(const Registro vetor[], const unsigned int tamanaho);
void testQuickSortMediana();
unsigned int getQuantidadePivos();
void testQuickSortSelecao();
unsigned int getTamanhoMinimo();
void testQuickSortIterativo();
void testQuickSortIterativoInteligente();
void testMergeSort();
void testHeapSort();

int main(int argc, char* argv[]) {
    configurarSementeAleatoria();
    unsigned int opcao = 0;

    do {
        printOpcoes();
        opcao = getOpcao();

        executarTeste(opcao);
    } while(opcao != 0);

    return 0;
}

void configurarSementeAleatoria() {
    srand((unsigned) time(NULL));
    return;
}

void printOpcoes() {
    std::cout << "\n[0] Sair\n"
              << "[1] QuickSort padrao\n"
              << "[2] QuickSort mediana\n"
              << "[3] QuickSort selecao\n"
              << "[4] QuickSort com pilha\n"
              << "[5] QuickSort com pilha inteligente\n"
              << "[6] MergeSort\n"
              << "[7] HeapSort\n";
    return;
}

unsigned int getOpcao() {
    std::cout << "Digite uma opcao: ";
    unsigned int opcao = 0;

    do {
        std::cin >> opcao;

        if(opcao > MAXIMO_OPCOES) {
            std::cout << "\nDigite uma opcao valida, entre 0 e " << MAXIMO_OPCOES << ": ";
        }
    } while(opcao > MAXIMO_OPCOES);

    return opcao;
}

void executarTeste(const unsigned int opcao) {
    switch(opcao) {
        case(Opcoes::QuickSortPadrao): {
            testQuickSortPadrao();
            break;
        }
        case(Opcoes::QuickSortMediana): {
            testQuickSortMediana();
            break;
        }
        case(Opcoes::QuickSortSelecao): {
            testQuickSortSelecao();
            break;
        }
        case(Opcoes::QuickSortPilha): {
            testQuickSortIterativo();
            break;
        }
        case(Opcoes::QuickSortPilhaInteligente): {
            testQuickSortIterativoInteligente();
            break;
        }
        case(Opcoes::MergeSort): {
            testMergeSort();
            break;
        }
        case(Opcoes::HeapSort): {
            testHeapSort();
            break;
        }
    }

    return;
}

void testQuickSortPadrao() {
    std::cout << "\n----- Teste Quick Sort Padrao -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    QuickSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

unsigned int getQuantidadeRegistros() {
    unsigned int quantidadeRegistros = 0;

    std::cout << "\nDigite a quantidade de registros: ";
    std::cin >> quantidadeRegistros;

    return quantidadeRegistros;
}

void printChavesVetor(const Registro vetor[], const unsigned int tamanaho) {
    for(unsigned int i = 0; i < tamanaho; i++) {
        std::cout << "[" << i << "] " << vetor[i].chave << "\n";
    }
    std::cout << "\n";

    return;
}

void testQuickSortMediana() {
    std::cout << "\n----- Teste Quick Sort Mediana -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    unsigned int quantidadePivos = getQuantidadePivos();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    QuickSortMediana::ordenarCrescente(registros, quantidadeRegistros, quantidadePivos, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

unsigned int getQuantidadePivos() {
    unsigned int quantidadePivos = 0;

    std::cout << "\nDigite a quantos pivos serao selecionados para a mediana: ";
    std::cin >> quantidadePivos;

    return quantidadePivos;
}

void testQuickSortSelecao() {
    std::cout << "\n----- Teste Quick Sort Selecao -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    unsigned int tamanhoMinimo = getTamanhoMinimo();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    QuickSortSelecao::ordenarCrescente(registros, quantidadeRegistros, tamanhoMinimo, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

unsigned int getTamanhoMinimo() {
    unsigned int tamanhoMinimo = 0;

    std::cout << "\nDigite o tamanho minimo para iniciar a ordenacao por selecao: ";
    std::cin >> tamanhoMinimo;

    return tamanhoMinimo;
}

void testQuickSortIterativo() {
    std::cout << "\n----- Teste Quick Sort Iterativo -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    QuickSortIterativo::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

void testQuickSortIterativoInteligente() {
    std::cout << "\n----- Teste Quick Sort Iterativo Inteligente -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    QuickSortIterativoInteligente::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

void testMergeSort() {
    std::cout << "\n----- Teste Merge Sort -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    MergeSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

void testHeapSort() {
    std::cout << "\n----- Teste Heap Sort -----\n";
    unsigned int quantidadeRegistros = getQuantidadeRegistros();
    DadosDesempenho dadosDesempenho;

    Registro* registros = new Registro[quantidadeRegistros];
    for(unsigned int i = 0; i < quantidadeRegistros; i++) {
        registros[i].chave = Utils::gerarNumeroInteiroAleatorio();
    }

    /*std::cout << "--- Vetor antes ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    HeapSort::ordenarCrescente(registros, quantidadeRegistros, dadosDesempenho);

    /*std::cout << "--- Vetor apos ordenacao: \n";
    printChavesVetor(registros, quantidadeRegistros);*/

    Utils::verificarOrdenacaoCrescente(registros, quantidadeRegistros);
    dadosDesempenho.print();

    delete[] registros;
    return;
}

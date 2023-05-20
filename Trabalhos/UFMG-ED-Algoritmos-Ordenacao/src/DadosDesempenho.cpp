#include <iostream>

#include "DadosDesempenho.h"

DadosDesempenho::DadosDesempenho() {}
DadosDesempenho::~DadosDesempenho() {}

void DadosDesempenho::print() const {
    std::cout << "\nQuantidade de Comparacoes: " << quantidadeComparacoes;
    std::cout << "\nQuantidade de Atribuicoes: " << quantidadeAtribuicoes;

    return;
}

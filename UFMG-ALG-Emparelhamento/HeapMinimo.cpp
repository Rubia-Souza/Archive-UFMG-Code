#include <iostream>
#include <string>

#include "HeapMinimo.hpp"

#include "VerticeGuloso.hpp"

const std::string MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO = "[ERROR]: Um elemento tentou ser atualizado com o heap vazio.";
const std::string MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO = "[ERROR]: O tamanho maximo do heap foi atingido e um elemento foi inserido.";
const std::string MENSAGEM_ERRO_REMOVER_HEAP_VAZIO = "[ERROR]: Um elemento foi removido com o heap vazio.";
const std::string MENSAGEM_ERRO_ATUALIZACAO_INVALIDA = "[ERROR]: Um par tentou ser atualizado para um valor superior.";

HeapMinimo::HeapMinimo(const int tamanhoMaximo){
    this->tamanhoMaximo = tamanhoMaximo;
    pares = new std::vector<std::pair<VerticeGuloso*, unsigned int>>(tamanhoMaximo);
    
    return;
}

HeapMinimo::~HeapMinimo(){
    delete pares;
    return;
}

void HeapMinimo::adicionar(VerticeGuloso* vertice) {
    if(tamanhoOcupado >= tamanhoMaximo) {
        std::cout << MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO;
        throw MENSAGEM_ERRO_TAMANHO_MAXIMO_ATINGIDO;
    }

    tamanhoOcupado++;

    int indexInsercao = tamanhoOcupado - 1;
    (*pares)[indexInsercao] = std::pair<VerticeGuloso*, unsigned int>(vertice, vertice->getQuantidadePossibilidades());

    int indexAjuste = indexInsercao;
    while(indexAjuste != 0 && (*pares)[getPai(indexAjuste)].second > (*pares)[indexAjuste].second) {
        std::pair<VerticeGuloso*, unsigned int> temporario = (*pares)[getPai(indexAjuste)];
        (*pares)[getPai(indexAjuste)] = (*pares)[indexAjuste];
        (*pares)[indexAjuste] = temporario;
        
        indexAjuste = getPai(indexAjuste);
    }
    
    return;
}

void HeapMinimo::atualizar(VerticeGuloso* vertice) {
    if(estaVazio()) {
        std::cout << MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO;
        throw MENSAGEM_ERRO_ATUALIZAR_HEAP_VAZIO;
    }

    int indexVerticeAtualizado = 0;
    for(std::pair<VerticeGuloso*, unsigned int> par : *pares) {
        if(par.first->getNome() == vertice->getNome()) {
            break;
        }
        indexVerticeAtualizado++;
    }

    if(vertice->getQuantidadePossibilidades() > (*pares)[indexVerticeAtualizado].second) {
        std::cout << MENSAGEM_ERRO_ATUALIZACAO_INVALIDA;
        throw MENSAGEM_ERRO_ATUALIZACAO_INVALIDA;
    }
    
    (*pares)[indexVerticeAtualizado].second = vertice->getQuantidadePossibilidades();
    
    int indexAjuste = indexVerticeAtualizado;
    while(indexAjuste != 0 && (*pares)[getPai(indexAjuste)].second > (*pares)[indexAjuste].second) {
        std::pair<VerticeGuloso*, unsigned int> temporario = (*pares)[getPai(indexAjuste)];
        (*pares)[getPai(indexAjuste)] = (*pares)[indexAjuste];
        (*pares)[indexAjuste] = temporario;
        
        indexAjuste = getPai(indexAjuste);
    }
    
    return;
}

VerticeGuloso* HeapMinimo::popMenor() {
    if(estaVazio()) {
        std::cout << MENSAGEM_ERRO_REMOVER_HEAP_VAZIO;
        throw MENSAGEM_ERRO_REMOVER_HEAP_VAZIO;
    }
    
    if(tamanhoOcupado == 1) {
        tamanhoOcupado--;
        return (*pares)[0].first;
    }

    VerticeGuloso* menor = (*pares)[0].first;
    (*pares)[0] = (*pares)[tamanhoOcupado - 1];

    tamanhoOcupado--;
    ajustarHeap(0);
    
    return menor;
}

void HeapMinimo::ajustarHeap(const int indexPai) {
    int indexFilhoEsquerdo = getFilhoEsquerdo(indexPai);
    int indexFilhoDireito = getFilhoDireito(indexPai);
    int indexMenor = indexPai;

    if(indexFilhoEsquerdo < tamanhoOcupado && (*pares)[indexFilhoEsquerdo].second < (*pares)[indexMenor].second) {
        indexMenor = indexFilhoEsquerdo;
    }

    if(indexFilhoDireito < tamanhoOcupado && (*pares)[indexFilhoDireito].second < (*pares)[indexMenor].second) {
        indexMenor = indexFilhoDireito;
    }

    if(indexMenor == indexPai) {
        return;
    }

    std::pair<VerticeGuloso*, unsigned int> temporario = (*pares)[indexPai];
    (*pares)[indexPai] = (*pares)[indexMenor];
    (*pares)[indexMenor] = temporario;
    
    ajustarHeap(indexMenor);

    return;
}

bool HeapMinimo::estaVazio() const {
    return tamanhoOcupado <= 0;
}

int HeapMinimo::getPai(const int index) const {
    return ((index - 1) / 2);
}

int HeapMinimo::getFilhoDireito(const int index) const {
    return ((2 * index) + 2);
}

int HeapMinimo::getFilhoEsquerdo(const int index) const {
    return ((2 * index) + 1);
}

void HeapMinimo::printHeap(){
    int power = 0;
    int value = 1;
    for(int i = 0; i < tamanhoOcupado; i++){
        if(i == value){
            std::cout << std::endl;
            power += 1;
            value += (1 << power);
        }
        std::cout << "(" << (*pares)[i].first->getNome() << ", " << (*pares)[i].second << ") | ";
    }
    std::cout << std::endl;
}
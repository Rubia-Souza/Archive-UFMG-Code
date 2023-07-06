#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

#include "SolucaoGulosa.hpp"

#include "GrafoGuloso.hpp"
#include "HeapMinimo.hpp"

/* Solução:
 * 1 Adiciona os empregos no heap minimo ordenando de acordo com a quantidade de pessoas aptas aquela vaga -- O(E*log(E))
 * 2 Comecando pelo emprego com menos pessoas -- O(E)
 *  2.1 Selecionar a pessoa que tem menos possibilidades de emprego e que ainda não foi agrupada -- O(T) -- Visitado uma vez seria O(m) com o while
 *  2.2 Agrupar os dois e marcá-los como removidos/agrupados
 *  2.3 Para cada emprego da pessoa escolhida -- O(E) -- Visitado uma vez seria O(m) com o while
 *      2.3.1 Decrementar a quantidade de pessoas aptas aquela vaga
 *      2.3.2 Atualizar vaga no heap -- O(log(E))
 *  2.4 Para cada pessoa apta para o emprego escolhido -- O(T) -- Visitado uma vez seria O(m) com o while
 *      2.4.1 Decrementar a quantidade de empregos aptos
 *  2.5 Repetir para cada emprego ainda no heap (Observação: Cada emprego é visitado apenas uma vez, assim como as arestas que saem dele e do trabalhador que foi escolhido)
 * 
 * Complexidade: O(E*log(E)) + O(m) + O(m*log(E)) + O(m) = O((m + E) * log(E)) = O((m + n) * log(n))
 * 
 * E = Quantidade Empregos
 * T = Quantidade Trabalhadores
 * 
 * n = Quantidade de vértices. n = E + T
 * m = Quantidade de arestas. m = E * T
 */

SolucaoGulosa::SolucaoGulosa() {}
SolucaoGulosa::~SolucaoGulosa() {}

unsigned int SolucaoGulosa::EncontrarMaximumMatchingComPrioridade(GrafoGuloso* grafo) {
    std::unordered_map<std::string, VerticeGuloso*>* listaEmpregos = grafo->getListaEmpregos();
    std::unordered_map<std::string, bool> registroAgrupados;

    HeapMinimo heap(listaEmpregos->size());
    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = listaEmpregos->begin(); iterator != listaEmpregos->end(); iterator++) {
        heap.adicionar(iterator->second);
        registroAgrupados[iterator->first] = false;
    }

    std::unordered_map<std::string, VerticeGuloso*>* listaTrabalhadores = grafo->getListaTrabalhadores();
    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = listaTrabalhadores->begin(); iterator != listaTrabalhadores->end(); iterator++) {
        registroAgrupados[iterator->first] = false;
    }

    unsigned int quantidadeAgrupamentos = 0;

    while(!heap.estaVazio()) {
        VerticeGuloso* empregoMenor = heap.popMenor();
        registroAgrupados[empregoMenor->getNome()] = true;

        if(empregoMenor->getQuantidadePossibilidades() <= 0) {
            continue;
        }

        VerticeGuloso* trabalhadorMenor = nullptr;
        std::vector<VerticeGuloso*>* trabalhadores = empregoMenor->getVizinhos();
        for(VerticeGuloso* trabalhador : *trabalhadores) {
            if(registroAgrupados[trabalhador->getNome()]) {
                continue;
            }

            if(trabalhadorMenor == nullptr || trabalhadorMenor->getQuantidadePossibilidades() > trabalhador->getQuantidadePossibilidades()) {
                trabalhadorMenor = trabalhador;
            }
        }

        if(trabalhadorMenor == nullptr) {
            continue;
        }

        registroAgrupados[trabalhadorMenor->getNome()] = true;
        quantidadeAgrupamentos++;

        for(VerticeGuloso* trabalhador : *trabalhadores) {
            if(registroAgrupados[trabalhador->getNome()]) {
                continue;
            }

            trabalhador->setQuantidadePossibilidades(trabalhador->getQuantidadePossibilidades() - 1);
        }

        std::vector<VerticeGuloso*>* empregosPossiveisTrabalhadorMenor = trabalhadorMenor->getVizinhos();
        for(VerticeGuloso* emprego : *empregosPossiveisTrabalhadorMenor) {
            if(registroAgrupados[emprego->getNome()]) {
                continue;
            }

            emprego->setQuantidadePossibilidades(emprego->getQuantidadePossibilidades() - 1);
            heap.atualizar(emprego);
        }
    }

    return quantidadeAgrupamentos;
}

unsigned int SolucaoGulosa::EncontrarMaximumMatchingSemPrioridade(GrafoGuloso* grafo) {
    std::unordered_map<std::string, VerticeGuloso*>* listaEmpregos = grafo->getListaEmpregos();
    std::unordered_map<std::string, bool> registroAgrupados;

    std::queue<VerticeGuloso*> fila;
    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = listaEmpregos->begin(); iterator != listaEmpregos->end(); iterator++) {
        fila.push(iterator->second);
        registroAgrupados[iterator->first] = false;
    }

    std::unordered_map<std::string, VerticeGuloso*>* listaTrabalhadores = grafo->getListaTrabalhadores();
    for(std::unordered_map<std::string, VerticeGuloso*>::iterator iterator = listaTrabalhadores->begin(); iterator != listaTrabalhadores->end(); iterator++) {
        registroAgrupados[iterator->first] = false;
    }

    unsigned int quantidadeAgrupamentos = 0;

    while(!fila.empty()) {
        VerticeGuloso* empregoAtual = fila.front();
        fila.pop();
        registroAgrupados[empregoAtual->getNome()] = true;

        VerticeGuloso* trabalhadorDisponivel = nullptr;
        std::vector<VerticeGuloso*>* trabalhadores = empregoAtual->getVizinhos();
        for(VerticeGuloso* trabalhador : *trabalhadores) {
            if(registroAgrupados[trabalhador->getNome()]) {
                continue;
            }

            trabalhadorDisponivel = trabalhador;
            break;
        }

        if(trabalhadorDisponivel == nullptr) {
            continue;
        }

        registroAgrupados[trabalhadorDisponivel->getNome()] = true;
        quantidadeAgrupamentos++;
    }

    return quantidadeAgrupamentos;
}
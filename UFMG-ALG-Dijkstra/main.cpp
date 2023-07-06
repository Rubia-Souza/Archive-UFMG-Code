#include <iostream>
#include <vector>
#include <string>

#include "Graph.hpp"
#include "Vertice.hpp"
#include "Dijkstra.hpp"

#define MAXIMO_ESTRADAS 100000
#define MINIMO_ESTRADAS 1

#define MAXIMO_CIDADES 10000
#define MINIMO_CIDADES 2

#define MENOR_ID_CIDADE 1

#define MINIMO_DISTANCIA 0
#define MAXIMO_DISTANCIA 10000

const std::string MENSAGEM_ERRO_QUANTIDADE_CIDADES_INVALIDA = "[ERROR]: A quantidade de cidades informadas e invalida.";
const std::string MENSAGEM_ERRO_QUANTIDADE_ESTRADAS_INVALIDA = "[ERROR]: A quandiade de estradas informadas e invalida.";
const std::string MENSAGEM_ERRO_IDENTIFICADOR_CIDADE_INVALIDO = "[ERROR]: Identificador da cidade informado invalido.";
const std::string MENSAGEM_ERRO_DISATANCIA_INVALIDA = "[ERROR]: Distancia entre cidades informada invalida.";

int main(int argc, char const *argv[]) {
    unsigned int quantidadeCidades = 0;
    unsigned int quantidadeEstradas = 0;

    std::cin >> quantidadeCidades >> quantidadeEstradas;
    if(quantidadeCidades < MINIMO_CIDADES || quantidadeCidades > MAXIMO_CIDADES) {
        std::cout << MENSAGEM_ERRO_QUANTIDADE_CIDADES_INVALIDA;
        throw MENSAGEM_ERRO_QUANTIDADE_CIDADES_INVALIDA;
    }

    if(quantidadeEstradas < MINIMO_ESTRADAS || quantidadeEstradas > MAXIMO_ESTRADAS) {
        std::cout << MENSAGEM_ERRO_QUANTIDADE_CIDADES_INVALIDA;
        throw MENSAGEM_ERRO_QUANTIDADE_ESTRADAS_INVALIDA;
    }

    Graph grafo(quantidadeCidades);

    for(unsigned int i = 0; i < quantidadeEstradas; i++) {
        unsigned int idCidade1 = 0;
        unsigned int idCidade2 = 0;
        unsigned int distancia = 0;

        std::cin >> idCidade1 >> idCidade2 >> distancia;
        if(idCidade1 < MENOR_ID_CIDADE || idCidade1 > MAXIMO_CIDADES) {
            std::cout << MENSAGEM_ERRO_IDENTIFICADOR_CIDADE_INVALIDO;
            throw MENSAGEM_ERRO_IDENTIFICADOR_CIDADE_INVALIDO;
        }

        if(idCidade2 < MENOR_ID_CIDADE || idCidade2 > MAXIMO_CIDADES) {
            std::cout << MENSAGEM_ERRO_IDENTIFICADOR_CIDADE_INVALIDO;
            throw MENSAGEM_ERRO_IDENTIFICADOR_CIDADE_INVALIDO;
        }

        if(distancia < MINIMO_DISTANCIA || distancia > MAXIMO_DISTANCIA) {
            std::cout << MENSAGEM_ERRO_DISATANCIA_INVALIDA;
            throw MENSAGEM_ERRO_DISATANCIA_INVALIDA;
        }

        idCidade1 = idCidade1 - 1;
        idCidade2 = idCidade2 - 1;

        grafo.adicionarAresta(idCidade1, idCidade2, distancia);
    }

    Vertice* verticeInicial = (*grafo.getListaVertices())[0];
    Vertice* verticeFinal = (*grafo.getListaVertices())[quantidadeCidades - 1];

    int valorMenorCaminho = Dijkstra::EncontrarMenorCaminho(&grafo, verticeInicial, verticeFinal);

    std::cout << valorMenorCaminho << "\n";

    return 0;
}
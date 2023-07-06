#include <iostream>
#include <string>

#include "GrafoGuloso.hpp"
#include "GrafoExato.hpp"
#include "SolucaoGulosa.hpp"
#include "SolucaoExata.hpp"

#define MINIMO_USUARIOS 2
#define MAXIMO_USUARIOS 10000

#define MINIMO_EMPREGOS 1
#define MAXIMO_EMPREGOS 10000

#define MINIMO_QUALIFICACOES 1

const std::string MENSAGEM_ERRO_QUANTIDADE_INVALIDA_USUARIOS = "[ERROR] A quantidade de usuarios informada e invalida.";
const std::string MENSAGEM_ERRO_QUANTIDADE_INVALIDA_EMPREGOS = "[ERROR] A quantidade de ofertas de emprego informada e invalida.";
const std::string MENSAGEM_ERRO_QUANTIDADE_INVALIDA_QUALIFICACOES = "[ERROR] A quantidade de qualificacoes (usuario-emprego) informada e invalida.";

void aplicarSolucaoGulosa(GrafoGuloso& grafo);
void aplicarSolucaoExata(GrafoExato& grafo);

int main(int argc, char const *argv[]) {
    unsigned int quantidadeUsuarios = 0;
    unsigned int quantidadeOfertasEmprego = 0;
    unsigned int quantidadeQualificacoes = 0;

    std::cin >> quantidadeUsuarios >> quantidadeOfertasEmprego >> quantidadeQualificacoes;
    if(quantidadeUsuarios < MINIMO_USUARIOS || quantidadeUsuarios > MAXIMO_USUARIOS) {
        std::cout << MENSAGEM_ERRO_QUANTIDADE_INVALIDA_USUARIOS << std::endl;
        throw MENSAGEM_ERRO_QUANTIDADE_INVALIDA_USUARIOS;
    }

    if(quantidadeOfertasEmprego < MINIMO_EMPREGOS || quantidadeOfertasEmprego > MAXIMO_EMPREGOS) {
        std::cout << MENSAGEM_ERRO_QUANTIDADE_INVALIDA_EMPREGOS << std::endl;
        throw MENSAGEM_ERRO_QUANTIDADE_INVALIDA_EMPREGOS;
    }

    const unsigned int MAXIMO_QUALIFICACOES = quantidadeOfertasEmprego * quantidadeUsuarios;
    if(quantidadeQualificacoes < MINIMO_QUALIFICACOES || quantidadeQualificacoes > MAXIMO_QUALIFICACOES) {
        std::cout << MENSAGEM_ERRO_QUANTIDADE_INVALIDA_QUALIFICACOES << std::endl;
        throw MENSAGEM_ERRO_QUANTIDADE_INVALIDA_QUALIFICACOES;
    }
    
    GrafoGuloso grafoGuloso;
    GrafoExato grafoExato;

    for(unsigned int i = 0; i < quantidadeQualificacoes; i++) {
        std::string nomeTrabalhador = "";
        std::string nomeEmprego = "";
        std::cin >> nomeTrabalhador >> nomeEmprego;

        grafoGuloso.adicionarTrabalhador(nomeTrabalhador);
        grafoGuloso.adicionarEmprego(nomeEmprego);

        grafoGuloso.adicionarQualificacao(nomeEmprego, nomeTrabalhador);

        grafoExato.adicionarTrabalhador(nomeTrabalhador);
        grafoExato.adicionarEmprego(nomeEmprego);

        grafoExato.adicionarQualificacao(nomeEmprego, nomeTrabalhador);
    }

    aplicarSolucaoGulosa(grafoGuloso);
    aplicarSolucaoExata(grafoExato);

    return 0;
}

/** 
 * @details A implementação com prioridade executou com um tempo próximo
 * ao da solução sem prioridade e teve uma precisão maior, sendo que
 * ambas tiveram um tempo inferior a 1s em cada caso de teste. Uma vez que o 
 * incremento de complexidade da primeira para a segunda é apenas logarítmico, 
 * decidi manter a solução com prioridade para ter mais precisão.
 * 
 * Caso queria testar a outra solução, basta comentar a linha 81 e descomentar a 82.
 */
void aplicarSolucaoGulosa(GrafoGuloso& grafo) {
    unsigned int quantidadeMaxima = SolucaoGulosa::EncontrarMaximumMatchingComPrioridade(&grafo);
    // unsigned int quantidadeMaxima = SolucaoGulosa::EncontrarMaximumMatchingSemPrioridade(&grafo);

    std::cout << "Guloso: " << quantidadeMaxima << std::endl;

    return;
}

/** 
 * @details O tempo de execução da implementação do algoritmo de fluxo com Edmonds Karp
 * foi maior do que utilizando a de Ford-Fulkerson. A fim de cumprir a restrição de que cada 
 * caso de teste execute em no máximo 1s, o algoritmo de Ford Fulkerson foi mantido, pois 
 * apenas ele conseguia chegar num tempo mais próximo do especificado para o caso de teste 13.
 * 
 * Caso queira testar a outra solução, basta comentar a linha 98 e descomentar a 99.
 */
void aplicarSolucaoExata(GrafoExato& grafo) {
    unsigned int quantidadeMaxima = SolucaoExata::EncontrarMaximumMatchingFordFulkerson(&grafo);
    // unsigned int quantidadeMaxima = SolucaoExata::EncontrarMaximumMatchingEdmondsKarp(&grafo);

    std::cout << "Exato: " << quantidadeMaxima << std::endl;

    return;
}
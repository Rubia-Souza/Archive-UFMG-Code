#include <vector>
#include <algorithm>

#include "SeparadorLigas.hpp"
#include "SeparadorLigasBottomUp.hpp"

#include "Constantes.hpp"

SeparadorLigasBottomUp::SeparadorLigasBottomUp() : SeparadorLigas() {}
SeparadorLigasBottomUp::~SeparadorLigasBottomUp() {}

/**
 * @details Algoritmo irá executar de 1 até "d", sendo "d" a demanda informada, no for mais externo
 * Para cada iteração nesse for, ele irá verificar cada liga metálica que pode ser adicionada para 
 * atender a demanda atual. Assim, ele irá executar "n" vezes, sendo "n" a quantidade de ligas
 * informadas.
 * 
 * Portanto, a complexidade será: O(n*d)
 */
unsigned int SeparadorLigasBottomUp::Separar(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas) const {
    std::vector<unsigned int> registroResultados(demanda + 1, INFINITO);
    registroResultados[0] = 0;

    for(unsigned int demandaAtual = 1; demandaAtual <= demanda; demandaAtual++) {
        unsigned int minimo = INFINITO;

        for(unsigned int ligaAtual : ligasMetalicas) {
            if(ligaAtual > demandaAtual) {
                continue;
            }

            unsigned int subDemanda = demandaAtual - ligaAtual;
            minimo = std::min(minimo, 1 + registroResultados[subDemanda]);
        }

        registroResultados[demandaAtual] = minimo;
    }

    return registroResultados[demanda];
}
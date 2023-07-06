#include <vector>
#include <algorithm>

#include "SeparadorLigas.hpp"
#include "SeparadorLigasTopDown.hpp"

#include "Constantes.hpp"

SeparadorLigasTopDown::SeparadorLigasTopDown() : SeparadorLigas() {}
SeparadorLigasTopDown::~SeparadorLigasTopDown() {}

unsigned int SeparadorLigasTopDown::Separar(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas) const {
    std::vector<unsigned int> registroResultados(demanda + 1, INFINITO);
    registroResultados[0] = 0;

    return SepararRecursivo(demanda, ligasMetalicas, registroResultados);
}

/**
 * @details Ocorrerá "d" chamada recursivas no pior caso, que serão as chamadas que o algoritmo tenta
 * preencher toda a demanda utilizando apenas ligas metálicas de tamanho 1.
 * Para cada uma dessa chamadas, haverá um custo de O(n) para verificar cada uma das ligas metálicas
 * disponíveis.
 * 
 * Assim, a complexidade será: O(d*n), sendo "d" a demanda e "n" a quantidade tamanhos de ligas
 * 
 * Observação: A complexidade não será maior, pois estamos utilizando programação dinâmica para 
 * armazenar os resultados anteriores. Assim, chamadas desnecessárias são evitadas ao adicionar
 * a verificação de uma demanda já ter sido calculada no registro de resultado.
 */
unsigned int SeparadorLigasTopDown::SepararRecursivo(const unsigned int demanda, const std::vector<unsigned int>& ligasMetalicas, std::vector<unsigned int>& registroResultados) const {
    if(demanda == 0) {
        return 0;
    }

    if(registroResultados[demanda] != INFINITO) {
        return registroResultados[demanda];
    }

    unsigned int minimo = INFINITO;
    for(unsigned int ligaAtual : ligasMetalicas) {
        if(ligaAtual > demanda) {
            continue;
        }

        unsigned int solucaoMenor = SepararRecursivo(demanda - ligaAtual, ligasMetalicas, registroResultados);
        minimo = std::min(minimo, solucaoMenor + 1);
    }

    registroResultados[demanda] = minimo;
    return minimo;
}
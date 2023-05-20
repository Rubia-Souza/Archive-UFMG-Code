#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "Registro.h"

namespace Utils {
    /**
     * @brief Gera uma string alfanumérica aleatória
     * 
     * @param tamanho É o tamanho da string que será gerada
     * @return std::string É a string aleatória resultante
     */
    std::string gerarStringAleatoria(const unsigned int tamanho);

    /**
     * @brief Gera um número inteiro aleatório em uma determinada faixa
     * 
     * @param valorInicial É o menor valor que pode ser gerado
     * @param valorFinal É o maior valor que pode ser gerado
     * @return int É o número interio aleatório gerado
     */
    int gerarNumeroInteiroAleatorioEmUmaFaixa(const int valorInicial, const int valorFinal);

    /**
     * @brief Gera um número inteiro aleatório em uma determinada faixa
     * 
     * @return int É o número interio aleatório gerado
     */
    int gerarNumeroInteiroAleatorio();

    /**
     * @brief Gera um número float aleatório em uma determinada faixa
     * 
     * @param valorInicial É o menor valor que pode ser gerado
     * @param valorFinal É o maior valor que pode ser gerado
     * @return float É o número float aleatório gerado
     */
    float gerarNumeroFloatAleatorioEmUmaFaixa(const float valorInicial, const float valorFinal);

    /**
     * @brief Gera um número float aleatório em uma determinada faixa
     * 
     * @return float É o número float aleatório gerado
     */
    float gerarNumeroFloatAleatorio();

    /**
     * @brief Gera um registro com todos atributos preenchidos aleatoreamente
     * 
     * @return Registro* É o registro aleatório criado
     */
    Registro* gerarRegistroAelatorio();

    /**
     * @brief Verifica se um vetor está ordenado de forma crescente
     * 
     * @param vetor É o vetor que será verificado
     * @param tamanaho É o tamanho do vetor que será verificado
     */
    void verificarOrdenacaoCrescente(Registro vetor[], const unsigned int tamanaho);

    /**
     * @brief Verifica se um vetor está ordenado de forma decrescente
     * 
     * @param vetor É o vetor que será verificado
     * @param tamanaho É o tamanho do vetor que será verificado
     */
    void verificarOrdenacaoDecrescente(Registro vetor[], const unsigned int tamanaho);
}

#endif

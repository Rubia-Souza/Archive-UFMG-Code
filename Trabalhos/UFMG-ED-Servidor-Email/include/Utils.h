#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    /**
     * @brief Substitui uma parte de uma string por uma outra
     * 
     * @param referencia Consiste na string que será alterada
     * @param alvo É a parte da string que será substituida
     * @param conteudo É o valor que será inserido na parte que será substituida da string
     * @return std::string É a string resultante da substituição
     */
    std::string replace(const std::string& referencia, const std::string& alvo, const std::string& conteudo);

    /**
     * @brief Converte todos os caracteres de uma determinada string para maiúsculos
     * 
     * @param referencia É a string que será usada de referência
     * @return std::string É a string resultante com todos caracteres maiúsculos
     */
    std::string toUpper(const std::string& referencia);

    /**
     * @brief Remove todos os espaços presentes no final de uma string
     * 
     * @param referencia É a string que terá todos os espaços no fim removidos
     */
    void trimEnd(std::string& referencia);
};

#endif

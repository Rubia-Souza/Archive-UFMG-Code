#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils {
    /**
     * @brief Converte os caracteres de um string para lower case
     * 
     * @param referencia É a string que terá os caracters colocados como lower case
     * @return std::string É a string formatada com caracteres lower case
     */
    std::string toLower(const std::string& referencia);

    /**
     * @brief Remove colchetes nos extremos de uma string
     * 
     * @details Transforma uma string: [string] -> string
     * 
     * @param referencia É a referencia que terá os extremos removidos
     * @return std::string É a string formatada com os extremoso removidos
     */
    std::string extrairColchetes(const std::string& referencia);

    /**
     * @brief Ajusta uma palavra de entrada tornar caracteres lower case e remover os colchetes nos extremos
     * 
     * @param referencia É a referencia que terá os extremos removidos e caracteres colocados lower case
     * @return std::string É a string formatada com os extremos removidos e caracteres lower case
     */
    std::string formatarPalavra(const std::string& referencia);

    /**
     * @brief Remove todos os espaços no final da string
     * 
     * @param referencia É a string que terá todos espaços no final removidos
     */
    void trimEnd(std::string& referencia);
}

#endif

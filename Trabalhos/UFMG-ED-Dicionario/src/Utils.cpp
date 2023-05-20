#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>

#include "Utils.h"

std::string Utils::toLower(const std::string& referencia) {
    std::string referenciaLowerCase = referencia;

    for(unsigned int i = 0; i < referenciaLowerCase.size(); i++) {
        referenciaLowerCase[i] = tolower(referenciaLowerCase[i]);
    }

    return referenciaLowerCase;
}

std::string Utils::extrairColchetes(const std::string& referencia) {
    std::string resultado = "";

    for(unsigned int i = 1; i < referencia.size() - 1; i++) {
        resultado.push_back(referencia[i]);
    }

    return resultado;
}

std::string Utils::formatarPalavra(const std::string& referencia) {
    std::string referenciaLowerCaseSemColchetes = "";

    for(unsigned int i = 1; i < referencia.size() - 1; i++) {
        referenciaLowerCaseSemColchetes.push_back(tolower(referencia[i]));
    }

    return referenciaLowerCaseSemColchetes;
}

void Utils::trimEnd(std::string& referencia) {
    referencia.erase(std::find_if(referencia.rbegin(), referencia.rend(), [](unsigned char caracter) {
        return !std::isspace(caracter);
    }).base(), referencia.end());

    return;
}

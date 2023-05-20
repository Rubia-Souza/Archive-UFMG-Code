#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>

#include "Utils.h"

std::string Utils::replace(const std::string& referencia, const std::string& alvo, const std::string& conteudo) {
    size_t posicaoAlvo = referencia.find(alvo);

    if(referencia.empty() || posicaoAlvo == std::string::npos) {
        return "";
    }

    std::string referenciaAjustada = referencia;
    referenciaAjustada.replace(posicaoAlvo, alvo.size(), conteudo);

    return referenciaAjustada;
}

std::string Utils::toUpper(const std::string& referencia) {
    std::string stringUpperCase = "";

    for(unsigned int i = 0; i < referencia.size(); i++) {
        stringUpperCase.push_back(toupper(referencia[i]));
    }

    return stringUpperCase;
}

void Utils::trimEnd(std::string& referencia) {
    referencia.erase(std::find_if(referencia.rbegin(), referencia.rend(), [](unsigned char caracter) {
        return !std::isspace(caracter);
    }).base(), referencia.end());

    return;
}

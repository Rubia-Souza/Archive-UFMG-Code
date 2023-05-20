#include <iostream>
#include <string.h>

#include "Registro.h"
#include "Constantes.h"

Registro::Registro() {}
 
/*Registro::Registro(const Registro& registro) {
    this->chave = registro.chave;

    for(unsigned int i = 0; i < QUANTIDADE_NUMEROS_REGISTRO; i++) {
        this->numeros[i] = registro.numeros[i];
    }

    for(unsigned int i = 0; i < QUANTIDADE_STRINGS_REGISTRO; i++) {
        *this->textos[i] = *registro.textos[i];
    }

    return;
}*/

Registro::~Registro() {}

/*Registro& Registro::operator=(const Registro& outroRegistro) {
    this->chave = outroRegistro.chave;

    for(unsigned int i = 0; i < QUANTIDADE_NUMEROS_REGISTRO; i++) {
        this->numeros[i] = outroRegistro.numeros[i];
    }

    for(unsigned int i = 0; i < QUANTIDADE_STRINGS_REGISTRO; i++) {
        *this->textos[i] = *outroRegistro.textos[i];
    }

    return *this;
}*/

bool Registro::operator<=(const Registro& outroRegistro) {
    return (this->chave <= outroRegistro.chave);
}

bool Registro::operator<(const Registro& outroRegistro) {
    return (this->chave < outroRegistro.chave);
}

bool Registro::operator>=(const Registro& outroRegistro) {
    return (this->chave >= outroRegistro.chave);
}

bool Registro::operator>(const Registro& outroRegistro) {
    return (this->chave > outroRegistro.chave);
}

void Registro::print() {
    std::cout << "Chave: " << this->chave << "\n";

    for(unsigned int i = 0; i < QUANTIDADE_NUMEROS_REGISTRO; i++) {
        std::cout << "Numero [" << i << "] " << this->numeros[i] << "\n";
    }

    for(unsigned int i = 0; i < QUANTIDADE_STRINGS_REGISTRO; i++) {
        std::cout << "String [" << i << "] " << this->textos[i] << "\n";
    }

    return;
}

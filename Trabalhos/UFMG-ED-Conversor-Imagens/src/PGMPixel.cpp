#include "PGMPixel.h"

PGMPixel::PGMPixel() {}

PGMPixel::PGMPixel(const short valor, const short tomMaximo) {
    setTomMaximo(tomMaximo);
    setValor(valor);
}

PGMPixel::~PGMPixel() {}

void PGMPixel::setValor(const short valor) {
    if(valor > getTomMaximo()) {
        return;
    }

    this->valor = valor;
    return;
}

short PGMPixel::getValor() const {
    return valor;
}

short* PGMPixel::getEnderecoValor() {
    return &valor;
}

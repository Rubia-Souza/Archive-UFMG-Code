#include "PPMPixel.h"

PPMPixel::PPMPixel() {}

PPMPixel::PPMPixel(const short vermelho, const short verde, const short azul, const short tomMaximo) {
    setTomMaximo(tomMaximo);
    setVermelho(vermelho);
    setVerde(verde);
    setAzul(azul);
}

PPMPixel::~PPMPixel() {}

void PPMPixel::setVermelho(const short vermelho) {
    if(vermelho > getTomMaximo()) {
        return;
    }

    this->vermelho = vermelho;
}

short PPMPixel::getVermelho() const {
    return vermelho;
}

short* PPMPixel::getEnderecoVermelho() {
    return &vermelho;
}

void PPMPixel::setVerde(const short verde) {
    if(verde > getTomMaximo()) {
        return;
    }

    this->verde = verde;
    return;
}

short PPMPixel::getVerde() const {
    return verde;
}

short* PPMPixel::getEnderecoVerde() {
    return &verde;
}

void PPMPixel::setAzul(const short azul) {
    if(azul > getTomMaximo()) {
        return;
    }

    this->azul = azul;
    return;
}

short PPMPixel::getAzul() const {
    return azul;
}

short* PPMPixel::getEnderecoAzul() {
    return &azul;
}

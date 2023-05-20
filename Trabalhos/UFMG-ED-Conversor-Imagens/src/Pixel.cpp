#include "Pixel.h"

Pixel::Pixel() {}

Pixel::Pixel(const short tomMaximo) {
    setTomMaximo(tomMaximo);
}

Pixel::~Pixel() {}

void Pixel::setTomMaximo(const short tomMaximo) {
    this->tomMaximo = tomMaximo;
    return;
}

short Pixel::getTomMaximo() const {
    return tomMaximo;
}

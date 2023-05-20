#include <string>

#include "Imagem.h"

#include "Lista.h"
#include "Pixel.h"

Imagem::Imagem() {
    pixels = new Lista<Pixel*>();
}

Imagem::Imagem(const std::string tipo, const unsigned int altura, const unsigned int largura, const short quatidadeTons) {
    pixels = new Lista<Pixel*>();
}

Imagem::~Imagem() {
    pixels->limpar();
    delete pixels;
}

void Imagem::setTipo(const std::string tipo) {
    this->tipo = tipo;
    return;
}

std::string Imagem::getTipo() const {
    return tipo;
}

void Imagem::setAltura(const unsigned int altura) {
    this->altura = altura;
    return;
}

unsigned int Imagem::getAltura() const {
    return altura;
}

void Imagem::setLargura(const unsigned int largura) {
    this->largura = largura;
    return;
}

unsigned int Imagem::getLargura() const {
    return largura;
}

void Imagem::setQuantidadeTons(const short quatidadeTons) {
    this->quatidadeTons = quatidadeTons;
    return;
}

short Imagem::getQuantidadeTons() const {
    return quatidadeTons;
}

Lista<Pixel*>* Imagem::getPixels() const {
    return pixels;
}

unsigned int Imagem::getTotalPixels() const {
    return getLargura() * getAltura();
}

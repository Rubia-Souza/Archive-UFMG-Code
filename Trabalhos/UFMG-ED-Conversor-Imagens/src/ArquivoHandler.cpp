#include <string>

#include "ArquivoHandler.h"

ArquivoHandler::ArquivoHandler(const std::string caminho) {
    setCaminho(caminho);
}

ArquivoHandler::~ArquivoHandler() {}

void ArquivoHandler::setCaminho(const std::string caminho) {
    this->caminho = caminho;
    return;
}

std::string ArquivoHandler::getCaminho() const {
    return caminho;
}

#include <string>
#include <stdexcept>

#include "Excecao.h"

Excecao::Excecao(const std::string mensagem) : std::runtime_error(mensagem) {}
Excecao::~Excecao() {}

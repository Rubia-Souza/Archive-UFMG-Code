#include <string>
#include <stdexcept>

#include "ExcecoesLista.h"

#include "Excecao.h"

ExcecoesLista::IndexInvalidoException::IndexInvalidoException(const std::string mensagem) : Excecao(mensagem) {}

ExcecoesLista::IndexInvalidoException::~IndexInvalidoException() {}

#include <string>
#include <stdexcept>

#include "Excecao.h"
#include "ExcecoesLista.h"

ExcecoesLista::IndexInvalidoException::IndexInvalidoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesLista::IndexInvalidoException::~IndexInvalidoException() {}

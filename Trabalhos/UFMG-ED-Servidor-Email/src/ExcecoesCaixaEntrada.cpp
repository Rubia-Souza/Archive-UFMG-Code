#include <string>
#include <stdexcept>

#include "Excecao.h"
#include "ExcecoesCaixaEntrada.h"

ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException::AcessoCaixaEntradaVaziaException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException::~AcessoCaixaEntradaVaziaException() {}

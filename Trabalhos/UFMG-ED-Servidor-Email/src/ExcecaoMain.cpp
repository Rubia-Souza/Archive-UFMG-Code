#include <string>
#include <stdexcept>

#include "ExcecoesMain.h"

ExcecoesMain::AquivoEntradaNaoInformadoException::AquivoEntradaNaoInformadoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::AquivoEntradaNaoInformadoException::~AquivoEntradaNaoInformadoException() {}

ExcecoesMain::ErroAoAbrirAquivoEntradaException::ErroAoAbrirAquivoEntradaException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ErroAoAbrirAquivoEntradaException::~ErroAoAbrirAquivoEntradaException() {}

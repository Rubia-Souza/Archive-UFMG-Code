#include <string>
#include <stdexcept>

#include "ExcecoesMain.h"

#include "Excecao.h"

ExcecoesMain::ArquivoEntradaNaoFornecidoException::ArquivoEntradaNaoFornecidoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoEntradaNaoFornecidoException::~ArquivoEntradaNaoFornecidoException() {}

ExcecoesMain::ArquivoSaidaNaoFornecidoException::ArquivoSaidaNaoFornecidoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoSaidaNaoFornecidoException::~ArquivoSaidaNaoFornecidoException() {}

ExcecoesMain::ErroAoEncerrarMemLogException::ErroAoEncerrarMemLogException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ErroAoEncerrarMemLogException::~ErroAoEncerrarMemLogException() {}

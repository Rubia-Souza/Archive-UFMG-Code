#include <string>
#include <stdexcept>

#include "ExcecoesMain.h"

#include "Excecao.h"

ExcecoesMain::ArquivoEntradaNaoFornecidoException::ArquivoEntradaNaoFornecidoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoEntradaNaoFornecidoException::~ArquivoEntradaNaoFornecidoException() {}

ExcecoesMain::ArquivoSaidaNaoFornecidoException::ArquivoSaidaNaoFornecidoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoSaidaNaoFornecidoException::~ArquivoSaidaNaoFornecidoException() {}

ExcecoesMain::ArgumentoInvalidoExcecao::ArgumentoInvalidoExcecao(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArgumentoInvalidoExcecao::~ArgumentoInvalidoExcecao() {}

ExcecoesMain::ArquivoEntradaNaoAbertoException::ArquivoEntradaNaoAbertoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoEntradaNaoAbertoException::~ArquivoEntradaNaoAbertoException() {}

ExcecoesMain::ArquivoSaidaNaoAbertoException::ArquivoSaidaNaoAbertoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ArquivoSaidaNaoAbertoException::~ArquivoSaidaNaoAbertoException() {}

ExcecoesMain::ErroAoEncerrarMemLogException::ErroAoEncerrarMemLogException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesMain::ErroAoEncerrarMemLogException::~ErroAoEncerrarMemLogException() {}

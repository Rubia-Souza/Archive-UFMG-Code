#include <string>
#include <stdexcept>

#include "Excecao.h"
#include "ExcecoesServidor.h"

ExcecoesServidor::UsuarioJaCadastradoException::UsuarioJaCadastradoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesServidor::UsuarioJaCadastradoException::~UsuarioJaCadastradoException() {}

ExcecoesServidor::UsuarioNaoEncontradoException::UsuarioNaoEncontradoException(const std::string mensagem) : Excecao(mensagem) {}
ExcecoesServidor::UsuarioNaoEncontradoException::~UsuarioNaoEncontradoException() {}

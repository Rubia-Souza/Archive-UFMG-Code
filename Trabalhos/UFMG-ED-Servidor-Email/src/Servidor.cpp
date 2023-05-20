#include <string>
#include <stdexcept>

#include "Servidor.h"

#include "ListaEncadeada.h"
#include "Mensagem.h"
#include "Usuario.h"
#include "Utils.h"

#include "ExcecoesServidor.h"

const std::string Servidor::MENSAGEM_ERRO_CADASTRO_USUARIO = "ERRO: CONTA {ID} JA EXISTENTE\n";
const std::string Servidor::MENSAGEM_ERRO_REMOVER_USUARIO = "ERRO: CONTA {ID} NAO EXISTE\n";
const std::string Servidor::MENSAGEM_ERRO_ENTREGAR_MENSAGEM = "ERRO: CONTA {ID} NAO EXISTE\n";
const std::string Servidor::MENSAGEM_ERRO_CONSULTAR_MENSAGEM_USUARIO_NAO_ENCONTRADO = "ERRO: CONTA {ID} NAO EXISTE\n";

Servidor::Servidor() {
    usuarios = new ListaEncadeada<Usuario>();
    return;
}

Servidor::~Servidor() {
    delete usuarios;
    return;
}

void Servidor::cadastrarNovoUsuario(const unsigned int id) {
    for(Celula<Usuario>* iterador = usuarios->getInicio()->getProximaCelula(); iterador != usuarios->getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getId() == id) {
            throw new ExcecoesServidor::UsuarioJaCadastradoException(Utils::replace(MENSAGEM_ERRO_CADASTRO_USUARIO, "{ID}", std::to_string(id)));
        }
    }

    Usuario* novoUsuario = new Usuario(id);
    usuarios->adicionarFim(novoUsuario);

    return;
}

void Servidor::removerUsuario(const unsigned int id) {
    Usuario* usuarioRemovido = new Usuario(id);
    unsigned int quantidadeUsuariosAnterior = usuarios->getTamanho();

    usuarios->removerItem(*usuarioRemovido);

    if(quantidadeUsuariosAnterior == usuarios->getTamanho()) {
        throw new ExcecoesServidor::UsuarioNaoEncontradoException(Utils::replace(MENSAGEM_ERRO_REMOVER_USUARIO, "{ID}", std::to_string(id)));
    }

    return;
}

void Servidor::entregarMensagem(const unsigned int id, const Mensagem mensagem) {
    for(Celula<Usuario>* iterador = usuarios->getInicio()->getProximaCelula(); iterador != usuarios->getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getId() == id) {
            iterador->getValor()->receberMensagem(mensagem);
            return;
        }
    }

    throw new ExcecoesServidor::UsuarioNaoEncontradoException(Utils::replace(MENSAGEM_ERRO_ENTREGAR_MENSAGEM, "{ID}", std::to_string(id)));
}

Mensagem Servidor::consultarEmail(const unsigned int id) {
    for(Celula<Usuario>* iterador = usuarios->getInicio()->getProximaCelula(); iterador != usuarios->getFim(); iterador = iterador->getProximaCelula()) {
        if(iterador->getValor()->getId() == id) {
            return iterador->getValor()->consultarMensagem();
        }
    }

    throw new ExcecoesServidor::UsuarioNaoEncontradoException(Utils::replace(MENSAGEM_ERRO_CONSULTAR_MENSAGEM_USUARIO_NAO_ENCONTRADO, "{ID}", std::to_string(id)));
}

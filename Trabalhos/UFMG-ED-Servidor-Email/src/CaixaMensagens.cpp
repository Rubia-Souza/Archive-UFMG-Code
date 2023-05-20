#include <stdexcept>

#include "CaixaMensagens.h"

#include "Mensagem.h"
#include "FilaPrioridade.h"
#include "ExcecoesCaixaEntrada.h"
#include "Utils.h"

const std::string CaixaMensagens::MENSAGEM_ERRO_CONSULTAR_MENSAGEM_CAIXA_ENTRADA_VAZIA = "CONSULTA {ID}: CAIXA DE ENTRADA VAZIA\n";

CaixaMensagens::CaixaMensagens() {
    mensagens = new FilaPrioridade<Mensagem>();
    return;
}

CaixaMensagens::~CaixaMensagens() {
    delete mensagens;
    return;
}

void CaixaMensagens::guardarMensagem(const Mensagem mensagem) {
    Mensagem* novaMensagem = new Mensagem(mensagem);
    mensagens->adicionar(novaMensagem, novaMensagem->getPrioridade());

    return;
}

Mensagem CaixaMensagens::consultarMensagem() {
    if(mensagens->estaVazia()) {
        throw new ExcecoesCaixaEntrada::AcessoCaixaEntradaVaziaException(MENSAGEM_ERRO_CONSULTAR_MENSAGEM_CAIXA_ENTRADA_VAZIA);
    }

    Mensagem alvo = mensagens->pop();

    return alvo;
}

FilaPrioridade<Mensagem>* CaixaMensagens::getMensagens() const {
    return mensagens;
}

unsigned int CaixaMensagens::getQuantidadeMensagens() const {
    return mensagens->getTamanho();
}

#ifndef ESCRITOR_ARQUIVO_SAIDA_H
#define ESCRITOR_ARQUIVO_SAIDA_H

#include "Cavalo.h"
#include "Tabuleiro.h"

static const char CAMINHO_NOME_ARQUIVO_SAIDA[] = "./saida.txt";

void criarArquivoSaida(const Tabuleiro* tabuleiro, const Cavalo* cavalo);

#endif

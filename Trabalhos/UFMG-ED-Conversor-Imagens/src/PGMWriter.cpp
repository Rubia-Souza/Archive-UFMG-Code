#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "PGMWriter.h"
#include "ArquivoHandler.h"
#include "Imagem.h"
#include "Constantes.h"
#include "Celula.h"
#include "Pixel.h"
#include "PGMPixel.h"
#include "ExcecoesPGMWriter.h"

#include "msgassert.h"
#include "memlog.h"

const std::string PGMWriter::MENSAGEM_ERRO_CRIAR_ARQUIVO = "[ERRO] Nao foi possivel criar o arquivo de saida.";

PGMWriter::PGMWriter(const std::string caminho) : ArquivoHandler(caminho) {}
PGMWriter::~PGMWriter() {}

void PGMWriter::criarImagem(const Imagem& imagem) const {
    std::ofstream arquivoSaida(getCaminho() + PGM_EXTENSION);

    if(arquivoSaida.fail()) {
        erroAssert(arquivoSaida.fail(), MENSAGEM_ERRO_CRIAR_ARQUIVO.c_str());
        throw ExcecoesPGMWriter::CriacaoArquivoSaidaException(MENSAGEM_ERRO_CRIAR_ARQUIVO);
    }

    escreverTipoImagem(&arquivoSaida, imagem);
    escreverDimensoes(&arquivoSaida, imagem);
    escreverQuantidadeTons(&arquivoSaida, imagem);
    escreverPixels(&arquivoSaida, imagem);

    arquivoSaida.close();
    return;   
}

void PGMWriter::escreverTipoImagem(std::ofstream* arquivo, const Imagem& imagem) const {
    *arquivo << imagem.getTipo() << "\n";
    return;
}

void PGMWriter::escreverDimensoes(std::ofstream* arquivo, const Imagem& imagem) const {
    *arquivo << imagem.getAltura() << " " << imagem.getLargura() << "\n";
    return;
}

void PGMWriter::escreverQuantidadeTons(std::ofstream* arquivo, const Imagem& imagem) const {
    *arquivo << imagem.getQuantidadeTons() << "\n";
    return;
}

void PGMWriter::escreverPixels(std::ofstream* arquivo, const Imagem& imagem) const {
    unsigned int caracterPorLinha = 0;

    for(Celula<Pixel*>* iterador = imagem.getPixels()->getInicio()->getProximaCelula(); iterador != imagem.getPixels()->getFim(); iterador = iterador->getProximaCelula()) {
        PGMPixel* pixel = dynamic_cast<PGMPixel*>(iterador->getValor());

        *arquivo << pixel->getValor() << " ";
        LEMEMLOG((long int) *pixel->getEnderecoValor(), sizeof(short), ID_IMAGEM_PGM);

        caracterPorLinha += QUANTIDADE_CARACTER_POR_PIXEL_PGM;
        if(caracterPorLinha >= QUANTIDADE_MAXIMA_CARACTER_POR_LINHA) {
            caracterPorLinha = 0;
            *arquivo << "\n";
        }
    }

    return;
}

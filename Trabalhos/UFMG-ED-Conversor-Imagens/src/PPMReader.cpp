#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "PPMReader.h"
#include "ArquivoHandler.h"
#include "Imagem.h"
#include "Constantes.h"
#include "ExcecoesPPMReader.h"

#include "msgassert.h"
#include "memlog.h"

const std::string PPMReader::MENSAGEM_ERRO_AO_ABRIR_ARQUIVO = "[ERRO] Nao foi possivel abrir o arquivo.";
const std::string PPMReader::MENSAGEM_ERRO_FORMATO_INVALIDO = "[ERRO] Formato ASCII de imagem invalido.";
const std::string PPMReader::MENSAGEM_ERRO_LEITURA_FALHOU = "[ERRO] Leitura da imagem foi corrompida.";

PPMReader::PPMReader(const std::string caminho) : ArquivoHandler(caminho) {}
PPMReader::~PPMReader() {}

Imagem* PPMReader::lerImagem() const {
    std::fstream arquivo;
    arquivo.open(getCaminho(), std::ios::in);

    if(!arquivo.is_open()) {
        erroAssert(!arquivo.is_open(), MENSAGEM_ERRO_AO_ABRIR_ARQUIVO.c_str());
        throw ExcecoesPPMReader::FalhaAbrirArquivoException(MENSAGEM_ERRO_AO_ABRIR_ARQUIVO);
    }

    Imagem* imagem = new Imagem();

    imagem->setTipo(getTipoImagem(arquivo));
    
    std::pair<unsigned int, unsigned int> dimenoes = getDimensoes(arquivo);
    imagem->setAltura(dimenoes.first);
    imagem->setLargura(dimenoes.second);

    imagem->setQuantidadeTons(getQuantidadeTons(arquivo));

    for(unsigned int i = 0; i < imagem->getTotalPixels(); i++) {
        PPMPixel* pixel = getPixels(arquivo, imagem->getQuantidadeTons());
        imagem->getPixels()->adicionarFim(pixel);

        ESCREVEMEMLOG((long int) *pixel->getEnderecoVermelho(), sizeof(short), ID_IMAGEM_PPM);
        ESCREVEMEMLOG((long int) *pixel->getEnderecoVerde(), sizeof(short), ID_IMAGEM_PPM);
        ESCREVEMEMLOG((long int) *pixel->getEnderecoAzul(), sizeof(short), ID_IMAGEM_PPM);
    }

    if(imagem->getPixels()->getTamanho() != imagem->getTotalPixels()) {
        erroAssert(imagem->getPixels()->getTamanho() != imagem->getTotalPixels(), MENSAGEM_ERRO_LEITURA_FALHOU.c_str());
        throw ExcecoesPPMReader::LeituraException(MENSAGEM_ERRO_LEITURA_FALHOU);
    }

    arquivo.close();
    return imagem;
}

std::string PPMReader::getTipoImagem(std::fstream& arquivo) const {
    std::string tipo = "";
    std::getline(arquivo, tipo);

    if(tipo != TIPO_ASCII_PPM) {
        erroAssert(tipo != TIPO_ASCII_PPM, MENSAGEM_ERRO_FORMATO_INVALIDO.c_str());
        throw ExcecoesPPMReader::FormatoInvalidoException(MENSAGEM_ERRO_FORMATO_INVALIDO);
    }

    return tipo;
}

std::pair<unsigned int, unsigned int> PPMReader::getDimensoes(std::fstream& arquivo) const {
    unsigned int colunas = 0;
    unsigned int linhas = 0;

    arquivo >> colunas >> linhas;

    return std::pair<unsigned int, unsigned int>(colunas, linhas);
}

unsigned int PPMReader::getQuantidadeTons(std::fstream& arquivo) const {
    unsigned int quatidadeTons = 0;

    arquivo >> quatidadeTons;

    return quatidadeTons;
}

PPMPixel* PPMReader::getPixels(std::fstream& arquivo, const short tomMaximo) const {
    short vermelho = 0;
    short verde = 0;
    short azul = 0;

    arquivo >> vermelho >> verde >> azul;

    return new PPMPixel(vermelho, verde, azul, tomMaximo);
}

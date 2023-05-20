#include <cmath>

#include "ConversorImagem.h"

#include "Imagem.h"
#include "Constantes.h"

#include "Pixel.h"
#include "PPMPixel.h"
#include "PGMPixel.h"

#include "Celula.h"

#include "memlog.h"

Imagem* ConversorImagem::converterPPMparaPGM(const Imagem& imagemPPM) {
    Imagem* imagemConvertida = new Imagem();
    imagemConvertida->setTipo(TIPO_ASCII_PGM);

    imagemConvertida->setQuantidadeTons(TOM_MAXIMO_PADRAO_CINZA);

    imagemConvertida->setAltura(imagemPPM.getAltura());
    imagemConvertida->setLargura(imagemPPM.getLargura());

    const double PROPORCAO = TOM_MAXIMO_PADRAO_CINZA / TOM_MAXIMO_PADRAO_COR;

    for(Celula<Pixel*>* iterador = imagemPPM.getPixels()->getInicio()->getProximaCelula(); iterador != imagemPPM.getPixels()->getFim(); iterador = iterador->getProximaCelula()) {
        PPMPixel* pixelColorido = dynamic_cast<PPMPixel*>(iterador->getValor());

        double tomCinzaPreciso = PROPORCAO * (FATOR_MULTIPLICACAO_VERMELHO * pixelColorido->getVermelho() + FATOR_MULTIPLICACAO_VERDE * pixelColorido->getVerde() + FATOR_MULTIPLICACAO_AZUL * pixelColorido->getAzul());
        LEMEMLOG((long int) *pixelColorido->getEnderecoVermelho(), sizeof(short), ID_IMAGEM_PPM);
        LEMEMLOG((long int) *pixelColorido->getEnderecoVerde(), sizeof(short), ID_IMAGEM_PPM);
        LEMEMLOG((long int) *pixelColorido->getEnderecoAzul(), sizeof(short), ID_IMAGEM_PPM);
        short tomCinza = floor(tomCinzaPreciso);

        PGMPixel* pixelCinza = new PGMPixel(tomCinza, TOM_MAXIMO_PADRAO_CINZA);
        imagemConvertida->getPixels()->adicionarFim(pixelCinza);

        ESCREVEMEMLOG((long int) *pixelCinza->getEnderecoValor(), sizeof(short), ID_IMAGEM_PGM);
    }

    return imagemConvertida;
}

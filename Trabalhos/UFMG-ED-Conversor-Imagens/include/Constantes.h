#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

const std::string TIPO_ASCII_PPM = "P3";
const std::string TIPO_ASCII_PGM = "P2";

const float TOM_MAXIMO_PADRAO_CINZA = 49.0;
const float TOM_MAXIMO_PADRAO_COR = 255.0;

const float FATOR_MULTIPLICACAO_VERMELHO = 0.3;
const float FATOR_MULTIPLICACAO_VERDE = 0.59;
const float FATOR_MULTIPLICACAO_AZUL = 0.11;

const unsigned int QUANTIDADE_MAXIMA_CARACTER_POR_LINHA = 60;
const unsigned int QUANTIDADE_CARACTER_POR_PIXEL_PGM = 3;

const std::string PGM_EXTENSION = ".pgm";

const unsigned int ID_IMAGEM_PGM = 0;
const unsigned int ID_IMAGEM_PPM = 1;

#endif

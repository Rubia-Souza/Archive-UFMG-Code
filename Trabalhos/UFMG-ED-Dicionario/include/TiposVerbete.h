#ifndef TIPOS_VERBETE_H
#define TIPOS_VERBETE_H

enum TiposVerbete {
    ADJETIVO = 'a',
    NOME = 'n',
    VERBO = 'v',
};

TiposVerbete converterCharParaTiposVerbete(const char tipo);

#endif

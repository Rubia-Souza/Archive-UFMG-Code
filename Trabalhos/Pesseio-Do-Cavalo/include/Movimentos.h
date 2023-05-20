#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

#define QUANTIDADE_TIPOS_MOVIMENTOS 8

typedef struct Movimentos {
    int horizontal;
    int vertical;
} Movimentos;

Movimentos TIPOS_MOVIMENTOS[QUANTIDADE_TIPOS_MOVIMENTOS];
void inicializarTiposMovimentos();

#endif

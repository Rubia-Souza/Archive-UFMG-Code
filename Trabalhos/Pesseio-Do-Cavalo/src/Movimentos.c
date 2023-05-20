#include "Movimentos.h"

void inicializarTiposMovimentos() {
    const Movimentos HORIZONTAL_DIREITO_SUPERIOR = {
        .horizontal = 2,
        .vertical = 1,
    };

    const Movimentos VERTICAL_SUPERIOR_DIREITO = {
        .horizontal = 1,
        .vertical = 2,
    };

    const Movimentos VERTICAL_SUPERIOR_ESQUERDO = {
        .horizontal = -1,
        .vertical = 2,
    };

    const Movimentos HORIZONTAL_ESQUERDO_SUPERIOR = {
        .horizontal = -2,
        .vertical = 1,
    };

    const Movimentos HORIZONTAL_ESQUERDO_INFERIOR = {
        .horizontal = -2,
        .vertical = -1,
    };

    const Movimentos VERTICAL_INFERIOR_ESQUERDO = {
        .horizontal = -1,
        .vertical = -2,
    };

    const Movimentos VERTICAL_INFERIOR_DIREITO = {
        .horizontal = 1,
        .vertical = -2,
    };

    const Movimentos HORIZONTAL_DIREITO_INFERIOR = {
        .horizontal = 2,
        .vertical = -1,
    };

    TIPOS_MOVIMENTOS[0] = HORIZONTAL_DIREITO_SUPERIOR;
    TIPOS_MOVIMENTOS[1] = VERTICAL_SUPERIOR_DIREITO;
    TIPOS_MOVIMENTOS[2] = VERTICAL_SUPERIOR_ESQUERDO;
    TIPOS_MOVIMENTOS[3] = HORIZONTAL_ESQUERDO_SUPERIOR;
    TIPOS_MOVIMENTOS[4] = HORIZONTAL_ESQUERDO_INFERIOR;
    TIPOS_MOVIMENTOS[5] = VERTICAL_INFERIOR_ESQUERDO;
    TIPOS_MOVIMENTOS[6] = VERTICAL_INFERIOR_DIREITO;
    TIPOS_MOVIMENTOS[7] = HORIZONTAL_DIREITO_INFERIOR;
    return;
}

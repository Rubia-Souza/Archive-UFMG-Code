#include <stdlib.h>
#include <time.h>

#include "passeio.h"
#include "Tabuleiro.h"

void setup();
unsigned int gerarPosicaoAleatoria();

int main() {
    setup();

    for(unsigned int x = 1; x <= TAMANHO_PADRAO_TABULEIRO; x++) {
        for(unsigned int y = 1; y <= TAMANHO_PADRAO_TABULEIRO; y++) {
            passeio(y, x);
        }
    }
    
    return 0;
}

void setup() {
    time_t tempo;
    srand((unsigned) time(&tempo));

    return;
}

unsigned int gerarPosicaoAleatoria() {
    return rand() % TAMANHO_PADRAO_TABULEIRO + 1;
}

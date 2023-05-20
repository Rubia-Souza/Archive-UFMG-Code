#include <stdio.h>

#include "EscritorArquivoSaida.h"

#include "Tabuleiro.h"

void criarArquivoSaida(const Tabuleiro* tabuleiro, const Cavalo* cavalo) {
    FILE* arquivoSaida = fopen(CAMINHO_NOME_ARQUIVO_SAIDA, "a");

    for(unsigned int y = 0; y < tabuleiro->altura; y++) {
        for(unsigned int x = 0; x < tabuleiro->largura; x++) {
            fprintf(arquivoSaida, "%d", tabuleiro->posicoes[y][x].numero);

            if(x != (tabuleiro->largura - 1)) {
                fprintf(arquivoSaida, " ");
            }
        }

        fprintf(arquivoSaida, "\n");
    }

    fprintf(arquivoSaida, "%d %d\n", cavalo->totalCasasVisitadas, cavalo->totalCasasRetrocedidas);
    fclose(arquivoSaida);
    return;
}

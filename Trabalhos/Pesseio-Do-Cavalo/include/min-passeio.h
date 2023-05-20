#ifndef MIN_PASSEIO_H
#define MIN_PASSEIO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma region .: Declaracoes :.

#pragma region .: Posicao :.

typedef struct Posicao {
    unsigned int x;
    unsigned int y;
    unsigned int numero;
} Posicao;

Posicao* newPosicao();
void destruirPosicao(Posicao* posicao);

bool foiVisitada(const Posicao* posicao);

#pragma endregion

#pragma region .: Tabuleiro :.

#define TAMANHO_PADRAO_TABULEIRO 8

typedef struct Tabuleiro {
    unsigned int altura;
    unsigned int largura;
    unsigned int quantidadePosicoes;
    Posicao** posicoes;
} Tabuleiro;

Tabuleiro* newTabuleiro(const unsigned int largura, const unsigned int altura);
void destruirTabuleiro(Tabuleiro* tabuleiro);

bool posicaoXYEhValida(const Tabuleiro* tabuleiro, const unsigned int x, const unsigned int y);

void printTabuleiro(const Tabuleiro* tabuleiro);

#pragma endregion

#pragma region .: Cavalo :.

typedef struct Cavalo {
    Posicao* posicaoAtual;
    unsigned int casasDiferentesVisitadas;
    unsigned int totalCasasVisitadas;
    unsigned int totalCasasRetrocedidas;
} Cavalo;

Cavalo* newCavalo();
void destruirCavalo(Cavalo* cavalo);

void mover(Cavalo* cavalo, Posicao* novaPosicao);
void retroceder(Cavalo* cavalo, Posicao* novaPosicao);

void printDadosCavalo(const Cavalo* cavalo);

#pragma endregion

#pragma region .: Movimentos :.

#define QUANTIDADE_TIPOS_MOVIMENTOS 8

typedef struct Movimentos {
    int horizontal;
    int vertical;
} Movimentos;

Movimentos TIPOS_MOVIMENTOS[QUANTIDADE_TIPOS_MOVIMENTOS];
void inicializarTiposMovimentos();

#pragma endregion

#pragma region .: CelulaPossibilidadePosicao :.

typedef struct CelulaPossibilidadePosicao {
    struct CelulaPossibilidadePosicao* proxima;
    Posicao* valor;
    unsigned int quantidadePossibilidades;
} CelulaPossibilidadePosicao;

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicao();
CelulaPossibilidadePosicao* newCelulaPossibilidadePosicaoComValor(Posicao* valor, const unsigned int quantidadePossibilidades);

void destruirCelulaPossibilidadePosicao(CelulaPossibilidadePosicao* celula);

#pragma endregion

#pragma region .: FilaPossibilidadePosicoes :.

typedef struct FilaPossibilidadePosicoes {
    CelulaPossibilidadePosicao* inicio;
    unsigned int tamanho;
} FilaPossibilidadePosicoes;

FilaPossibilidadePosicoes* newFilaPossibilidadePosicoes();
void destruirFilaPossibilidadePosicoes(FilaPossibilidadePosicoes* fila);

void adicionar(FilaPossibilidadePosicoes* fila, Posicao* posicao, const unsigned int quantidadePossibilidades);
Posicao* remover(FilaPossibilidadePosicoes* fila);

void limpar(FilaPossibilidadePosicoes* fila);
bool estaVazia(const FilaPossibilidadePosicoes* fila);

#pragma endregion

#pragma region .: EscritorArquivoSaida :.

static const char CAMINHO_NOME_ARQUIVO_SAIDA[] = "./saida.txt";

void criarArquivoSaida(const Tabuleiro* tabuleiro, const Cavalo* cavalo);

#pragma endregion

bool andar(Cavalo* cavalo, Tabuleiro* tabuleiro);

#pragma endregion

void passeio(const unsigned int x, const unsigned int y) {
    if(x > TAMANHO_PADRAO_TABULEIRO || y > TAMANHO_PADRAO_TABULEIRO) {
        return;
    }

    inicializarTiposMovimentos();

    Tabuleiro* tabuleiro = newTabuleiro(TAMANHO_PADRAO_TABULEIRO, TAMANHO_PADRAO_TABULEIRO);
    Cavalo* epona = newCavalo();
    
    unsigned int xPosicaoInicial = (x == 0) ? 0 : x - 1;
    unsigned int yPosicaoInicial = (y == 0) ? 0 : y - 1;

    epona->posicaoAtual = &tabuleiro->posicoes[xPosicaoInicial][yPosicaoInicial];
    epona->casasDiferentesVisitadas++;
    epona->totalCasasVisitadas++;

    tabuleiro->posicoes[xPosicaoInicial][yPosicaoInicial].numero = 1;

    andar(epona, tabuleiro);
    criarArquivoSaida(tabuleiro, epona);

    printTabuleiro(tabuleiro);
    printDadosCavalo(epona);

    destruirCavalo(epona);
    destruirTabuleiro(tabuleiro);
    return;
}

bool andar(Cavalo* cavalo, Tabuleiro* tabuleiro) {
    if(cavalo->casasDiferentesVisitadas >= tabuleiro->quantidadePosicoes) {
        return true;
    }

    FilaPossibilidadePosicoes* filaPosicoes = newFilaPossibilidadePosicoes();

    for(unsigned int i = 0; i < QUANTIDADE_TIPOS_MOVIMENTOS; i++) {
        int proximaPosicaoEixoX = cavalo->posicaoAtual->x + TIPOS_MOVIMENTOS[i].horizontal;
        int proximaPosicaoEixoY = cavalo->posicaoAtual->y + TIPOS_MOVIMENTOS[i].vertical;

        if(!posicaoXYEhValida(tabuleiro, proximaPosicaoEixoX, proximaPosicaoEixoY)) {
            continue;
        }

        Posicao* proximaPosicao = &tabuleiro->posicoes[proximaPosicaoEixoY][proximaPosicaoEixoX];
        if(!foiVisitada(proximaPosicao)) {
            unsigned int quantidadePossibilidades = 0;

            for(unsigned int j = 0; j < QUANTIDADE_TIPOS_MOVIMENTOS; j++) {
                int posicaoDerivadaProximaEixoX = proximaPosicao->x + TIPOS_MOVIMENTOS[j].horizontal;
                int posicaoDerivadaProximaEixoY = proximaPosicao->y + TIPOS_MOVIMENTOS[j].vertical;

                if(!posicaoXYEhValida(tabuleiro, posicaoDerivadaProximaEixoX, posicaoDerivadaProximaEixoY)) {
                    continue;
                }
                else if(!foiVisitada(&tabuleiro->posicoes[posicaoDerivadaProximaEixoY][posicaoDerivadaProximaEixoX])) {
                    quantidadePossibilidades++;
                }
            }

            adicionar(filaPosicoes, proximaPosicao, quantidadePossibilidades);
        }
    }

    for(unsigned int i = 0; i < filaPosicoes->tamanho; i++) {
        Posicao* posicaoAnterior = cavalo->posicaoAtual;
        Posicao* proximaPosicao = remover(filaPosicoes);
        
        mover(cavalo, proximaPosicao);

        if(andar(cavalo, tabuleiro)) {
            destruirFilaPossibilidadePosicoes(filaPosicoes);
            return true;
        }

        retroceder(cavalo, posicaoAnterior);
    }

    destruirFilaPossibilidadePosicoes(filaPosicoes);
    return false;
}

#endif

#pragma region .: Implementacoes :.

#pragma region .: ImplementacaoPosicao :.

Posicao* newPosicao() {
    Posicao* novaPosicao = (Posicao*) malloc(sizeof(Posicao));

    novaPosicao->x = 0;
    novaPosicao->y = 0;
    novaPosicao->numero = 0;

    return novaPosicao;
}

void destruirPosicao(Posicao* posicao) {
    posicao->x = 0;
    posicao->y = 0;
    posicao->numero = 0;

    free(posicao);
    
    return;
}

bool foiVisitada(const Posicao* posicao) {
    return (posicao->numero > 0);
}

#pragma endregion

#pragma region .: ImplementacaoTabuleiro :.

Tabuleiro* newTabuleiro(const unsigned int largura, const unsigned int altura) {
    Tabuleiro* novoTabuleiro = (Tabuleiro*) malloc(sizeof(Tabuleiro));

    novoTabuleiro->altura = altura;
    novoTabuleiro->largura = largura;

    novoTabuleiro->posicoes = (Posicao**) malloc(novoTabuleiro->altura * sizeof(Posicao*));
    for(unsigned int y = 0; y < novoTabuleiro->altura; y++) {
        novoTabuleiro->posicoes[y] = (Posicao*) malloc(novoTabuleiro->largura * sizeof(Posicao));

        for(unsigned int x = 0; x < novoTabuleiro->largura; x++) {
            novoTabuleiro->posicoes[y][x].x = x;
            novoTabuleiro->posicoes[y][x].y = y;
            novoTabuleiro->posicoes[y][x].numero = 0;
        }
    }

    novoTabuleiro->quantidadePosicoes = (novoTabuleiro->altura * novoTabuleiro->largura);
    return novoTabuleiro;
}

void destruirTabuleiro(Tabuleiro* tabuleiro) {
    tabuleiro->altura = 0;
    tabuleiro->largura = 0;
    
    for(unsigned int y = 0; y < tabuleiro->altura; y++) {
        for(unsigned int x = 0; x < tabuleiro->largura; x++) {
            tabuleiro->posicoes[y][x].x = 0;
            tabuleiro->posicoes[y][x].y = 0;
            tabuleiro->posicoes[y][x].numero = 0;
        }

        free(tabuleiro->posicoes[y]);
    }
    
    free(tabuleiro);
    return;
}

bool posicaoXYEhValida(const Tabuleiro* tabuleiro, const unsigned int x, const unsigned int y) {
    return (x >= 0 && x < tabuleiro->largura && y >= 0 && y < tabuleiro->altura);
}

void printTabuleiro(const Tabuleiro* tabuleiro) {
    printf("\t");
    for(unsigned int i = 0; i < tabuleiro->largura; i++) {
        printf("%d", i + 1);

        if(i != (tabuleiro->largura - 1)) {
            printf("\t");
        }
    }
    printf("\n");

    for(unsigned int y = 0; y < tabuleiro->altura; y++) {
        printf("%d\t", y + 1);

        for(unsigned int x = 0; x < tabuleiro->largura; x++) {
            printf("%d", tabuleiro->posicoes[y][x].numero);

            if(x != (tabuleiro->largura - 1)) {
                printf("\t");
            }
        }

        printf("\n");
    }

    return;
}

#pragma endregion

#pragma region .: ImplementacaoCavalo :.

Cavalo* newCavalo() {
    Cavalo* cavalo = (Cavalo*) malloc(sizeof(Cavalo));

    cavalo->casasDiferentesVisitadas = 0;
    cavalo->totalCasasRetrocedidas = 0;
    cavalo->totalCasasVisitadas = 0;
    cavalo->posicaoAtual = NULL;

    return cavalo;
}

void destruirCavalo(Cavalo* cavalo) {
    cavalo->casasDiferentesVisitadas = 0;
    cavalo->totalCasasRetrocedidas = 0;
    cavalo->totalCasasVisitadas = 0;
    
    cavalo->posicaoAtual = NULL;

    free(cavalo);
    return;
}

void mover(Cavalo* cavalo, Posicao* novaPosicao) {
    cavalo->casasDiferentesVisitadas = cavalo->casasDiferentesVisitadas + 1;
    cavalo->totalCasasVisitadas = cavalo->totalCasasVisitadas + 1;

    novaPosicao->numero = cavalo->casasDiferentesVisitadas;

    cavalo->posicaoAtual = novaPosicao;

    return;
}

void retroceder(Cavalo* cavalo, Posicao* posicaoAnterior) {
    cavalo->totalCasasRetrocedidas = cavalo->totalCasasRetrocedidas + 1;
    cavalo->casasDiferentesVisitadas = cavalo->casasDiferentesVisitadas - 1;

    cavalo->posicaoAtual->numero = 0;
    cavalo->posicaoAtual = posicaoAnterior;

    return;
}

void printDadosCavalo(const Cavalo* cavalo) {
    printf("\nTotal Casas Visitadas: %d", cavalo->totalCasasVisitadas);
    printf("\nTotal Casas Retrocedidas: %d", cavalo->totalCasasRetrocedidas);
    printf("\nQuantidade Casas Diferentes Visitadas: %d\n", cavalo->casasDiferentesVisitadas);

    return;
}

#pragma endregion

#pragma region .: ImplementacaoMovimentos :.

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

#pragma endregion

#pragma region .: ImplementacaoCelulaPossibilidadePosicao :.

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicao() {
    CelulaPossibilidadePosicao* novaCelula = (CelulaPossibilidadePosicao*) malloc(sizeof(CelulaPossibilidadePosicao));
    
    novaCelula->proxima = NULL;
    novaCelula->valor = NULL;
    novaCelula->quantidadePossibilidades = 0;

    return novaCelula;
}

CelulaPossibilidadePosicao* newCelulaPossibilidadePosicaoComValor(Posicao* valor, const unsigned int quantidadePossibilidades) {
    CelulaPossibilidadePosicao* novaCelula = (CelulaPossibilidadePosicao*) malloc(sizeof(CelulaPossibilidadePosicao));
    
    novaCelula->proxima = NULL;
    novaCelula->valor = valor;
    novaCelula->quantidadePossibilidades = quantidadePossibilidades;

    return novaCelula;
}

void destruirCelulaPossibilidadePosicao(CelulaPossibilidadePosicao* celula) {
    celula->proxima = NULL;
    celula->valor = NULL;
    celula->quantidadePossibilidades = 0;

    free(celula);
    return;
}

#pragma endregion

#pragma region .: ImplementacaoFilaPossibilidadePosicoes :.

FilaPossibilidadePosicoes* newFilaPossibilidadePosicoes() {
    FilaPossibilidadePosicoes* fila = (FilaPossibilidadePosicoes*) malloc(sizeof(FilaPossibilidadePosicoes));

    fila->inicio = newCelulaPossibilidadePosicao();
    fila->tamanho = 0;

    return fila;
}

void destruirFilaPossibilidadePosicoes(FilaPossibilidadePosicoes* fila) {
    limpar(fila);
    fila->inicio = NULL;

    free(fila);
    return;
}

void adicionar(FilaPossibilidadePosicoes* fila, Posicao* posicao, const unsigned int quantidadePossibilidades) {
    if(estaVazia(fila)) {
        fila->inicio->proxima = newCelulaPossibilidadePosicaoComValor(posicao, quantidadePossibilidades);
        fila->tamanho++;
        return;
    }

    CelulaPossibilidadePosicao* anterior = fila->inicio;
    while(anterior->proxima != NULL && quantidadePossibilidades > anterior->proxima->quantidadePossibilidades) {
        anterior = anterior->proxima;
    }

    CelulaPossibilidadePosicao* continuacaoFila = anterior->proxima;
    anterior->proxima = newCelulaPossibilidadePosicaoComValor(posicao, quantidadePossibilidades);
    anterior->proxima->proxima = continuacaoFila;

    fila->tamanho++;
    return;
}

Posicao* remover(FilaPossibilidadePosicoes* fila) {
    if(estaVazia(fila)) {
        return NULL;
    }

    CelulaPossibilidadePosicao* primeiraCelula = fila->inicio->proxima;

    Posicao* valor = primeiraCelula->valor;
    fila->inicio->proxima = primeiraCelula->proxima;

    destruirCelulaPossibilidadePosicao(primeiraCelula);
    return valor;
}

void limpar(FilaPossibilidadePosicoes* fila) {
    if(estaVazia(fila)) {
        return;
    }

    CelulaPossibilidadePosicao* proximaCelula = NULL;
    for(CelulaPossibilidadePosicao* iterador = fila->inicio->proxima; iterador != NULL; iterador = proximaCelula) {
        proximaCelula = iterador->proxima;
        destruirCelulaPossibilidadePosicao(iterador);
    }

    fila->tamanho = 0;
    return;
}

bool estaVazia(const FilaPossibilidadePosicoes* fila) {
    return (fila->tamanho <= 0);
}

#pragma endregion

#pragma region .: ImplementacaoEscritorArquivoSaida :.

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

#pragma endregion

#pragma endregion

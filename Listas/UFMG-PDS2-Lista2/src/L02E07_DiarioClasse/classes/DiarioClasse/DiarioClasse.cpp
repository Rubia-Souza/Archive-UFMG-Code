#include "DiarioClasse.hpp"

const double NOTA_MINIMA = 0;
const double NOTA_MAXIMA = 100;

const double NOTA_MINIMA_APROVACAO = 60;
const double NOTA_MINIMA_EXAME_ESPECIAL = 40;

const double FREQUENCIA_MINIMA = 0;
const double FREQUENCIA_MAXIMA = 1;

const double FREQUENCIA_MINIMA_APROVACAO = 0.75;

void validarNotaSemestre(const double notaSemestre);
void validarNotaEspecial(const double notaEspecial);
void validarFrequencia(const double frequencia);
void validarExameEspecialEstaDisponivel(const double notaSemestre, const double notaEspecial, const double frequencia);

bool possuiNotaParaAprovacao(const double nota);
bool possuiFrequenciaParaAprovacao(const double frequencia);

bool notaEhInferiorAoMinimo(const double nota);
bool notaEhSuperiorAoMaximo(const double nota);
bool frequenciaEhInferiorAoMinimo(const double frequencia);
bool frequenciaEhSuperiorAoMaximo(const double frequencia);

DiarioClasse::DiarioClasse() {}
DiarioClasse::~DiarioClasse() {}

bool DiarioClasse::determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia) {
    validarNotaSemestre(notaSemestre);
    validarNotaEspecial(notaEspecial);
    validarFrequencia(frequencia);
    validarExameEspecialEstaDisponivel(notaSemestre, notaEspecial, frequencia);

    if((possuiNotaParaAprovacao(notaSemestre) || possuiNotaParaAprovacao(notaEspecial)) && possuiFrequenciaParaAprovacao(frequencia)) {
        return true;
    }
    else {
        return false;
    }
}

void validarNotaSemestre(const double notaSemestre) {
    if(notaEhInferiorAoMinimo(notaSemestre) || notaEhSuperiorAoMaximo(notaSemestre)) {
        throw ExcecaoNotaSemestreInvalida();
    }
    return;
}

void validarNotaEspecial(const double notaEspecial) {
    if(notaEhInferiorAoMinimo(notaEspecial) || notaEhSuperiorAoMaximo(notaEspecial)) {
        throw ExcecaoNotaEspecialInvalida();
    }
    return;
}

void validarFrequencia(const double frequencia) {
    if(frequenciaEhInferiorAoMinimo(frequencia) || frequenciaEhSuperiorAoMaximo(frequencia)) {
        throw ExcecaoFrequenciaInvalida();
    }
    return;
}

void validarExameEspecialEstaDisponivel(const double notaSemestre, const double notaEspecial, const double frequencia) {
    if(notaEspecial == NOTA_MINIMA) {
        return;
    }

    if(!possuiFrequenciaParaAprovacao(frequencia)) {
        throw ExcecaoNotaEspecialInvalida();
    }

    bool notaNaoEhValidaParaFazerExameEspecial = notaSemestre < NOTA_MINIMA_EXAME_ESPECIAL || possuiNotaParaAprovacao(notaSemestre);
    if(notaNaoEhValidaParaFazerExameEspecial) {
        throw ExcecaoNotaEspecialInvalida();
    }

    return;
}

bool possuiNotaParaAprovacao(const double nota) {
    return (nota >= NOTA_MINIMA_APROVACAO);
}

bool possuiFrequenciaParaAprovacao(const double frequencia) {
    return (frequencia >= FREQUENCIA_MINIMA_APROVACAO);
}

bool notaEhInferiorAoMinimo(const double nota) {
    return (nota < NOTA_MINIMA);
}

bool notaEhSuperiorAoMaximo(const double nota) {
    return (nota > NOTA_MAXIMA);
}

bool frequenciaEhInferiorAoMinimo(const double frequencia) {
    return (frequencia < FREQUENCIA_MINIMA);
}

bool frequenciaEhSuperiorAoMaximo(const double frequencia) {
    return (frequencia > FREQUENCIA_MAXIMA);
}

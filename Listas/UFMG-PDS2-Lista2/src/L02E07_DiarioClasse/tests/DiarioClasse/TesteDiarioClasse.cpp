#include "../../libs/doctest.h"

#include "../../classes/DiarioClasse/DiarioClasse.hpp"

TEST_CASE("TesteDiarioClasse - Teste de reprovacao por falta") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(75, 0, 0.30);
    CHECK_FALSE(aprovado);
};

TEST_CASE("TesteDiarioClasse - Teste excecao notaSemestre inferior a 0") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(-75, 0, 1.2), ExcecaoNotaSemestreInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao frequencia inferior a 0") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(75, 0, -1), ExcecaoFrequenciaInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao exame especial nao pode ser feito por notaSemestre inferior") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(30, 70, 0.75), ExcecaoNotaEspecialInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao exame especial nao pode ser feito por notaSemestre superior") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(70, 70, 0.90), ExcecaoNotaEspecialInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao exame especial nao pode ser feito por infrequencia") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(45, 80, 0.30), ExcecaoNotaEspecialInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao exame especial com nota invalida superior a 100") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(45, 120, 0.80), ExcecaoNotaEspecialInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste excecao exame especial com nota invalida inferior a 0") {
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(45, -50, 0.80), ExcecaoNotaEspecialInvalida);
};

TEST_CASE("TesteDiarioClasse - Teste aprovacao simples") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(90, 0, 0.80);
    CHECK(aprovado);
};

TEST_CASE("TesteDiarioClasse - Reprovacao no exameEspecial") {
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(45, 50, 0.80);
    CHECK_FALSE(aprovado);
};

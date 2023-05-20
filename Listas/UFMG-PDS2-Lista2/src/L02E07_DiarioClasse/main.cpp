#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./libs/doctest.h"

#include "./classes/DiarioClasse/DiarioClasse.hpp"

TEST_CASE("Teste 01 - Reprovacao simples") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(50, 0, 1);
  CHECK_FALSE(aprovado);
};

TEST_CASE("Teste 02 - Excecao notaSemestre maior que 100") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(120, 0, 1), ExcecaoNotaSemestreInvalida);
};

TEST_CASE("Teste 03 - Excecao frequencia acima de 1") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, 1.5), ExcecaoFrequenciaInvalida);
};

TEST_CASE("Teste 04 - Aprovacao Exame Especial") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(50, 60, 0.75);
  CHECK(aprovado);
};

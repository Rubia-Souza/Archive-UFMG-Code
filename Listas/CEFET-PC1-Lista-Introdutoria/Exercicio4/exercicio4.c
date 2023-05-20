#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float parseKmToM(float distancia) {
    return distancia * 1000;
}

float calcularConsumo(float distancia) {
    return distancia / 12000;
}

float calcularDistancia(float velocidade, float tempo) {
    return velocidade * tempo;
}

float parseKmHToMS(float velocidade) {
    return velocidade / 3.6;
}

float parseMinutosToSegundos(float tempoMinutos) {
    return tempoMinutos * 60;
}

int main() {
    const int tempoMin = 35, velocidadeKmH = 80;

    const float velocidadeMS = parseKmHToMS(velocidadeKmH);
    const float tempoS = parseMinutosToSegundos(tempoMin);
    const float distancia = calcularDistancia(velocidadeMS, tempoS);
    const float consumo = calcularConsumo(distancia);

    printf("O consumo total de gasolina do percurso e: %f", ceil(consumo));
    return 0;
}

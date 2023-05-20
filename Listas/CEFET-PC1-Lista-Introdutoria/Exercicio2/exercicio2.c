#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcularValorCobranca(int salarioMinimo, int consumoAgua) {
    const int valorPor1000Litros = 00.2 * salarioMinimo;
    return valorPor1000Litros * consumoAgua / 1000;
}

int main() {
    setlocale(LC_ALL,"Portuguese");

    float consumoAgua = 0, salarioMinimo = 0;

    printf("\nInsira o valor do salário mínimo atual: ");
    scanf("%f", &salarioMinimo);

    printf("\nInsira o consumo mensal de água da residência: ");
    scanf("%f", &consumoAgua);

    int valorContaTotal = calcularValorCobranca(salarioMinimo, consumoAgua);
    int valorContaDesconto = valorContaTotal * 0.85;

    printf("Valor de cobrança integral: %d\n", valorContaTotal);
    printf("Valor de cobrança com desconto de 15%: %d", valorContaDesconto);
    return 0;
}

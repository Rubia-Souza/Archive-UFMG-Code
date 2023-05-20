#include <stdio.h>
#include <stdlib.h>

int main() {
    float inputNumber = 0, sum = 0;

    printf("Digite 4 numeros\n");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &inputNumber);
        sum += inputNumber;
        printf("%d: %f\n", i, sum);
    }

    const float media = sum / 4;
    printf("A media dos valores é: %f", media);

    return 0;
}

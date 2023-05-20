#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0, b = 0;

    printf("Insira o valor para a variavel A: ");
    scanf("%d", &a);

    printf("Insira o valor para a variavel B: ");
    scanf("%d", &b);

    printf("\nValores de A: %d e B: %d", a, b);

    int temp = a;
    a = b;
    b = temp;

    printf("\nValores de A: %d e B: %d", a, b);
    return 0;
}

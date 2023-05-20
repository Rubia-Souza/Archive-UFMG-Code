#include <stdio.h>

int main() {
    int faces = 6;
    int arestas = 12;

    int vertices = arestas + 2 - faces;

    printf("O cubo possui %d faces, %d arestas, %d vertices", faces, arestas, vertices);
    return 0;
}

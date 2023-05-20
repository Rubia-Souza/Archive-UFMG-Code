#include <iostream>

using namespace std;

#define DEFAULT_SIZE 3

void ordenarArrayBubble(int alvo[DEFAULT_SIZE]);
void renderizarConteudoArray(const int alvo[DEFAULT_SIZE]);

int main() {
    int numeros[DEFAULT_SIZE] = {};

    for (int i = 0; i < DEFAULT_SIZE; i++) {
        cin >> numeros[i];
    }

    ordenarArrayBubble(numeros);    

    return 0;
}

void ordenarArrayBubble(int alvo[DEFAULT_SIZE]) {
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            if (alvo[i] < alvo[j]) {
                int temp = alvo[i];
                alvo[i] = alvo[j];
                alvo[j] = temp;
            }
        }
    }

    cout << "Array oredenado crescente\n";
    renderizarConteudoArray(alvo);

    return;
}

void renderizarConteudoArray(const int alvo[DEFAULT_SIZE]) {
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        cout << "Posicao: " << i << " valor: " << alvo[i] << "\n";
    }

    return;
}

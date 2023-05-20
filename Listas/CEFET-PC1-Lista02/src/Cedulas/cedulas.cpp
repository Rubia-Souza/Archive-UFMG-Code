#include <iostream>
#include <string>

using namespace std;

void calcularQuantidadeDeNotas(int notas[], int valorTotal, int qtdNotas[]) {
    const int NOTAS_SIZE = 7;
    int valorRestante = 0;

    for (int i = 0; i < NOTAS_SIZE; i++) {
        bool primeiraInteracao = i == 0;
        if (primeiraInteracao) {
            valorRestante = valorTotal;
        }
        
        qtdNotas[i] = valorRestante / notas[i];
        valorRestante = valorRestante % notas[i];
    }
}

string formatarQuantidadeDeNotas(int notas[], int qtdNotas[]) {
    const int NOTAS_SIZE = 7;
    string mensagem;

    for (int i = 0; i < NOTAS_SIZE; i++) {
        string tipoNota = to_string(notas[i]);
        string quantidadeNotas = to_string(qtdNotas[i]);
        
        mensagem += quantidadeNotas + " nota(s) de R$ " + tipoNota + ",00\n";
    }

    return mensagem;
}

int main() {
    const int VALOR_MINIMO = 0, VALOR_MAXIMO = 1000000;
    const int NOTAS_ARRAY_SIZE = 7;
    
    int notas[NOTAS_ARRAY_SIZE] = {100, 50, 20, 10, 5, 2, 1};
    int valorTotal = 0;

    do {
        cin >> valorTotal;
    } while (valorTotal < VALOR_MINIMO || valorTotal > VALOR_MAXIMO);

    cout << to_string(valorTotal) + "\n";

    int qtdNotas[NOTAS_ARRAY_SIZE];
    calcularQuantidadeDeNotas(notas, valorTotal, qtdNotas);

    cout << formatarQuantidadeDeNotas(notas, qtdNotas);
    return 0;
}

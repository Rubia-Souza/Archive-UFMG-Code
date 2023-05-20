#include <iostream>

using namespace std;

int main() {

    float nota1 = 0, nota2 = 0, nota3 = 0;
    int faltas = 0;

    cout << "Insira a quantidade de faltas\n";
    cin >> faltas;

    if (faltas > 18) {
        cout << "REPROVADO POR FALTA\n";
        return 0;
    }

    cout << "Insira as notas 1, 2 e 3, respectivamente\n";
    cin >> nota1 >> nota2 >> nota3;

    float media = (nota1 + nota2 + nota3) / 3;
    if (media < 60) {
        cout << "REPROVADO POR MÉDIA\n";
        return 0;
    }

    cout << "“APROVADO”\n";

    return 0;
}

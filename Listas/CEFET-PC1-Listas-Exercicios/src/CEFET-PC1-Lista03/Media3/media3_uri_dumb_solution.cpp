#include <iostream>
#include <iomanip>

using namespace std;

void setUpCout() {
    cout << fixed;
    cout.precision(1);
}

int main() {
    setUpCout();

    const int PESO_1 = 2, PESO_2 = 3, PESO_3 = 4, PESO_4 = 1;
    float n1 = 0, n2 = 0, n3 = 0, n4 = 0;

    cin >> n1 >> n2 >> n3 >> n4;

    float nota1 = n1 * PESO_1;
    float nota2 = n2 * PESO_2;
    float nota3 = n3 * PESO_3;
    float nota4 = n4 * PESO_4;

    float media = (nota1 + nota2 + nota3 + nota4) / (PESO_1 + PESO_2 + PESO_3 + PESO_4);

    cout << "Media: " << media << "\n";

    if (media >= 7) {
        cout << "Aluno aprovado.\n";
        return 0;
    }
    
    if (media < 5) {
        cout << "Aluno reprovado.\n";
        return 0;
    }

    cout << "Aluno em exame.\n";

    float notaExameEspecial = 0;
    cin >> notaExameEspecial;

    cout << "Nota do exame: " << notaExameEspecial << "\n";
    float novaMedia = (media + notaExameEspecial) / 2;

    if (novaMedia >= 5) {
        cout << "Aluno aprovado.\n";
    }
    else {
        cout << "Aluno reprovado.\n";
    }

    cout << "Media final: " << novaMedia << "\n";

    return 0;
}

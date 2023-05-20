#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Prova {
    float nota;
    int peso;
} Prova;

void setUpCout() {
    cout << fixed;
    cout.precision(1);
}

float calcularMedia(Prova provas[]) {
    float sumNotas = 0;
    int sumPesos = 0;

    for (int i = 0; i < 4; i++) {
        sumNotas += provas[i].nota * provas[i].peso;
        sumPesos += provas[i].peso;
    }

    return sumNotas / sumPesos;
}

int main() {
    setUpCout();

    const int pesos[4] = {2, 3, 4, 1};
    float notas[4] = {0, 0, 0, 0};

    cin >> notas[0] >> notas[1] >> notas[2] >> notas[3];

    Prova provas[4];
    for (int i = 0; i < 4; i++) {
        provas[i].nota = notas[i];
        provas[i].peso = pesos[i];
    }

    float media = calcularMedia(provas);
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

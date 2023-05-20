#include <iostream>

using namespace std;

void printMenu();
void printMensagemErroOpcaoInvalida();
void executarOperacao(const int opcaoEscolhida);

int main() {
    setlocale(LC_ALL, "portuguese");
    char deveEncerrar;

    do {
        printMenu();
        
        int opcaoEscolhida = 0;
        bool inseriuOpcaoInvalida = false;
        do {
            cin >> opcaoEscolhida;
            inseriuOpcaoInvalida = opcaoEscolhida < 1 || opcaoEscolhida > 4;

            if (inseriuOpcaoInvalida) {
                printMensagemErroOpcaoInvalida();
            }
        } while (inseriuOpcaoInvalida);

        executarOperacao(opcaoEscolhida);


        do {
            cout << "\nDeseja fazer outra operacao?\n";
            cout << "Digite [s] para continuar\n";
            cout << "Digite [n] para parar\n";

            cin >> deveEncerrar;
        } while (deveEncerrar != 'n' && deveEncerrar != 's');


    } while (deveEncerrar != 'n');

    return 0;
}

void printMenu() {
    cout << "\nEscolha uma das opcoes: \n\n";
    cout << "[1] Soma\n";
    cout << "[2] Subtracao\n";
    cout << "[3] Multiplicacao\n";
    cout << "[4] Divisao\n";

    cout << "Opcao: ";
    return;
}

void printMensagemErroOpcaoInvalida() {
    cout << "\nPor favor insira uma das opcoes validas!\n";
    cout << "Digite um número entre 1 e 4\n";

    cout << "Opcao: ";
    return;
}

void executarOperacao(const int opcaoEscolhida) {
    double numero1 = 0, numero2 = 0, resultado = 0;

    switch (opcaoEscolhida) {
    case 1:
        cout << "\nSomar o numero: ";
        cin >> numero1;
        cout << "com o numero: ";
        cin >> numero2;

        resultado = numero1 + numero2;
        break;

    case 2:
        cout << "\nSubtrair o numero: ";
        cin >> numero1;
        cout << "por: ";
        cin >> numero2;

        resultado = numero1 - numero2;
        break;

    case 3:
        cout << "\nMultiplicar o numero: ";
        cin >> numero1;
        cout << "por: ";
        cin >> numero2;

        resultado = numero1 * numero2;
        break;

    case 4:
        cout << "\nDividir o numero: ";
        cin >> numero1;
        cout << "por: ";
        cin >> numero2;

        if (numero2 == 0) {
            cout << "Operacao invalida!\n";
            return;
        }

        resultado = numero1 / numero2;
        break;
    }

    cout << "\nResultado: " << resultado << "\n";
    return;
}

#include <iostream>

using namespace std;

int main() {

    int ano = 0;
    cin >> ano;

    if (ano % 400 == 0 || ano % 4 == 0 && ano % 100 != 0) {
        cout << "O ano e bisexto\n";
    }
    else {
        cout << "O ano nao e bisexto\n";
    }

    return 0;
}

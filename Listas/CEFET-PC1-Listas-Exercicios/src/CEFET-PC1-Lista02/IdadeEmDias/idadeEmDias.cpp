#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string idadePorExtenso(int diasTotal) {
    int anos = ceil(diasTotal / 365);

    int restoDeDias = diasTotal % 365;
    int meses = ceil(restoDeDias / 30);
    int dias = ceil(restoDeDias % 30);

    string strAnos = to_string(anos);
    string strMeses = to_string(meses);
    string strDias = to_string(dias);

    return (
        strAnos + " ano(s)\n" +
        strMeses + " mes(es)\n" +
        strDias + " dia(s)\n"
    );
}

int main() {
    int idadeDias = 0;

    cin >> idadeDias;

    string idadeExtenso = idadePorExtenso(idadeDias);

    cout << idadeExtenso;
    return 0;
}

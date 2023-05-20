#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string parseTempoExtenso(int tempoTotalSegundos) {
    int horas = (int) ceil(tempoTotalSegundos / 3600);

    int restoDeHorasEmSegundos = tempoTotalSegundos % 3600;
    int minutos = (int) ceil(restoDeHorasEmSegundos / 60);

    int restoDeMinutosEmSegundos = restoDeHorasEmSegundos % 60;
    int segundos = (int) ceil(restoDeMinutosEmSegundos);

    string strHoras = to_string(horas);
    string strMinutos = to_string(minutos);
    string strSegundos = to_string(segundos);

    return (strHoras + ":" + strMinutos + ":" + strSegundos);
}

int main() {
    int tempoTotal = 0;

    cin >> tempoTotal;

    string tempo = parseTempoExtenso(tempoTotal);

    cout << tempo;
    return 0;
}

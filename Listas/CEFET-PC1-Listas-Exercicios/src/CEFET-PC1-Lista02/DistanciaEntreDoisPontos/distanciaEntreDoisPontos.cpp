#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void setUpCout() {
    cout << fixed;
    cout << setprecision(4);
}

double distanciaPontos(float Xponto1, float Yponto1, float Xponto2, float Yponto2) {
    return (sqrt(pow(Xponto2 - Xponto1, 2) + pow(Yponto2 - Yponto1, 2)));
}

int main() {
    float Xponto1 = 0, Yponto1 = 0;
    float Xponto2 = 0, Yponto2 = 0;

    cin >> Xponto1 >> Yponto1;
    cin >> Xponto2 >> Yponto2;

    float distancia = distanciaPontos(Xponto1, Yponto1, Xponto2, Yponto2);
    
    cout << distancia << "\n";
    return 0;
}

#include <iostream>

using namespace std;

int somarSequenciaPar(const int comeco);

int main() {
    int x = 0;
    cin >> x;

    while (x != 0) {
        int resultado = somarSequenciaPar(x);
        cout << resultado << "\n";

        cin >> x;
    }

    return 0;
}

int somarSequenciaPar(const int comeco) {
    int sum = 0;
    for (int i = 0, step = comeco; i < 5; step++) {
        if (step % 2 ==0) {
            sum += step;
            i++;
        }
    }

    return sum;
}

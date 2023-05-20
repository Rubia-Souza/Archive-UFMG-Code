#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int vectorSize = 0;

    while (vectorSize < 1 || vectorSize > 1000) {
        cin >> vectorSize;
        cin.ignore();
    }

    string line;
    getline(cin, line);

    istringstream input(line);
    vector<int> result;
    int value;
    while (input >> value) {
        result.push_back(value);
    }
    input.eof();

    int lowestValue = result[0], index = 0;
    for (int i = 1; i < vectorSize; i++) {
        if (result[i] < lowestValue) {
            lowestValue = result[i];
            index = i;
        }
    }

    cout << "Menor valor: " << lowestValue << "\n";
    cout << "Posicao: " << index << "\n";

    return 0;
}

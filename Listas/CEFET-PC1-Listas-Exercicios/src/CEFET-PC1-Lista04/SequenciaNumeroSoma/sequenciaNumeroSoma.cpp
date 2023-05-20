#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int sumFromLowestToHighest(const int highest, const int lowest);
string concatNumbers(const vector<int> numbers);

int main() {
    vector<int> highestNumbers(0);
    vector<int> lowestNumbers(0);

    int n1 = 0, n2 = 0;
    cin >> n1 >> n2;
    while (n1 > 0 && n2 > 0) {
        int maior = 0, menor = 0;
        if (n1 > n2) {
            maior = n1;
            menor = n2;
        }
        else {
            maior = n2;
            menor = n1;
        }

        highestNumbers.push_back(maior);
        lowestNumbers.push_back(menor);
        cin >> n1 >> n2;
    }
    
    for (int i = 0; i < highestNumbers.size(); i++) {
        vector<int> tempVector(0);
        for (int j = lowestNumbers[i]; j <= highestNumbers[i]; j++) {
            tempVector.push_back(j);
        }

        string numberSequency = concatNumbers(tempVector);
        int sum = sumFromLowestToHighest(highestNumbers[i], lowestNumbers[i]);

        cout << numberSequency << " Sum=" << sum << "\n";
    } 

    return 0;
}

int sumFromLowestToHighest(const int highest, const int lowest) {
    int sum = lowest;
    for (int i = lowest + 1; i <= highest; i++) {
        sum += i;
    }
    return sum;
}

string concatNumbers(const vector<int> numbers) {
    ostringstream os;

    for (int i = 0; i < numbers.size(); i++) {
        os << numbers[i];
        if (i != numbers.size() - 1) {
            os << " ";
        }
    }

    return os.str();
}

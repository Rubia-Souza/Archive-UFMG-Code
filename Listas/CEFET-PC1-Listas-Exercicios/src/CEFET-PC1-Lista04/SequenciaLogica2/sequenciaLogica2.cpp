#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void fillVectorWithSequency(const int startValue, const int finalValue, vector<int> outVector);
string concatNumbers(const vector<int> numbers);

int main() {
    int x = 0, y = 0;

    do {
        cin >> x >> y;
    } while((x < 1 || x > 20) && (y < x || y > 100000));

    vector<int> numbers(0);
    for (int i = 1; i <= y; i++) {
        numbers.push_back(i);
    }

    int count = 0;
    while (count < numbers.size()) {
        vector<int> tempVector(x);
        for (int j = 0; j < x; j++, count++) {
            tempVector[j] = numbers[count];
        }

        string line = concatNumbers(tempVector);
        cout << line << "\n";
    }

    return 0;
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

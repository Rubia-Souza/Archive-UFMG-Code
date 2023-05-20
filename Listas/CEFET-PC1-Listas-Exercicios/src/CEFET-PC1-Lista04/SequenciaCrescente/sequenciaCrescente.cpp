#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string concatNumbers(const vector<int> numbers);

int main() {
    int input = 0;
    vector<int> inputs(0);

    cin >> input;
    while(input != 0){
        inputs.push_back(input);
        cin >> input;
    }

    for (int i = 0; i < inputs.size(); i++){
        vector<int> numbers(inputs[i]);
        for (int j = 0, number = 1; j < inputs[i]; j++, number++) {
            numbers[j] = number;
        }

        string sequency = concatNumbers(numbers);
        cout << sequency << "\n";
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

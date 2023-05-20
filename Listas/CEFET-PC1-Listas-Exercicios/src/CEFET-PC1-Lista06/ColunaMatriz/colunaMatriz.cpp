#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX_LINES_SIZE 12
#define MAX_COLUMNS_SIZE 12

#define SUM 'S'
#define AVERAGE 'M'

void setUpCout(const int precision);
float calculateAverage(const vector<float> values);
float calculateSum(const vector<float> values);

int main() {
    setUpCout(1);

    int targetColumn = 0;
    do {
        cin >> targetColumn;
    } while (targetColumn < 0 || targetColumn > 11);

    char operation;
    do {
        cin >> operation;
    } while (operation != SUM && operation != AVERAGE);

    vector<vector<float>> matrix;
    for (int i = 0; i < MAX_LINES_SIZE; i++) {
        vector<float> line;

        for (int j = 0; j < MAX_COLUMNS_SIZE; j++) {
            float input;
            cin >> input;

            line.push_back(input);
        }

        matrix.push_back(line);
    }

    vector<float> columnsValue;
    for (int i = 0; i < MAX_LINES_SIZE; i++) {
        columnsValue.push_back(matrix[i][targetColumn]);
    }

    float result = 0.0;
    if (operation == SUM) {
        result = calculateSum(columnsValue);
    }
    else {
        result = calculateAverage(columnsValue);
    }

    cout << result << "\n";

    return 0;
}

void setUpCout(const int precision) {
    cout << fixed;
    cout << setprecision(precision);
}

float calculateAverage(const vector<float> values) {
    float sum = calculateSum(values);
    return (sum / values.size());
}

float calculateSum(const vector<float> values) {
    float sum = 0.0;

    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }

    return sum;
}

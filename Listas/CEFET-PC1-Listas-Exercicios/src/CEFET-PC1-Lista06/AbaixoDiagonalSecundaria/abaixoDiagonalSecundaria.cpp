#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX_LINES_SIZE 12
#define MAX_COLUMNS_SIZE 12

#define SUM 'S'
#define AVERAGE 'M'

void setUpCout(const int precision);
float calculateAverage(const vector<vector<float>> values);
float calculateSum(const vector<vector<float>> values);

int main() {
    setUpCout(1);

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

    float result = 0.0;
    if (operation == SUM) {
        result = calculateSum(matrix);
    }
    else {
        result = calculateAverage(matrix);
    }

    cout << result << "\n";

    return 0;
}

void setUpCout(const int precision) {
    cout << fixed;
    cout << setprecision(precision);
}

float calculateAverage(const vector<vector<float>> values) {
    float sum = calculateSum(values);
    int elements = 0;

    for (int i = 1; i < values.size(); i++) {
        elements += i;
    }

    return (sum / elements);
}

float calculateSum(const vector<vector<float>> values) {
    float sum = 0.0;

    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i + j > values.size() - 1) {
                sum += values[i][j];
            }
        }
    }

    return sum;
}

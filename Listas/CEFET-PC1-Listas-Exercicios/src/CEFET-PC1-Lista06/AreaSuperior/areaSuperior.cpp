#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

#define MAX_LINES_SIZE 12
#define MAX_COLUMNS_SIZE 12

#define SUM 'S'
#define AVERAGE 'M'

void setUpCout(const int precision);
double calculateAverage(const vector<vector<double>> values);
double calculateSum(const vector<vector<double>> values);

int main() {
    setUpCout(1);

    char operation;
    do {
        cin >> operation;
    } while (operation != SUM && operation != AVERAGE);

    vector<vector<double>> matrix;
    for (int i = 0; i < MAX_LINES_SIZE; i++) {
        vector<double> line;

        for (int j = 0; j < MAX_COLUMNS_SIZE; j++) {
            double input;
            cin >> input;

            line.push_back(input);
        }

        matrix.push_back(line);
    }

    double result = 0.0;
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

double calculateAverage(const vector<vector<double>> values) {
    double sum = calculateSum(values);
    int elements = 0;

    for (int i = 0; i < ceil(values.size()/2); i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i + j < values.size() - 1 && j > i) {
               elements++;
            }
        }
    }

    return (sum / elements);
}

double calculateSum(const vector<vector<double>> values) {
    double sum = 0.0;

    for (int i = 0; i < ceil(values.size()/2); i++) {
        for (int j = 0; j < values.size(); j++) {
            if (i + j < values.size() - 1 && j > i) {
                sum += values[i][j];
            }
        }
    }

    return sum;
}

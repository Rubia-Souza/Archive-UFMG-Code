#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void buildMatrix(const int order);
void printMatrix(const vector<vector<int>> matrix, const int order);

int main() {
    vector<int> matrixOrders;
    int order = 0;

    do {
        do {
            cin >> order;
        } while (order < 0 || order > 100);

        matrixOrders.push_back(order);
    } while (order != 0);
    matrixOrders.pop_back();

    for (int i = 0; i < matrixOrders.size(); i++) {
        buildMatrix(matrixOrders[i]);
        cout << "\n";
    }
    
    return 0;
}

void buildMatrix(const int order) {
    vector<vector<int>> matrix(order, vector<int>(order));

    for (int i = 0; i < order; i++) {
        int value = i + 2;
        for (int j = 0; j < order; j++) {
            if (i > j) {
                value--;
            }
            else if (i == j) {
                value = 1;
            }
            else if (i < j) {
                value++;
            }

            matrix[i][j] = value;
        }
    }

    printMatrix(matrix, order);
    return;
}

void printMatrix(const vector<vector<int>> matrix, const int order) {
    for (int i = 0; i < order; i++) {
        cout << setfill(' ') << setw(3);
        for (int j = 0; j < order; j++) {
            if (j == 0) {
            }

            cout << matrix[i][j];
            if (j < order - 1) {
                cout << " " << setfill(' ') << setw(3);
            }
        }

        cout << "\n";
    }

    return;
}

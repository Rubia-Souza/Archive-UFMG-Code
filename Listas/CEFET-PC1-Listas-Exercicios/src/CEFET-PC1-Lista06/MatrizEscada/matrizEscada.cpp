#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void getLineNumbers(vector<int> *outNumbers);
bool isLadderMatrix(const vector<vector<int>> matrix, const int lines, const int columns);

int main() {
    int lines = 0, columns = 0;
    do {
        cin >> lines >> columns;
        cin.ignore();
    } while ((lines < 1 || lines > 500) && (columns < 1 || columns > 500));

    vector<vector<int>> matrix;
    for (int i = 0; i < lines; i++) {
        vector<int> numbersInLine;
        getLineNumbers(&numbersInLine);

        matrix.push_back(numbersInLine);
    }

    if (isLadderMatrix(matrix, lines, columns)) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}

void getLineNumbers(vector<int> *outNumbers) {
    string line;
    getline(cin, line);

    unsigned int value;
    istringstream input(line);
    while (input >> value) {
        outNumbers->push_back(value);
    }
    input.eof();

    return;
}

bool isLadderMatrix(const vector<vector<int>> matrix, const int lines, const int columns) {
    int lastNoneZeroNumberColumn = -1;
    bool lastLineWasNull = false;
    for (int i = 0; i < lines; i++) {
        bool hasFoundFirstNoneZeroNumber = false;

        for (int j = 0; j < columns; j++) {
            bool actualNumberIsZero = matrix[i][j] == 0;

            if (!actualNumberIsZero) {
                if (j <= lastNoneZeroNumberColumn) {
                    return false;
                }
                else if (!hasFoundFirstNoneZeroNumber) {
                    lastNoneZeroNumberColumn = j;
                }
                hasFoundFirstNoneZeroNumber = true;
                break;
            }
        }

        if (lastLineWasNull && hasFoundFirstNoneZeroNumber) {
            return false;
        }

        lastLineWasNull = !hasFoundFirstNoneZeroNumber;
    }

    return true;
}

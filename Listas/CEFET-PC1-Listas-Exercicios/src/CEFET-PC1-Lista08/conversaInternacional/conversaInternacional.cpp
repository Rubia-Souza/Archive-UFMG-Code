#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned int getAmountTestCases();
unsigned int getAmountOfPeople();
void getLanguages(const int amountPeople, vector<string> *outLanguages);
bool shouldUseEnglish(const vector<string> languages);

int main() {
    unsigned int testAmount = getAmountTestCases();

    for(int i = 0; i < testAmount; i++) {
        unsigned int amountPeople = getAmountOfPeople();

        vector<string> languages;
        getLanguages(amountPeople, &languages);
        
        if(shouldUseEnglish(languages)) {
            cout << "ingles\n";
        }
        else {
            cout << languages[0] << "\n";
        }
    }

    return 0;
}

unsigned int getAmountTestCases() {
    unsigned int testAmount = 0;
    
    do {
        cin >> testAmount;
        cin.ignore();
    } while(testAmount < 0);

    return testAmount;
}

unsigned int getAmountOfPeople() {
    unsigned int amountPeople = 0;
    do {
        cin >> amountPeople;
        cin.ignore();
    } while(amountPeople < 2 || amountPeople > 100);

    return amountPeople;
}

void getLanguages(const int amountPeople, vector<string> *outLanguages) {
    string line = "";
    vector<string> languages;

    for(int i = 0; i < amountPeople; i++) {
        getline(cin, line);
        languages.push_back(line);
    }

    *outLanguages = languages;
    return;
}

bool shouldUseEnglish(const vector<string> languages) {
    string testLanguage = languages[0];

    for(int i = 1; i < languages.size(); i++) {
        if(testLanguage.compare(languages[i]) != 0) {
            return true;
        }
    }

    return false;
}

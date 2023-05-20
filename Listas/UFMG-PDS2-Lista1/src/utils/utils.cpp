#include <iostream>
#include <string>
#include <sstream>

std::string getLine() {
    std::stringstream input;
    input.clear();

    std::string temp = "";
    while(std::cin >> temp) {
        input << temp << " ";
    }

    return input.str();
}

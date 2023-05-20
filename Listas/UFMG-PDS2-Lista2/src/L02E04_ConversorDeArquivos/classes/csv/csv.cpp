#include <string>
#include <vector>
#include <sstream>

#include "./csv.hpp"
#include "../file/file.hpp"
#include "../ireadable/ireadable.hpp"

#define SPLIT_CHARACTER ';'

CSV::CSV() {}

CSV::~CSV() {}

void CSV::split(const std::string& reference, std::vector<std::string>& splitedString) const {
    std::string stringPart = "";

    for(char character : reference) {
        if(character != SPLIT_CHARACTER) {
            stringPart.push_back(character);
        }
        else {
            splitedString.push_back(stringPart);
            stringPart.clear();
        }
    }

    splitedString.push_back(stringPart);
    stringPart.clear();

    return;
}

std::string CSV::getHeader(const IReadable& object) const {
    std::vector<std::string> columns;
    object.GetCampos(columns);

    return concat(columns);
}

std::string CSV::concat(const std::vector<std::string>& reference) const {
    if(reference.size() <= 0) {
        return "";
    }

    std::stringstream result;
    result.clear();

    for(unsigned int i = 0; i < reference.size(); i++) {
        std::string word = reference[i];

        result << word;
        if(i != reference.size() - 1) {
            result << SPLIT_CHARACTER;
        }
    }
    

    return result.str();
}

void CSV::readLine(const std::string& head, const std::string& line, IReadable& object) const {
    std::vector<std::string> attributes;
    split(head, attributes);

    std::vector<std::string> values;
    split(line, values);

    for(unsigned int i = 0; i < attributes.size() && i < values.size(); i++) {
        std::string attribute = attributes[i];
        std::string value = values[i];

        object.setAtributo(attribute, value);
    }

    return;
}

std::string CSV::write(const IReadable& object) const {
    std::vector<std::string> attributes;
    object.GetCampos(attributes);

    std::vector<std::string> values;
    for(std::string attribute : attributes) {
        values.push_back(object.GetAtributo(attribute));
    }
    
    return concat(values);
}

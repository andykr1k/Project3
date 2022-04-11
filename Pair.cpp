//
// Created by Andrew Krikorian on 4/7/22.
//

#include "Pair.hpp"

bool Pair::isDouble() {
    return _isNumber;
}

double Pair::numberValue() {
    return _attributeNumberValue;
}

std::string Pair::stringValue() {
    return _attributeStringValue;
}

std::string Pair::attributeName() {
    return _attributeName;
}

void Pair::printInJSON(int numSpaces) {
    std::cout << "\"" << _attributeName << "\""  <<" : " << _attributeStringValue << std::endl;
}

void Pair::printInCSV() {
    std::cout << _attributeStringValue << std::endl;
}

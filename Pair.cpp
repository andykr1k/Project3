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
    if (_attributeStringValue.empty()){
        std::cout << std::fixed << std::setprecision(11) << std::setw(numSpaces)<< "\"" << _attributeName << "\""  <<" : " << _attributeNumberValue;
    } else {
        std::cout << std::setw(numSpaces) << "\"" << _attributeName << "\""  <<" : \"" << _attributeStringValue << "\"";
    }
}

void Pair::printInCSV(bool name) {
    if (_attributeStringValue.empty()){
        std::cout << std::fixed << std::setprecision(4)  << _attributeNumberValue;
    } else {
        std::cout << _attributeStringValue;
    }
}

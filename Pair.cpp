//
// Created by Andrew Krikorian on 4/7/22.
//

#include "Pair.hpp"

std::string Pair::stringValue() {
    return _attributeStringValue;
}

std::string Pair::attributeName() {
    return _attributeName;
}

void Pair::printInJSON(int numSpaces) {
    if (_attributeStringValue.empty()){
        if ((!_isNumber) && _isInt){
            std::cout << std::setw(numSpaces) << "\"" << _attributeName << "\"" << " : " << _attributeIntValue;
        } else {
            std::cout << std::fixed << std::setprecision(10) << std::setw(numSpaces) << "\"" << _attributeName << "\"" << " : " << _attributeDoubleValue;
        }
    } else {
        std::cout << std::setw(numSpaces) << "\"" << _attributeName << "\""  <<" : \"" << _attributeStringValue << "\"";
    }
}

void Pair::printInCSV(bool name) {
    if (!name){
        if ((!_isNumber) && _isInt){
            std::cout << _attributeIntValue;
        } else {
            std::cout << std::fixed << std::setprecision(4) << _attributeDoubleValue;
        }
    } else {
        std::cout << _attributeStringValue;
    }
}

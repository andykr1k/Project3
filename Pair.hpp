//
// Created by Andrew Krikorian on 4/7/22.
//

#ifndef PROJECT3_PAIR_HPP
#define PROJECT3_PAIR_HPP
#include <string>
#include <iomanip>
#include <iostream>
class Pair {
public:
    Pair(std::string attributeName,std::string attributeValue, double valueDouble, int valueInt, bool doubleQ, bool stringQ){
        if (stringQ) {
            _attributeName = attributeName;
            _attributeStringValue = attributeValue;
            _isNumber = false;
        } else {
            if (!doubleQ){
                _attributeName = attributeName;
                _isInt = true;
                _attributeIntValue = valueInt;
            } else {
                _attributeName = attributeName;
                _attributeDoubleValue = valueDouble;
                _isNumber = true;
            }
        }
    };
    bool isNumber() { return _isNumber; };
    bool isInt() { return _isInt; };
    double getDoubleValue() { return _attributeDoubleValue; };
    int getIntValue() { return _attributeIntValue; };
    std::string stringValue();
    std::string attributeName();
    void printInJSON(int numSpaces);
    void printInCSV(bool name);

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeDoubleValue;
    int _attributeIntValue;
    bool _isNumber, _isInt;
};


#endif //PROJECT3_PAIR_HPP

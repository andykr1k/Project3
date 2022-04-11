//
// Created by Andrew Krikorian on 4/7/22.
//

#ifndef PROJECT3_PAIR_HPP
#define PROJECT3_PAIR_HPP
#include <string>
#include <iostream>
class Pair {
public:
    Pair(std::string attributeName, std::string attributeValue): _isNumber{false} {};
    //Pair(std::string attributeName, double): _isNumber{true} {};
    bool isDouble();
    double numberValue();
    void setNumberValue(double num) { _attributeNumberValue = num; };
    std::string stringValue();
    void setStringValue(std::string str) { _attributeStringValue = str; } ;
    std::string attributeName();
    void setAttributeName(std::string name) { _attributeName = name; };
    void printInJSON(int numSpaces);
    void printInCSV();

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};


#endif //PROJECT3_PAIR_HPP

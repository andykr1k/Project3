//
// Created by Andrew Krikorian on 3/9/22.
//
#include <string>
#include <iostream>
#include <fstream>
#include "JSONToken.hpp"
using namespace std;

void JSONToken::print(){
    if (isOBracket()) {
        cout << getSymbol() << endl;
    } else if (isCBracket()){
        cout << getSymbol() << endl;
    } else if (isCBrace()){
        cout << getSymbol() << endl;
    } else if (isOBrace()){
        cout << getSymbol() << endl;
    } else if (isQuote()){
        cout << getSymbol() << endl;
    } else if (isHyphen()){
        cout << getSymbol() << endl;
    } else if (isDot()){
        cout << getSymbol() << endl;
    } else if (isComma()){
        cout << getSymbol() << endl;
    } else if (isColon()){
        cout << getSymbol() << endl;
    } else if (isWord()){
        cout << getWord() << endl;
    } else if (isDouble()){
        cout << getDouble() << endl;
    } else if (isInt()){
        cout << getInt() << endl;
    } else {
        cout << "No Token";
    }
}
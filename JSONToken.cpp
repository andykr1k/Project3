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
        cout << endl;
        cout << getSymbol();
    } else if (isCBrace()){
        cout << endl;
        cout << getSymbol();
    } else if (isOBrace()){
        cout << getSymbol() << endl;
    } else if (isQuote()){
        //Print Nothing
    } else if (isHyphen()){
        cout << getSymbol();
    } else if (isDot()){
        cout << getSymbol();
    } else if (isComma()){
        cout << endl;
        cout << getSymbol() << endl;
    } else if (isColon()){
        cout << endl;
        cout << getSymbol() << endl;
    } else if (isWord()){
        cout << getWord();
    } else if (isNumber()){
        cout << getNumber();
    } else {
        cout << "No Token";
    }
}
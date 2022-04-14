//
// Created by Andrew Krikorian on 3/9/22.
//

#ifndef PROJECT3_JSONTOKEN_HPP
#define PROJECT3_JSONTOKEN_HPP
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class JSONToken {
public:
    //Set Token Structure
    JSONToken(): _isSymbol{false}, _isWord{false}, _isDouble{false}, _isInt{false}, _eof{false} {};

    //Sets variables of Token based off arguments
    void makeWord(string n) {
        _word = n;
        _isWord = true;
    }
    void makeDouble(double n) {
        _double = n;
        _isDouble = true;
    }
    void makeInt(int n) {
        _int = n;
        _isInt = true;
    }
    void makeSymbol(char c){
        _symbol = c;
        _isSymbol = true;
    }
    //Gets variables from taken
    double getDouble() { return _double; }
    int getInt() { return _int; }
    string getWord() { return _word; }
    char getSymbol() { return _symbol; }

    //Symbol Map
    bool isSymbol() { return _isSymbol; }
    bool isWord() { return _isWord; }
    bool isDouble() { return _isDouble; }
    bool isInt() { return _isInt; }
    bool isComma() { return _isSymbol && _symbol == ','; }
    bool isHyphen() { return _isSymbol && _symbol == '-'; }
    bool isQuote() { return _isSymbol && _symbol == '"'; }
    bool isDot() { return _isSymbol && _symbol == '.'; }
    bool isColon() { return _isSymbol && _symbol == ':'; }
    bool isOBracket() { return (_isSymbol && _symbol == '[' ); }
    bool isCBracket() { return (_isSymbol && _symbol == ']' ); }
    bool isOBrace() { return (_isSymbol && _symbol == '{'); }
    bool isCBrace() { return (_isSymbol && _symbol == '}'); }

    //File Functions
    bool endOfFile() { return _eof; }
    void makeEOF() { _eof = true; }
    void print();

private:
    string _word;
    double _double;
    int _int;
    char _symbol;

    bool _isSymbol;
    bool _isWord;
    bool _isDouble;
    bool _isInt;
    bool _eof;
};


#endif //PROJECT3_JSONTOKEN_HPP

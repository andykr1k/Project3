//
// Created by Andrew Krikorian on 3/9/22.
//

#ifndef PROJECT3_JSONTOKENIZER_HPP
#define PROJECT3_JSONTOKENIZER_HPP
#include <string>
#include <iostream>
#include <fstream>
#include "JSONToken.hpp"
using namespace std;

class JSONTokenizer {
public:
    JSONTokenizer(string inputFile);
    JSONToken getToken();
    bool isSymbol(char c);
    bool isNegativeSign(char c);

private:
    string inputFileName;
    fstream inputStream;
};


#endif //PROJECT3_JSONTOKENIZER_HPP

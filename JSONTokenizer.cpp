//
// Created by Andrew Krikorian on 3/9/22.
//
#include <string>
#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"

JSONTokenizer::JSONTokenizer(string inputFile): inputFileName{inputFile} {
    inputStream.open(inputFile, std::ios::in);
}

bool JSONTokenizer::isSymbol(char c){
    return c == '[' || c == ']' || c == '{' || c == '}' || c == ':' || c == ',' || c == '"' || c == '.' || c == '-';
}


JSONToken JSONTokenizer::getToken() {
    if (!inputStream.is_open()){
        cout << "Error: Input Stream in Tokenizer" << endl;
        exit(3);
    }

    char c;
    inputStream >> c;

    if ( inputStream.eof() ){
        JSONToken token;
        token.makeEOF();
        return token;
    }

    if ( isSymbol(c) ){
        JSONToken token;
        token.makeSymbol(c);
        return token;
    }

    if ( isdigit(c) ){
        inputStream.putback(c);
        double number;
        inputStream >> number;
        JSONToken token;
        token.makeNumber(number);
        return token;
    }

    inputStream.putback(c);
    string word;
    while (getline(inputStream, word, '"') ) {
        JSONToken token;
        token.makeWord(word);
        return token;
    }

    cout << "Unexpected Character" << c << endl;
    cout << "Terminating.." << endl;
    exit(5);
}

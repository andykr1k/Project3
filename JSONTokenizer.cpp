#include "JSONTokenizer.hpp"

#include <fstream>
#include <iostream>
#include "JSONToken.hpp"
#include <cstdlib>
#include <string>

JSONTokenizer::JSONTokenizer(std::string inputFile): inputFileName{inputFile}{
    inputStream.open(inputFile, std::ios::in);
}

bool JSONTokenizer::isSymbol(char c) {
    if(c == ',' || c == ':' || c == '{' || c == '}' || c == '[' || c == ']' || c == '"' || c== '-' || c=='.') {
        return true;
    } else {
        return false;
    }
}

JSONToken JSONTokenizer::getToken() {
    if(!inputStream.is_open()){
        std::cout << "Input stream in JSONTokenizer::getToken is not open. Terminating...\n";
        exit(4);
    }

    char c;
    inputStream >> c;
    if ( inputStream.eof()){
        JSONToken token;
        token.makeEOF();
        return token;
    }

    if(isSymbol(c)){
        JSONToken token;
        token.makeSymbol(c);
        return token;
    }

    if( isdigit(c) ){
        inputStream.putback(c);
        string number;
        inputStream >> number;
        bool Defdouble = false;
        for ( int i = 0; i < number.size(); i++ ){
            if ( number[i] == '.'){
                Defdouble = true;
            }
        }
        if(number[number.length()-1] == ',') {
            if (isdigit(number[number.length() - 2])) {
                inputStream.putback(number[number.length() - 1]);
                if (Defdouble){
                    JSONToken token;
                    token.makeDouble(stod(number));
//                    cout << "Made Double" << endl;
//                    token.print();
                    return token;
                } else {
                    JSONToken token;
                    token.makeInt(stoi(number));
//                    cout << "Made Int" << endl;
//                    token.print();
                    return token;
                }
            } else if (number[number.length() - 2] == '"') {
                inputStream.putback(number[number.length() - 1]);
                number = number.substr(0, number.length() - 2);
                JSONToken token;
                token.makeWord(number);
//                cout << "Made Word" << endl;
//                token.print();
                return token;
            }
        }
        else {
            if (isdigit(number[number.length() - 1])) {
                if (Defdouble){
                    JSONToken token;
                    token.makeDouble(stod(number));
//                    cout << "Made Double" << endl;
//                    token.print();
                    return token;
                } else {
                    JSONToken token;
                    token.makeInt(stoi(number));
//                    cout << "Made Int" << endl;
                    return token;
                }
            } else if (number[number.length() - 1] == '"') {
                number = number.substr(0, number.length() - 1);
                JSONToken token;
                token.makeWord(number);
//                cout << "Made Word" << endl;
//                token.print();
                return token;
            }
        }
    }

    inputStream.putback(c);
    string word;
    while (getline(inputStream, word, '"')) {
        JSONToken token;
        token.makeWord(word);
        return token;
    }

    std::cout << "Unexpected character in input ->" << c << "<-\n";
    std::cout << "Terminating...\n";
    exit(5);

}
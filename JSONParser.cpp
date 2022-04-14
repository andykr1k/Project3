#include "JSONParser.hpp"
#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include <cstdlib>
#include <string>
#include <memory>
#include <cassert>
using namespace std;


Pair JSONParser::parseAPair() {

    JSONToken token = tokenizer.getToken();
//    cout << "Before name: ";
//    token.print();
    string name;

    token = tokenizer.getToken();
//    cout << "Before word: ";
//    token.print();
    name = token.getWord();

    token = tokenizer.getToken();
//    cout << "Before colon: ";
//    token.print();
    string colon = token.getWord();

    string secondName;
    double value;
    int valueInt = -7777;

    token = tokenizer.getToken();
//        token.print();
    if (token.isDouble()){
//        cout << "is double hit!";
        value = token.getDouble();
    } else if (token.isInt()) {
//        cout << "is int hit!";
        valueInt = token.getInt();
    } else {
//        cout << "is word hit!";
        token = tokenizer.getToken();
        secondName = token.getWord();
    }

    if(secondName.empty()){
        if ( valueInt == -7777 ){
            //cout << "is Double " << name << value;
            Pair pair(name,secondName, value, valueInt, true, false);
            return pair;
        } else {
            //cout << "is Int" << name << valueInt;
            Pair pair(name,secondName, value, valueInt, false, false);
            return pair;
        }
    } else{
        //cout << "Is word" << name << secondName;
        Pair pair(name, secondName, value, valueInt, false, true);
        return pair;
    }
}

EntityInstance JSONParser::parseJSONObject() {

    JSONToken token = tokenizer.getToken();
    if( ! token.isOBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addPair(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );

    if( ! token.isCBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

EntitySet JSONParser::parseJSONEntity() {

    JSONToken token = tokenizer.getToken();
    if( ! token.isOBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntitySet set;
    do {
        EntityInstance instance = parseJSONObject();
        set.addEntity(instance);
        token = tokenizer.getToken();
    } while( token.isComma() );

    if( ! token.isCBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return set;
}


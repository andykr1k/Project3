//
// Created by Andrew Krikorian on 4/11/22.
//
#include <fstream>
#include <iostream>
#include "JSONParser.hpp"

Pair JSONParser::parseAPair() {
    std::string name1;
    std::string valueString;
    std::string colon;
    double value;

    JSONToken token = tokenizer.getToken();
    if( ! token.isQuote() ) {
        std::cout << "Error: JSONParser::parseJSONpair: Expected a qoute but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    token = tokenizer.getToken();
    name1 = token.getWord();

    token = tokenizer.getToken();
    if( ! token.isColon() ) {
        std::cout << "Error: JSONParser::parseJSONpair: Expected a colon but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    //token = tokenizer.getToken();
    do {
        token = tokenizer.getToken();
        value = token.getNumber();
    } while ( token.isNumber());

    do {
        token = tokenizer.getToken();
        valueString = token.getWord();
    } while ( token.isQuote() );

    if ( valueString.empty() ){
        Pair pair1(name1, value);
        pair1.printInJSON(5);
        return pair1;
    } else {
        Pair pair1(name1, valueString);
        pair1.printInJSON(5);
        return pair1;
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
        std::cout << "Error: JSONParser::parseJSONEntity: Expected an open bracket, but found" << std::endl;
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
        std::cout << "Error: JSONParser::parseJSONEntity: Expected an close bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return set;
}


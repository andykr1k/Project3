//
// Created by Andrew Krikorian on 4/11/22.
//

#include "JSONParser.hpp"

Pair JSONParser::parseAPair() {
    std::string name1;
    std::string value;
    double value1;
    bool double1;

    JSONToken token = tokenizer.getToken();
    if( ! token.isQuote() ) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected a qoute but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    do {
        name1 = token.getWord();
        token = tokenizer.getToken();
    } while( token.isQuote() );

    if( ! token.isColon() ) {
        std::cout << "Error: JSONParser::parseJSONEntity: Expected a colon but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(2);
    }
    do {
        Pair pair(std::string name, std::string value);
        value = token.getWord();
        token = tokenizer.getToken();
    } while( token.isQuote() );

    do {
        Pair pair(std::string name, double value);
        value1 = token.getNumber();
        token = tokenizer.getToken();
    } while( token.isNumber() );

    if( ! token.isComma() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected a comma, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    return pair(name1, value);
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
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return set;
}


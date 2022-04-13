#include "JSONParser.hpp"
#include "Pair.hpp"
#include "JSONTokenizer.hpp"
#include <cstdlib>
#include <string>
#include <memory>
using namespace std;


Pair JSONParser::parseAPair() {

    JSONToken token = tokenizer.getToken();
    string name;

    //grabs name for token
    token = tokenizer.getToken();
    name = token.getWord();

    //grabs the uselsess colon
    token = tokenizer.getToken();
    string colon = token.getWord();

    //tokenizer.getToken();
    string secondName;
    double value;
    token = tokenizer.getToken();
    if (token.isNumber()){
        value = token.getNumber();
    }
    else{
        token = tokenizer.getToken();
        secondName = token.getWord();
    }

    if(secondName.empty()){
        Pair pair(name,value);
        return pair;
    }
    else{
        Pair pair(name, secondName);
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
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
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
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    set.printInJSON(5);
    return set;
}


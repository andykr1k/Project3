//
// Created by Andrew Krikorian on 4/11/22.
//

#ifndef PROJECT3_JSONPARSER_HPP
#define PROJECT3_JSONPARSER_HPP
#include "JSONTokenizer.hpp"
#include "EntitySet.hpp"

class JSONParser {
public:
    JSONParser(std::string nameOfInputFile): tokenizer(nameOfInputFile){};

    Pair parseAPair();
    EntityInstance parseJSONObject();
    EntitySet parseJSONEntity();

private:
    JSONTokenizer tokenizer; // the input file name is used to create an instance of JSONTOkenizer
    // please note that there is not an ampersand in front of "tokenizer"
};


#endif //PROJECT3_JSONPARSER_HPP

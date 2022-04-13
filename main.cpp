#include <string>
#include <iostream>
#include <fstream>
#include "JSONToken.hpp"
#include "JSONTokenizer.hpp"
#include "EntityInstance.hpp"
#include "EntitySet.hpp"
#include "Pair.hpp"
#include "JSONParser.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    /*std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();

    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONToken token = jsonTokenizer.getToken();
    while( ! token.endOfFile() ) {
        token.print();
        token = jsonTokenizer.getToken();
    }*/


    JSONParser parser("inputJSONTest.json");
    parser.parseAPair();

    //JSONParser parser2("nameOfSomeJSONInputFile.txt");
    //parser2.parseJSONObject();

    //JSONParser parser3("aapl-2021-01-02-to-2022-03-23_raw_w_date_input_pp.json");
    //parser3.parseJSONEntity();

    return 0;
}

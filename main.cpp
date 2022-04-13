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

    JSONParser parser3("inputJSONTest.json");
    EntitySet set = parser3.parseJSONEntity();
    //set.printInJSON(5);

    //string name = "Andy";
    //double number = 101.101;
    //Pair pair = Pair(name,number);
    //EntityInstance instance1 = set.getEntityInstances().at(1);
    //instance1.addPair(pair);
    //set.changeEntity(1,instance1);
    set.printInJSON(5);
    //cout << set.getEntityInstances().at(0).getClose() << endl;

    std::vector<string> keys = {"Date","Open","High","Low","Close","Volume","EMA-12","EMA-26","MACD","Signal"};
    set.printInCSV(keys);
    cout << endl;
    set.getEntityInstances().at(0).printInCSV(keys);
    return 0;
}

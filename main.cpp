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
    if ( argc != 3 ){
        cout << "Error: Missing a parameter - argv[1]:" << argv[1] << ", argv[2]:" << argv[2] << endl;
    }

    JSONParser parser3(argv[2]);
    EntitySet set = parser3.parseJSONEntity();

    string argument = argv[1];

    if (argument == "-json"){
        set.printInJSON(5);
    }
    if (argument == "-csv"){
        std::vector<string> keys = {"Date","Open","High","Low","Close","Volume","EMA-12","EMA-26","MACD","Signal"};
        set.printInCSV(keys);
        cout << endl;
        for (int i = 0; i < set.getEntityInstances().size(); i++) {
            set.getEntityInstances().at(i).printInCSV(keys);
            cout << endl;
        }
    }


    //string name = "Andy";
    //double number = 101.101;
    //Pair pair = Pair(name,number);
    //EntityInstance instance1 = set.getEntityInstances().at(1);
    //instance1.addPair(pair);
    //set.changeEntity(1,instance1);
    //set.printInJSON(5);

    return 0;
}

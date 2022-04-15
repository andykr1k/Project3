#include <string>
#include <iostream>
#include <fstream>
#include "JSONToken.hpp"
#include "JSONTokenizer.hpp"
#include "EntityInstance.hpp"
#include "EntitySet.hpp"
#include "Pair.hpp"
#include "JSONParser.hpp"
#include "EquityStats.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    if ( argc != 3 ){
        cout << "Error: Missing a parameter - argv[1]:" << argv[1] << ", argv[2]:" << argv[2] << endl;
    }

    JSONParser parser3(argv[2]);
    EntitySet set = parser3.parseJSONEntity();

    std::vector<string> keys = {"Date","Close","EMA-12","EMA-26","MACD","Signal"};
    string argument = argv[1];

    EquityStats stats = EquityStats( set );
    stats.calculateSMA12();
    stats.calculateSMA26();
    stats.calculateExponentialMovingAverage(12);
    stats.calculateExponentialMovingAverage(26);
    stats.calculateMACD();
    stats.calculateSignal(9);

    if (argument == "-json"){
        stats.printJSON(5);
    }
    if (argument == "-csv"){
        stats.printCSV(keys);
    }

    return 0;
}

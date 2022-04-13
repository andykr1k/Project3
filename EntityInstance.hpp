//
// Created by Andrew Krikorian on 4/7/22.
//

#ifndef PROJECT3_ENTITYINSTANCE_HPP
#define PROJECT3_ENTITYINSTANCE_HPP
#include <string>
#include <vector>
#include "Pair.hpp"

class EntityInstance {
public:
    void addPair(Pair &pair) { entityPairs.push_back(pair); };
    int numAttributes() { return numPairs; };

    std::vector<std::string> attributeNames();
    void print();

    void printInJSON(int numSpaces);
    void printInCSV();

    /*
    double getClose() { return close; };
    double getOpen() { return open; };
    double getHigh() { return high; };
    double getLow() { return low; };
    double getVolume() { return volume; };
    double getDividends() { return dividends; };
    double getStocksplits() { return stocksplits; };
    std::string getDate() { return date; };
    std::string getTimestamp() { return timestamp; };
    double getEma12() { return ema12; };
    double getEma26() { return ema26; };
    double getMacd() { return macd; };
    double getSignal() { return signal; };
     */

    // an accessor function that return the
    // value associated with an attribute. In this case, the value.
    // of attribute, Close. You will need to add more such functions
    // to this class.
private:
    std::vector<Pair> entityPairs;
    int numPairs;
};


#endif //PROJECT3_ENTITYINSTANCE_HPP

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
    int numAttributes() { return entityPairs.size(); };

    void print();

    void printInJSON(int numSpaces);
    void printInCSV(std::vector<std::string>keyValues);

/*
    double getClose();
    double getOpen();
    double getHigh();
    double getLow();
    double getVolume();
    double getDividends();
    double getStocksplits();
    std::string getDate();
    std::string getTimestamp();
    double getEma12();
    double getEma26();
    double getMacd();
    double getSignal();
*/

private:
    std::vector<Pair> entityPairs;
};


#endif //PROJECT3_ENTITYINSTANCE_HPP

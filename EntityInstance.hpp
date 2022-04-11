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
    void addPair(Pair &pair); // Add a new pair to this entity.
    int numAttributes();  // how many pairs are in this instance?
    std::vector<std::string> attributeNames();
    void print();   // prints this object.
    // more member functions here when necessary.
    void printInJSON(int numSpaces);
    void printInCSV();

    double close();
    double open();
    double high();
    double low();
    double volume();
    double dividends();
    double stocksplits();
    std::string date();
    std::string timestamp();
    double ema12();
    double ema26();
    double macd();
    double signal();
    // an accessor function that return the
    // value associated with an attribute. In this case, the value.
    // of attribute, Close. You will need to add more such functions
    // to this class.
private:
    std::vector<Pair> entityPairs;
    // more variables here as necessary.
};


#endif //PROJECT3_ENTITYINSTANCE_HPP

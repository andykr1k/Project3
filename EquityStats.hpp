//
// Created by Andrew Krikorian on 4/11/22.
//

#ifndef PROJECT3_EQUITYSTATS_HPP
#define PROJECT3_EQUITYSTATS_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "EntitySet.hpp"
using namespace std;

class EquityStats {
public:
    EquityStats( EntityInstance &instanceOfEntitySet ): attributesToPrint{} instanceCopy{instanceOfEntitySet} {};

    void calculateExponentialMovingAverage(int);
    double calculateSMA(int);
    double calculateMACD();
    double calculateSignal(int);
    void print(vector<string> attributes);
private:
    vector<string> attributesToPrint;
    EntityInstance instanceCopy{};
};


#endif //PROJECT3_EQUITYSTATS_HPP

//
// Created by Andrew Krikorian on 4/11/22.
//

#ifndef PROJECT3_EQUITYSTATS_HPP
#define PROJECT3_EQUITYSTATS_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class EquityStats {
public:
    double calculateExponentialMovingAverage(int days);
    double calculateMACD();
    double calculateSignal(int days);
    void print(vector<string> attributes);
private:
    vector<string> attributesToPrint;
};


#endif //PROJECT3_EQUITYSTATS_HPP

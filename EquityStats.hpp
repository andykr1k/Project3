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
    EquityStats( EntitySet &instanceOfEntitySet ): instanceCopy{instanceOfEntitySet} {};

    void calculateExponentialMovingAverage(int days){
        string attributeName = "EMA-" + to_string(days);
        double yesterdaySMA = calculateSMA(days, days - 1);
        double average;
        for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
            if (i >= days - 1){
                average = (returnSet().getEntityInstances().at(i).getClose() * soothingFactor(days)) + (yesterdaySMA * (1 -
                                                                                                                     soothingFactor(days)));
                Pair pair = Pair(attributeName, "", average, 0, true, false);
                returnSet().getEntityInstances().at(i).addPair(pair);
            }
        }
    };

    void calculateMACD() {
        string name = "MACD";
        for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
            double macd = returnSet().getEntityInstances().at(i).getEma12() - returnSet().getEntityInstances().at(i).getEma26();
            if ( i < 25){

            } else {
                Pair pair = Pair(name, "", macd, 0, true, false);
                returnSet().getEntityInstances().at(i).addPair(pair);
            }
        }
    };

    double calculateSignal(int days){
        string name = "Signal";
        for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
            double signal = returnSet().getEntityInstances().at(i).getEma12() - returnSet().getEntityInstances().at(i).getEma26();
            if ( i < 33){

            } else {
                Pair pair = Pair(name, "", signal, 0, true, false);
                returnSet().getEntityInstances().at(i).addPair(pair);
            }
        }
        return 0.0;
    };

    double soothingFactor(int days){
        double daysToDouble = days;
        double sooth = 2.0;
        double soothingFactor = sooth / ( 1.0 + daysToDouble);
        return soothingFactor;
    };

    void print(vector<string> attributes){
        returnSet().printInCSV(attributes);
        cout << endl;
        for (int i = 0; i < attributes.size() - 1; i++){
            for (int k = 0; i < instanceCopy.getEntityInstances().size(); i++) {
                returnSet().getEntityInstances().at(i).printInCSV(attributes);
                cout << endl;
            }
        }
    };

    EntitySet &returnSet() { return instanceCopy; } ;

    double calculateSMA(int days, int index){
        double avg = 0.0;
        double daysToDouble = days;

        for (int i = index; i >= index - (days - 1); i--) {
            avg += returnSet().getEntityInstances().at(i).getClose();
        }

        return avg/daysToDouble;
    };

private:
    EntitySet instanceCopy;
};


#endif //PROJECT3_EQUITYSTATS_HPP

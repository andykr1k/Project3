//
// Created by Andrew Krikorian on 4/11/22.
//

#include "EquityStats.hpp"

double EquityStats::calculateExponentialMovingAverage(int days) {
    return 0;
}

double EquityStats::calculateMACD() {
    double macd = calculateExponentialMovingAverage(12) - calculateExponentialMovingAverage(26);
    return macd;
}

double EquityStats::calculateSignal(int days) {
    return calculateExponentialMovingAverage(days);
}

void EquityStats::print(vector<string> attributesToPrint){
/*    for (int i = 0; i < attributesToPrint.size(); i++){
        for (int k = 0; i < ; k++){
            if (attributesToPrint.at(i) == entityPairs.at(k).attributeName()){

            }
        }
    }*/
}

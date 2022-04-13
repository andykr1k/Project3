//
// Created by Andrew Krikorian on 4/11/22.
//

#include "EquityStats.hpp"

void EquityStats::calculateExponentialMovingAverage(int days) {
    if ( .size() < days){
        return;
    }
    calculateSMA(days);
    for (int i = 0; i < .size(); ++i) {

    }
    return 0;
}

double EquityStats::calculateSMA(int) {
    double avg = 0.0;

}

double EquityStats::calculateMACD() {
    double macd = calculateExponentialMovingAverage(12) - calculateExponentialMovingAverage(26);
    return macd;
}

double EquityStats::calculateSignal(int days) {
    return calculateExponentialMovingAverage(days);
}

void EquityStats::print(vector<string> attributesToPrint){
//    for (int i = 0; i < attributesToPrint.size(); i++){
//        for (int k = 0; i < ; k++){
//            if (attributesToPrint.at(i) == set.at(k).attributeName()){
//
//            }
//        }
//    }
}

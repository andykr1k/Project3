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

void EquityStats::print(vector<string> attributes){
    for (int i =0; i < attributes.size(); i++){

    }
}

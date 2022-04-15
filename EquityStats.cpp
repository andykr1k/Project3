//
// Created by Andrew Krikorian on 4/11/22.
//

#include "EquityStats.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void EquityStats::calculateExponentialMovingAverage(int days){
    string attributeName = "EMA-" + to_string(days);
    double average;
    for (int i = 0; i < instanceCopy.getEntityInstances().size(); i++) {
        if (i > days - 1){
            if ( days == 12){
                average = returnSet().getEntityInstances().at(i).getClose() * soothingFactor(days) + returnSet().getEntityInstances().at(i-1).getEma12() * (1.0 - soothingFactor(days));
            }
            if (days == 26){
                average = returnSet().getEntityInstances().at(i).getClose() * soothingFactor(days) + returnSet().getEntityInstances().at(i-1).getEma26() * (1.0 - soothingFactor(days));
            }
            Pair pair = Pair(attributeName, "", average, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
        if (i == days - 1){
            if ( days == 12){
                average = returnSet().getEntityInstances().at(i).getSMA12();
            }
            if (days == 26){
                average = returnSet().getEntityInstances().at(i).getSMA26();
            }
            Pair pair = Pair(attributeName, "", average, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
    }
};

void EquityStats::calculateMACD() {
    string name = "MACD";
    for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
        if ( i < 25){

        } else {
            double macd = returnSet().getEntityInstances().at(i).getEma12() - returnSet().getEntityInstances().at(i).getEma26();
            Pair pair = Pair(name, "", macd, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
    }
};

double EquityStats::firstSignal(int days){
    double first = 0.0;
    for (int j = 25; j <  25 + days; j++){
        first += returnSet().getEntityInstances().at(j).getMacd();
    }
    return first / days;
}

void EquityStats::calculateSignal(int days){
    string name = "Signal";
    double signal = 0.0;
    Pair pair = Pair(name, "", firstSignal(9), 0, true, false);
    returnSet().getEntityInstances().at(25 + days - 1).addPair(pair);
    for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
        if ( i > 33){
            signal = returnSet().getEntityInstances().at(i).getMacd() * soothingFactor(days) + returnSet().getEntityInstances().at(i-1).getSignal() * (1.0 -
                                                                                                                                                       soothingFactor(days));
            Pair pair = Pair(name, "", signal, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
        signal = 0.0;
    }
};

double EquityStats::soothingFactor(int days){
    double soothingFactor = 2.0 / (1.0 + days);
    return soothingFactor;
};

void EquityStats::printCSV(vector<string> attributes){
    returnSet().printInCSV(attributes);
    cout << endl;
    for (int i = 0; i < attributes.size() - 1; i++){
        for (int k = 0; i < instanceCopy.getEntityInstances().size(); i++) {
            returnSet().getEntityInstances().at(i).printInCSV(attributes);
            if ( i < 33) {
                std::cout << ",";
            }
            cout << endl;
        }
    }
};

void EquityStats::printJSON(int numSpaces){
    cout << "[" << endl;
    for (int i = 0; i < instanceCopy.getEntityInstances().size(); i++) {
        returnSet().getEntityInstances().at(i).printInJSON(numSpaces);
        if ( i < instanceCopy.getEntityInstances().size() - 1) {
            std::cout << "," << endl;
        }
    }
    cout << endl;
    cout << "]" << endl;
};


void EquityStats::calculateSMA12() {
    string name = "SMA-12";
    double avg = 0.0;

    for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
        avg += returnSet().getEntityInstances().at(i).getClose();
        double sma = (avg / (i + 1));
        if (i >= 11){
            Pair pair = Pair(name, "", sma, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
    }
};

void EquityStats::calculateSMA26() {
    string name = "SMA-26";
    double avg = 0.0;

    for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
        avg += returnSet().getEntityInstances().at(i).getClose();
        double sma = (avg / (i + 1));
        if (i >= 25){
            Pair pair = Pair(name, "", sma, 0, true, false);
            returnSet().getEntityInstances().at(i).addPair(pair);
        }
    }
};
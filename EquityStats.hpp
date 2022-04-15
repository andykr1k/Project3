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
        double average;
        for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
            if (i > days - 1){
                if ( days == 12){
                    average = (returnSet().getEntityInstances().at(i).getClose() * soothingFactor(i - 1)) + (returnSet().getEntityInstances().at(i-1).getEma12() * (1.0 - soothingFactor(i - 1)));
                }
                if (days == 26){
                    average = (returnSet().getEntityInstances().at(i).getClose() * soothingFactor(i - 1)) + (returnSet().getEntityInstances().at(i-1).getEma26() * (1.0 - soothingFactor(i - 1)));
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

    void calculateMACD() {
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

    double calculateSignal(int days){
        string name = "Signal";
        double signal = 0.0;
        double avg = 0.0;
        for (int i = 0; i < returnSet().getEntityInstances().size(); i++) {
            if ( i < 33){

            } else {
                for (int j = 0; j < days; j++){
                    avg += returnSet().getEntityInstances().at(i - j).getMacd();
                }
                signal = avg / days;
                Pair pair = Pair(name, "", signal, 0, true, false);
                avg = 0.0;
                returnSet().getEntityInstances().at(i).addPair(pair);
            }
        }
        return 0.0;
    };

    double soothingFactor(int days){
        double soothingFactor = 2.0 / (1.0 + days);
        return soothingFactor;
    };

    void printCSV(vector<string> attributes){
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

    void printJSON(int numSpaces){
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

    EntitySet &returnSet() { return instanceCopy; } ;

    void calculateSMA12() {
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
    void calculateSMA26() {
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

private:
    EntitySet instanceCopy;
};


#endif //PROJECT3_EQUITYSTATS_HPP

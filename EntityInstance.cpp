//
// Created by Andrew Krikorian on 4/7/22.
//

#include "EntityInstance.hpp"

void EntityInstance::printInJSON(int numSpaces) {
    std::cout << std::setw(numSpaces) <<  "{" << std::endl;
    for (int i = 0; i < entityPairs.size(); i++){
        Pair pair = entityPairs.at(i);
        pair.printInJSON(5);
        if (i < entityPairs.size() - 1) {
            std::cout << "," << std::endl;
        }
    }
    std::cout << std::endl << std::setw(numSpaces) << "}";
}

void EntityInstance::printInCSV(std::vector<std::string>keyValues) {
    for (int i = 0; i < keyValues.size(); i++) {
        for (int j = 0; j < entityPairs.size(); j++) {
            if (keyValues.at(i) == entityPairs.at(j).attributeName()){
                if (entityPairs.at(j).stringValue().empty()){
                    if (entityPairs.at(j).isInt()){
                        entityPairs.at(j).printInCSV(false);
                    } else {
                        entityPairs.at(j).printInCSV(false);
                    }
                } else {
                    entityPairs.at(j).printInCSV(true);
                }
            } else {
                if ( j + 1 == entityPairs.size()) {
                    std::cout << "";
                    if ( i < keyValues.size() - 1){
                        std::cout << ",";
                    }
                }
            }
        }
    }
}
double EntityInstance::getClose() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Close"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getOpen() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Open"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getHigh() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "High"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getLow() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Low"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

int EntityInstance::getVolume() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Volume"){
            return entityPairs.at(i).getIntValue();
        }
    }
}

int EntityInstance::getDividends() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Dividends"){
            return entityPairs.at(i).getIntValue();
        }
    }
}

int EntityInstance::getStocksplits() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Stock Splits"){
            return entityPairs.at(i).getIntValue();
        }
    }
}

std::string EntityInstance::getDate() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Date"){
            return entityPairs.at(i).stringValue();
        }
    }
}

std::string EntityInstance::getTimestamp() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "Timestamp"){
            return entityPairs.at(i).stringValue();
        }
    }
}

double EntityInstance::getEma12() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "EMA-12"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getEma26() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "EMA-26"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getMacd() {
    for (int i = 0; i < entityPairs.size(); i++){
        if (entityPairs.at(i).attributeName() == "MACD"){
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

double EntityInstance::getSignal() {
    for (int i = 0; i < entityPairs.size(); i++) {
        if (entityPairs.at(i).attributeName() == "Signal") {
            return entityPairs.at(i).getDoubleValue();
        }
    }
}

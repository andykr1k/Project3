//
// Created by Andrew Krikorian on 4/7/22.
//

#include "EntityInstance.hpp"

void EntityInstance::print() {

}

void EntityInstance::printInJSON(int numSpaces) {
    std::cout << "{";
    for (int i = 0; i < entityPairs.size(); i++){

        Pair pair = entityPairs.at(i);
        pair.printInJSON(5);
        if (i < entityPairs.size() - 1) {
            std::cout << "," << std::endl;
        }
    }
    std::cout << "}";
}

void EntityInstance::printInCSV() {
    for (int i = 0; i < entityPairs.size(); i++){

        Pair pair = entityPairs.at(i);
        pair.printInCSV(true);
    }
    for (int i = 0; i < entityPairs.size(); i++){

        Pair pair = entityPairs.at(i);
        pair.printInCSV(false);
    }
}

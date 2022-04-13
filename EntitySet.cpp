//
// Created by Andrew Krikorian on 4/7/22.
//

#include "EntitySet.hpp"

void EntitySet::print() {

}

void EntitySet::printInJSON(int numSpaces) {
    std::cout << "[" << std::endl ;
    for (int i = 0; i < instances.size(); i++){

        EntityInstance instance = instances.at(i);
        instance.printInJSON(5);
        if (i < instances.size() - 1) {
            std::cout << "," << std::endl;
        }
    }
    std::cout << std::endl << "]" << std::endl;
}

void EntitySet::printInCSV(std::vector<std::string> keyValues) {
    for (int i = 0; i < keyValues.size(); i++){
        std::cout << keyValues.at(i);
        if ( i < keyValues.size() - 1) {
            std::cout << ",";
        }
    }
}

//
// Created by Andrew Krikorian on 4/7/22.
//

#ifndef PROJECT3_ENTITYSET_HPP
#define PROJECT3_ENTITYSET_HPP
#include <string>
#include <vector>
#include "EntityInstance.hpp"

class EntitySet {
public:
    EntitySet();

    void addEntity(EntityInstance &);
    void print();    // prints all instances of this Entity.
    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
    // more member functions here.
    void printInJSON(int numSpaces);
    void printInCSV();

private:
    std::vector<EntityInstance> instances;
};


#endif //PROJECT3_ENTITYSET_HPP

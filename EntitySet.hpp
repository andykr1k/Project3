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
    EntitySet(): instances(){};

    void addEntity(EntityInstance &instance) { instances.push_back(instance); };
    void changeInstance(int index, EntityInstance &instance) { instances.at(index) = instance; };
    std::vector<EntityInstance> &getEntityInstances() { return instances; };
    void printInJSON(int numSpaces);
    void printInCSV(std::vector<std::string>keyValues);

private:
    std::vector<EntityInstance> instances;
};


#endif //PROJECT3_ENTITYSET_HPP

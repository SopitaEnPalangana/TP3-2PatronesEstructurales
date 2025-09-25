#include <iostream>
#include <memory>
#include "hotel.hpp"

using namespace std;

string Hotel::getDescription() const {
    return description;
}

string Hotel::getType() const {
    return type;
}

float Hotel::getBudget() const {
    return price;
}

void Hotel::setDescription(const string desc){
    description = desc;
}

void Hotel::setType(const string t){
    type = t;
}

void Hotel::setBudget(float budget){
    price = budget;
}
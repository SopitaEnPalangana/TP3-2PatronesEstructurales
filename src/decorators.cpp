#include <iostream>
#include <memory>
#include "decorators.hpp"

using namespace std;

//Abstract Decorator
string RentableDecorator::getDescription() const {
    return housing->getDescription();
}
string RentableDecorator::getType() const {
    return housing->getType();
}
float RentableDecorator::getBudget() const {
    return housing->getBudget();
}
void RentableDecorator::setDescription(const string desc){
    housing->setDescription(desc);
}
void RentableDecorator::setType(const string t){
    housing->setType(t);
}
void RentableDecorator::setBudget(const float budget){
    housing->setBudget(budget);
}

//Beachline
string Beachline::getDescription() const {
    return housing->getDescription() + " on Beachline";
}
    //RentableDecorator::getDescription() seria mejor encapsulado, pero no lo termino de entender
string Beachline::getType() const {
    return housing->getType() + " (Beachline)";
}
float Beachline::getBudget() const {
    return housing->getBudget() + extraprice;
}

//Wholepension
string WholePension::getDescription() const {
    return housing->getDescription() + ", wholepension provided";
}
string WholePension::getType() const {
    return housing->getType() + " (WholePension)";
}
float WholePension::getBudget() const {
    return housing->getBudget() + extraprice;
}

//VIPDiscount
string VIPDiscount::getDescription() const {
    return housing->getDescription() + ". Descuento aplicado: 15%";
}
string VIPDiscount::getType() const {
    return housing->getType() + " (VIP Discount)";
}
float VIPDiscount::getBudget() const {
    return housing->getBudget() * 0.85;
}
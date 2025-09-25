#pragma once
#include <iostream>
using namespace std;

class Rentable {
    public:
        virtual ~Rentable() = default;

        virtual string getDescription() const = 0;
        virtual string getType() const = 0;
        virtual float getBudget() const = 0;

        virtual void setDescription(const string description) = 0;
        virtual void setType(const string type) = 0;
        virtual void setBudget(const float price) = 0;
};
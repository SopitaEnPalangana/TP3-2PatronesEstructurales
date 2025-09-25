#pragma once
#include <iostream>
#include "rentable.hpp"
using namespace std;

class Hotel : public Rentable{
    private:
        string type = "Hotel";
        string description;
        float price;
    public:
        Hotel() = default;

        string getDescription() const override;
        string getType() const override;
        float getBudget() const override;

        void setDescription(const string desc) override;
        void setType(const string type) override;
        void setBudget(const float price) override;
};
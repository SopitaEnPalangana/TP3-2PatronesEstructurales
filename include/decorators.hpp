#pragma once
#include <iostream>
#include <memory>
#include "rentable.hpp"

using namespace std;

class RentableDecorator : public Rentable{
    protected:
        unique_ptr<Rentable> housing;
    public:
        RentableDecorator(unique_ptr<Rentable> h) : housing(move(h)){}
        virtual ~RentableDecorator() = default;

        string getDescription() const override;
        string getType() const override;
        float getBudget() const override;

        void setDescription(const string desc) override;
        void setType(const string type) override;
        void setBudget(const float price) override;
};

class Beachline : public RentableDecorator{
        float extraprice = 10;
    public:
        Beachline(unique_ptr<Rentable> h) : RentableDecorator(move(h)){};
        string getDescription() const override;
        string getType() const override;
        float getBudget() const override;
};

class WholePension : public RentableDecorator{
        float extraprice = 15;
    public:
        WholePension(unique_ptr<Rentable> h) : RentableDecorator(move(h)){};
        string getDescription() const override;
        string getType() const override;
        float getBudget() const override;
};

class VIPDiscount : public RentableDecorator{
        float extraprice = 0;
    public: 
        VIPDiscount(unique_ptr<Rentable> h) : RentableDecorator(move(h)){};
        string getDescription() const override;
        string getType() const override;
        float getBudget() const override;
};
#include "fruit.h"

Fruit::Fruit()
{
    weight = 0;
    loss = 0;
}

Fruit::Fruit(int w, int l)
{
    weight = w;
    loss = l;
}

int& Fruit::checkWeight()
{
    return weight;
}

int Fruit::checkLoss()
{
    return loss;
}

void Fruit::upDate()
{
    this->DatePassed++;
}

void Fruit::Dryed()
{
    this->Dry = true;
}

bool Fruit::isDryed()
{
    return Dry;
}

void Apple::losewater()
{
    if (this->checkWeight() > 30) {
        this->checkWeight() -= 4;
    }
    else
    {
        this->Dryed();
    }
}

void Orange::losewater()
{
    if (this->checkWeight() > 18) {
        this->checkWeight() -= 3;
    }
    else
    {
        this->Dryed();
    }
}

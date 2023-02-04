#include "Hero.h"

Hero::Hero(int vie, int defense, int degats, std::string arme, std::string nom): Personnage(vie, defense, degats, arme, nom)
{
    this->setTourDeRecharge(0);
}

int Hero::getTourDeRecharge() const
{
    return this->toursDeRecharge;
}

void Hero::DecrementTourDeRecharge()
{
    if (this->getTourDeRecharge() > 0)
    {
        this->toursDeRecharge--;
    }
}

void Hero::setTourDeRecharge(int toursDeRecharge)
{
    this->toursDeRecharge = toursDeRecharge;
}
